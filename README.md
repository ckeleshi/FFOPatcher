﻿# 介绍
此插件支持修改QQ自由幻想帧数，获得流畅的游戏体验和~~伤害提升并非本意~~。</br>
目前插件支持任意图形方式启动游戏。强烈推荐使用OpenGL模式。</br>
**本人从未在中国国内任何公开平台发布此插件，请自行承担使用本插件的风险！**</br>

# 安装方法
使用方法:将附件解压到qqffo.exe同一目录下。</br>
通过修改ffopatcher.ini中FrameInterval数值。一般地，FrameInterval越小，游戏帧数越高。</br>

# FrameInterval是什么？
单位毫秒，控制游戏循环处理一次逻辑的耗时。</br>

# 底层逻辑
**游戏在同一个循环内处理渲染和逻辑，意味着两者用同一个线程处理**</br>
记当次循环的耗时为C毫秒</br>
A: 如果C小于FrameInterval，则会Sleep(FrameInterval-C)然后进行下一次循环。</br>
B: 如果C大于等于FrameInterval，则会Sleep(1)然后进行下一次循环，此时FrameInterval等于无效。</br>
于是，当电脑性能足够时，可以通过降低FrameInterval来提升渲染画面的次数，即帧数。</br>
但是，逻辑处理次数也变高了，产生了各种无法预知的效果。</br></br>
当FrameInterval大于0时，大约能获得1000/(FrameInterval+1)的帧数，补丁默认值为15，约62.5帧。</br>
个人认为调到6，获得140帧就很不错了。</br></br>
基于上面逻辑，解释以下几个问题：</br>

# FAQ
### 为什么我修改FrameInterval无效？
当C已经长于FrameInterval时，降低FrameInterval自然是没有作用的。

### 为什么我的帧数不能超过显示器刷新率？
请关闭垂直同步。

### 为什么我多开之后帧数变低了/提升帧数之后干啥都卡？
由于上面说的同一线程设计，帧数变高，显卡和CPU占用会一起变高。需要自行确定是CPU还是显卡瓶颈。如果是CPU瓶颈，尝试手动将游戏进程分散到其他CPU核心。</br>
Windows7的CPU调度貌似不如Windows10智能，更加需要人工干预。

### 为什么我的帧数波动很大？
上面所说的AB条件交替发生

# FrameInterval设为0
补丁现已支持将FrameInterval设为0，由于系统对于Sleep(0)的特殊逻辑，游戏将会吃满性能获得最高的帧数。**没什么用。**</br>
在Ryzen 7 5700X + RTX4070的机器上，得到了1300+的帧数，此时已经占满了CPU单核性能，显卡占用不到20%。
