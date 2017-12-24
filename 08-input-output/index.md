# 输入输出

### 标准文件

C 语言把所有的设备都当作文件。所以设备（比如显示器）被处理的方式与文件相同。以下三个文件会在程序执行时自动打开，以便访问键盘和屏幕。


|标准文件|文件指针|设备|
|---|----|----|
|标准输入|stdin|键盘|
|标准输出|stdout|屏幕|
|标准错误|stderr|您的屏幕|

文件指针是访问文件的方式

```c
void test()
{
    float f;
    printf("Enter a number: ");
    // %f 匹配浮点型数据
    scanf("%f",&f);
    printf("Value = %f\n", f);
}
```

#### getchar() putchar()

`int getchar(void)`函数从屏幕上获取一个可用字符,并把它返回一个整.这个函数在同一时间只会读取一个单一的字符.

`int putchar(int c)` 函数把字符输出到屏幕上，并返回相同的字符。这个函数在同一个时间内只会输出一个单一的字符。
#### gets() puts()

`char * gets(char *buffer)`函数从`stdin`读取一行到`s`所指向的缓冲区,直到一个终止符或EOF.

`gets`函数功能：从键盘上输入字符，直至接受到换行符或EOF时停止，并将读取的结果存放在`buffer`指针所指向的字符数组中。
读取的换行符被转换为`null`值，做为字符数组的最后一个字符，来结束字符串.
gets函数由于没有指定输入字符大小，所以会无限读取，一旦输入的字符大于数组长度，就会发生内存越界，从而造成程序崩溃或其他数据的错误.

`fgets`

fgets函数原型：`char *fgets(char *s, int n, FILE *stream)`;//我们平时可以这么使用：`fgets(str, sizeof(str), stdin)`;

其中str为数组首地址，sizeof(str)为数组大小，stdin表示我们从键盘输入数据。
fgets函数功能：从文件指针stream中读取字符，存到以s为起始地址的空间里，直到读完N-1个字符，或者读完一行。

注意: 调用`fgets`函数时，最多只能读入n-1个字符。读入结束后，系统将自动在最后加'\0'，并以str作为函数值返回。

`int puts(const char *s)`函数把字符串`s`和一个尾随的换行符写到`stdout`

#### scanf() printf()
`int scanf(const char *format, ...)`函数从标准输入流`stdin`读取输入,并根据提供的`format`来浏览输入.
`int printf(const char *format, ...)`函数把输出写入到标准输出流 `stdout` ，并根据提供的格式产生输出。

`format` 可以是一个简单的常量字符串，但是您可以分别指定 %s、%d、%c、%f 等来输出或读取字符串、整数、字符或浮点数。还有许多其他可用的格式选项，可以根据需要使用.

