## 适用于51单片机的课后源码

### 本源码需要配合Clion使用,keil等代码编辑器可能存在语法错误 

代码中注释了部分功能,可以自行尝试


### 环境配置

1. 下载安装Clion

2. 安装 PlatformIO 插件

3. 在clion中新建一个项目，根据提示配置环境

4. 编写一个简单的代码测试环境是否配置成功

```c
#include <mcs51/8052.h>

void main()

{
    while(1)
    {
        P1 = 0xfe;
    }
}
```

### 环境配置文件(以stc89c52rc为例)

```json
[env:STC89C52RC]
platform = intel_mcs51
board = STC89C52RC

lib_deps = C:\Users\Night\.platformio\packages\toolchain-sdcc\include 
// 这里配置环境安装路径
```

### 后记

`单片机学习之路漫长，需要坚持以往的努力`
