## 文件结构拆分

```
flight_management/
|
|_inc/
    |_ common.h   # 通用头文件
    |_ user.h     # 用户头文件(结构体相关函数)
    |_ admin.h    # 管理员(结构体相关函数)
    |_ flight.h   # 航班结构体相关函数
|_src/
    |_ user.c     # 用户头文件(结构体相关函数)
    |_ admin.c    # 管理员(结构体相关函数)
    |_ flight.c   # 航班结构体相关函数
```