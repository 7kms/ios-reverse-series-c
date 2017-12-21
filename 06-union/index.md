# 共用体
> 共用体是一种特殊的数据类型,允许在相同的内存位置存储不同的数据类型.你可以定义一个带有多个成员的共用体,但是任何时候只有一个成员有值

### 定义共用体


必须使用`union`语句,方式与定义结构体相似,`union`语句定义了一个新的数据类型,带有多个成员.
```c
    union [union tag]
    {
        member definition;
        member definition;
        ...
        member definition;
    }[one or more union variables];
```
`union tag`是可选的,每个`member definition`是标准的变量定义.比如int i; 或者 float f;

共用体占用的内存应足够存储共用体中最大的成员

例如:

```c

union Data
{
   int i;
   float f;
   char  str[20];
} data;

```
`Data` 类型的变量可以存储一个整数、一个浮点数，或者一个字符串.


