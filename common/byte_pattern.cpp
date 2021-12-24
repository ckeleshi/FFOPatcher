//Core code from Hooking.Patterns
//https://github.com/ThirteenAG/Hooking.Patterns

#include "byte_pattern.h"

using namespace std;

memory_pointer byte_pattern::get(size_t index) const
{
    if (this->_results.size() < (index + 1))
    {
        return nullptr;
    }
    else
    {
        return this->_results.at(index);
    }
}

std::vector<memory_pointer> byte_pattern::get() const
{
    return _results;
}

memory_pointer byte_pattern::get_first() const
{
    return this->get(0);
}

byte_pattern::byte_pattern()
{
    reset_module();
}

byte_pattern& byte_pattern::set_pattern(const char* pattern_literal)
{
    this->_pattern.clear();
    this->_mask.clear();
    this->transform_pattern(pattern_literal);
    this->bm_preprocess();

    return *this;
}

byte_pattern& byte_pattern::set_pattern(const void* pattern_binary, size_t size)
{
    this->_pattern.clear();
    this->_mask.clear();
    this->_pattern.assign(reinterpret_cast<const uint8_t*>(pattern_binary), reinterpret_cast<const uint8_t*>(pattern_binary) + size);
    this->_mask.resize(size, 0xFF);
    this->bm_preprocess();

    return *this;
}

byte_pattern& byte_pattern::reset_module()
{
    static HMODULE default_module = GetModuleHandleA(nullptr);

    return set_module(default_module);
}

byte_pattern& byte_pattern::set_module(memory_pointer module)
{
    this->get_module_range(module);

    return *this;
}

byte_pattern& byte_pattern::set_range(memory_pointer beg, memory_pointer end)
{
    this->_range.first = beg;
    this->_range.second = end;

    return *this;
}

byte_pattern& byte_pattern::search()
{
    this->bm_search();

    return *this;
}

byte_pattern& byte_pattern::find_pattern(const char* pattern_literal)
{
    this->set_pattern(pattern_literal).search();

    return *this;
}

byte_pattern& byte_pattern::find_pattern(const void* pattern_binary, size_t size)
{
    this->set_pattern(pattern_binary, size).search();

    return *this;
}

std::vector<std::string> byte_pattern::split_pattern(const char* literal)
{
    std::vector<std::string> result;
    std::string sub_pattern;

    while (true)
    {
        if (*literal == ' ' || *literal == 0)
        {
            if (!sub_pattern.empty())
            {
                result.push_back(sub_pattern);
            }

            sub_pattern.clear();
        }
        else
        {
            sub_pattern += *literal;
        }

        if (*literal == 0)
        {
            break;
        }

        ++literal;
    }

    return result;
}

pair<uint8_t, uint8_t> byte_pattern::parse_sub_pattern(std::string_view sub)
{
    auto digit_to_value = [](char character) {
        if ('0' <= character && character <= '9') return (character - '0');
        else if ('A' <= character && character <= 'F') return (character - 'A' + 10);
        else if ('a' <= character && character <= 'f') return (character - 'a' + 10);
        throw invalid_argument("Could not parse pattern."); };

    pair<uint8_t, uint8_t> result;

    if (sub.size() == 1)
    {
        if (sub[0] == '?')
        {
            result.first = 0;
            result.second = 0;
        }
        else
        {
            result.first = digit_to_value(sub[0]);
            result.second = 0xFF;
        }
    }
    else if (sub.size() == 2)
    {
        if (sub[0] == '?' && sub[1] == '?')
        {
            result.first = 0;
            result.second = 0;
        }
        else if (sub[0] == '?')
        {
            result.first = digit_to_value(sub[1]);
            result.second = 0xF;
        }
        else if (sub[1] == '?')
        {
            result.first = (digit_to_value(sub[0]) << 4);
            result.second = 0xF0;
        }
        else
        {
            result.first = ((digit_to_value(sub[0]) << 4) | digit_to_value(sub[1]));
            result.second = 0xFF;
        }
    }
    else
    {
        throw invalid_argument("Could not parse pattern.");
    }

    return result;
}

void byte_pattern::transform_pattern(const char* literal)
{
    vector<string> sub_patterns;

    if (literal == nullptr)
    {
        return;
    }

    sub_patterns = split_pattern(literal);

    for (auto sub : sub_patterns)
    {
        auto pat = parse_sub_pattern(sub);

        this->_pattern.push_back(pat.first);
        this->_mask.push_back(pat.second);
    }
}

void byte_pattern::get_module_range(memory_pointer module)
{
    //Range of whole image.
    PIMAGE_DOS_HEADER dosHeader = module.p<IMAGE_DOS_HEADER>();
    PIMAGE_NT_HEADERS ntHeader = module.p<IMAGE_NT_HEADERS>(dosHeader->e_lfanew);

    _range.first = module;
    _range.second = module.i(ntHeader->OptionalHeader.SizeOfImage);
}

void byte_pattern::clear()
{
    this->_pattern.clear();
    this->_mask.clear();
    this->_results.clear();
}

size_t byte_pattern::count() const
{
    return this->_results.size();
}

bool byte_pattern::has_size(size_t expected) const
{
    return (this->_results.size() == expected);
}

bool byte_pattern::empty() const
{
    return this->_results.empty();
}

void byte_pattern::bm_preprocess()
{
    const uint8_t* pbytes = this->_pattern.data();
    const uint8_t* pmask = this->_mask.data();
    size_t pattern_len = this->_pattern.size();

    for (uint32_t bc = 0; bc < 256; ++bc)
    {
        std::ptrdiff_t index;

        for (index = pattern_len - 1; index >= 0; --index)
        {
            if ((pbytes[index] & pmask[index]) == (bc & pmask[index]))
            {
                break;
            }
        }

        this->_bmbc[bc] = index;
    }
}

void byte_pattern::bm_search()
{
    const uint8_t* pbytes = this->_pattern.data();
    const uint8_t* pmask = this->_mask.data();
    size_t pattern_len = this->_pattern.size();

    this->_results.clear();

    if (pattern_len == 0)
    {
        return;
    }

    uint8_t* range_begin = reinterpret_cast<uint8_t*>(this->_range.first);
    uint8_t* range_end = reinterpret_cast<uint8_t*>(this->_range.second - pattern_len);

    ptrdiff_t index;

    __try
    {
        while (range_begin <= range_end)
        {
            for (index = pattern_len - 1; index >= 0; --index)
            {
                if ((pbytes[index] & pmask[index]) != (range_begin[index] & pmask[index]))
                {
                    break;
                }
            }

            if (index == -1)
            {
                this->_results.emplace_back(range_begin);
                range_begin += pattern_len;
            }
            else
            {
                range_begin += max(index - this->_bmbc[range_begin[index]], 1);
            }
        }
    }
    __except ((GetExceptionCode() == EXCEPTION_ACCESS_VIOLATION) ? EXCEPTION_EXECUTE_HANDLER : EXCEPTION_CONTINUE_SEARCH)
    {

    }
}
