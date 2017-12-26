# 可变参数
有时候,需求希望函数带有可变数量的参数,而不是预定义数量的参数.c语言为这种情况提供了一个解决方案,它允许定义一个函数,能根据具体的需求接受可变数量的参数

```c
int func(int,...)
{
    ...
}
int main()
{
    func(2,1,2);
    func(3,1,2,3);
}
```
函数`func()`最后一个参数写成省略号(...),省略号之前的那个参数是`int`,代表了要传递的可变参数的总数.为了使用这个功能,需要引入`stdarg.h`头文件,该文件提供了实现可变参数功能的函数和宏.

1. 定义一个函数,最后一个参数为省略号,省略号前面可以设置自定义参数.
2. 在函数定义中创建一个`va_list`类型变量,该类型是在`stdarg.h`头文件中定义的.
3. 使用`int`参数和`va_start`宏来初始化`va_list`变量为一个参数列表.宏`va_start`是在`stdarg.h`头文件中定义的.
4. 使用`va_arg`宏和`va_list`变量来访问参数列表中的每个项.
5. 使用宏`va_end`来清理赋予`va_list`变量的内存.

现在我们按照上面的步骤,来编写一个带有可变参数的函数
返回可变参数的平均值.

```c
double average(int num, ...)
{
    va_list valist;
    double sum = 0.0;
    int i;
    va_start(valist,num);//为num个参数初始化valist

    //访问所有赋给valist的参数
    for(i=0; i < num; i++){
        sum += va_arg(valist,int);
    }
    //清理为valist保留的内存
    va_end(valist);
    return sum/num;
}

```


可变参数原理

以32位机为例:

 1. 函数参数的传递存储在栈中,从右至左压入栈中,压栈过程为递减。
 2. 参数的传递以4字节对齐,float/double这里不讨论

```c

void debug_arg(unsigned int num, ...)
{
    unsigned int i = 0;
    unsigned int *addr = #
    for (i = 0; i <= num; i++) 
    {
        /* *(addr + i) 从左往右依次取出传递进来的参数,类似于出栈过程 */
        printf("i=%d,value=%d\r\n", i, *(addr + i));
    }
}

```