# 通用的 C 语言多文件项目目录结构

```plaintext
project/                       # 项目根目录
├── build/                     # 编译产物目录（自动生成）
├── doc/                       # 文档目录
│   ├── api/                   # API接口文档
│   ├── design/                # 设计文档（架构、模块设计等）
│   └── user_manual/           # 用户手册（如有）
├── inc/                       # 公共头文件目录（对外暴露的接口）
│    ├── module_a.h
│    └── module_b.h
├── res/                       # 资源文件目录（新增）
│   ├── config/                # 配置文件（如.ini/.json/.xml）
│   │   └── app_config.json
│   ├── data/                  # 静态数据文件（如模板、字典、初始数据）
│   │   └── default_data.csv
│   ├── log/                   # 日志输出目录（可选，也可运行时创建）
│   │   └── app.log
│   └── ui/                    # GUI相关资源（如图片、字体、布局文件）
│       ├── icon.png
│       └── font.ttf
├── src/                       # 源代码目录（核心实现）
│   ├── module_a/              # 模块A的源码（按功能/模块拆分）
│   │   ├── module_a.c
│   │   └── private_a.h        # 模块A的私有头文件（仅内部使用）
│   ├── module_b/              # 模块B的源码
│   │   ├── module_b.c
│   │   └── private_b.h
│   └── main.c                 # 程序入口文件（main函数）
├── test/                      # 测试代码目录
│   ├── test_module_a.c
│   └── test_module_b.c
├── third_party/               # 第三方依赖库（如libcurl、json-c等）
│   ├── include/               # 第三方库的头文件
│   └── lib/                   # 第三方库的编译产物（.a/.so）
├── Makefile                   # 编译脚本（核心）
├── CMakeLists.txt             # 可选：跨平台编译配置（替代Makefile）
└── README.md                  # 项目说明（功能、编译、使用方式）
```


目前我们要编译这个项目编译语句
```shell
# 访问当前项目的根目录
cd ./project
# -I ./inc 指定头文件的路径
gcc ./src/*.c -o  ./bulid/demo  -I ./inc
```