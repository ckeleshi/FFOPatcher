# FFOPatcher
对QQ自由幻想的一些修改

0. 警告！！！风险自担！</br>
1. 使用方法: 将附件解压到qqffo.exe同一目录下 </br>
2. 修改游戏帧数，目前只支持D3D9/OpenGL模式启动的游戏。通过修改ffopatcher.ini调整帧间隔，默认值为15毫秒(大约60fps)，目前限定在[1,29]毫秒。帧间隔过低会影响游戏稳定性，而且动画效果过于鬼畜。 </br>
3. 打开LargeAddressAware可以大大减少蓝地板/满屏鼠标指针及类似的贴图问题。此开关无法在程序启动后改变，需要先用附件中的large_address.bat开启。</br>
4. 每次游戏更新后记得重新运行一次large_address.bat </br>
