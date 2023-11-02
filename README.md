# System_Run_LED 软件包

## 1 介绍

System_Run_LED 软件包提供了一个系统运行指示灯的控制线程。

### 1.1 目录结构

| 名称 | 说明 |
| ---- | ---- |
| System_Run_LED.c | System_Run_LED 源代码 |
| SConscript | RT-Thread 默认的构建脚本 |
| README.md | 软件包使用说明 |

### 1.2 许可证

System_Run_LED 软件包遵循  Apache-2.0 许可，详见 LICENSE 文件。

### 1.3 依赖

依赖 `RT-Thread PIN` 设备驱动框架。

## 2 获取软件包

使用 `System_Run_LED` 软件包需要在 RT-Thread 的包管理器中选择它，具体路径如下：

```
RT-Thread online packages
    peripheral libraries and drivers  --->
        [*] System_Run_LED: System Run LED Control --->
```

每个功能的配置说明如下：

- `System_Run_LED: System Run LED Control`：选择使用 `System_Run_LED` 软件包；
- `Version`：配置软件包版本，默认最新版本。

然后让 RT-Thread 的包管理器自动更新，或者使用 `pkgs --update` 命令更新包到 BSP 中。

## 3 使用 System_Run_LED 软件包

- 按照前文介绍，获取 `System_Run_LED` 软件包后，编译工程，下载固件到硬件，就可以看到硬件LED等闪烁了。

## 4 注意事项

软件包默认配置详细信息如下，可以根据自己的项目需求，在 `ENV` 或 `RT-Thread studio` 中，灵活修改软件包配置：
- `System_Run_LED_THREAD_PRIORITY 20` : SYS Run LED 线程的优先级 20 。
- `System_Run_LED_THREAD_STACK_SIZE 250` : SYS Run LED 线程栈大小 250，单位是字节。
- `System_Run_LED_THREAD_TIMESLICE 1`: SYS Run LED 线程的时间片大小 1。
- `System_Run_LED_Pin_Name "PA.00"` ：SYS Run LED 的物理 Pin 名称，格式为 `PA.00`。
- `System_Run_LED_Flash_Time 500` ：SYS Run LED 的闪烁时间间隔，单位为500毫秒（ms）。

## 5 联系方式

* 维护：[WennianYan](https://github.com/WennianYan)
* 主页：https://github.com/WennianYan/System_Run_LED
