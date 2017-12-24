# 文件读写
一个文件，无论它是文本文件还是二进制文件，都是代表了一系列的字节.C 语言不仅提供了访问顶层的函数，也提供了底层（OS）调用来处理存储设备上的文件

### 打开文件
```c
    FILE *fopen (const char *filename,const char *mode);
```
在这里`filename`是字符串,用来命名文件,访问`mode`的值可以是下列值的一个:
|模式|描述|
|---|---|
|r|打开一个已有的文本文件,允许读|
|w|打开一个文本文件，允许写入文件。如果文件不存在，则会创建一个新文件。在这里，您的程序会从文件的开头写入内容。|
|a|打开一个文本文件，以追加模式写入文件。如果文件不存在，则会创建一个新文件。在这里，您的程序会在已有的文件内容中追加内容。|
|r+|打开一个文本文件，允许读写文件。|
|w+|打开一个文本文件，允许读写文件。如果文件已存在，则文件会被截断为零长度，如果文件不存在，则会创建一个新文件。|
|a+|打开一个文本文件，允许读写文件。如果文件不存在，则会创建一个新文件。读取会从文件的开头开始，写入则只能是追加模式。|

### 关闭文件
```c
int fclose (FILE *fp)
```
如果成功关闭文件，`fclose()` 函数返回零，如果关闭文件时发生错误，函数返回 EOF。这个函数实际上，会清空缓冲区中的数据，关闭文件，并释放用于该文件的所有内存。EOF 是一个定义在头文件 `stdio.h` 中的常量。

### 写入文件
```c
int fputc(int c,FILE *fp);
```
函数 `fputc()` 把参数 c 的字符值写入到 fp 所指向的输出流中。如果写入成功，它会返回写入的字符，如果发生错误，则会返回 EOF。您可以使用下面的函数来把一个以 `null` 结尾的字符串写入到流中
```c
int fputs( const char *s, FILE *fp );
```
函数 `fputs()` 把字符串 s 写入到 fp 所指向的输出流中。如果写入成功，它会返回一个非负值，如果发生错误，则会返回 EOF。您也可以使用 `int fprintf(FILE *fp,const char *format, ...)` 函数来写把一个字符串写入到文件中。尝试下面的实例：
```c
#include <stdio.h>
 
int main()
{
   FILE *fp = NULL;
 
   fp = fopen("/tmp/test.txt", "w+");
   fprintf(fp, "This is testing for fprintf...\n");
   fputs("This is testing for fputs...\n", fp);
   fclose(fp);
}

```


### 读取文件
```c
int fgetc(FILE *fp);
```
`fgetc()` 函数从 fp 所指向的输入文件中读取一个字符。返回值是读取的字符，如果发生错误则返回 EOF。下面的函数允许您从流中读取一个字符串：
```c
char *fgets(char *buf,int n, FILE *fp);
```
函数`fgets`从 fp 所指向的输入流中读取 `n - 1` 个字符。它会把读取的字符串复制到缓冲区 buf，并在最后追加一个 null 字符来终止字符串。如果这个函数在读取最后一个字符之前就遇到一个换行符 '\n' 或文件的末尾 EOF，则只会返回读取到的字符，包括换行符。

也可以使用 `int fscanf(FILE *fp, const char *format, ...)` 函数来从文件中读取字符串，但是在遇到第一个空格字符时，它会停止读取
```c
#include <stdio.h>
int main()
{
   FILE *fp = NULL;
   char buff[255];
 
   fp = fopen("/tmp/test.txt", "r");
   fscanf(fp, "%s", buff);
   printf("1 : %s\n", buff );
 
   fgets(buff, 255, (FILE*)fp);
   printf("2: %s\n", buff );
   
   fgets(buff, 255, (FILE*)fp);
   printf("3: %s\n", buff );
   fclose(fp);
}
```

```c
int fseek(FILE *stream, long offset, int whence);
```
`fseek` 设置当前读写点到 `offset` 处, `whence` 可以是 `SEEK_SET`,`SEEK_CUR`,`SEEK_END` 这些值决定是从文件头、当前点和文件尾计算偏移量 `offset`.
你可以定义一个文件指针 `FILE *fp`,当你打开一个文件时，文件指针指向开头，你要指到多少个字节，只要控制偏移量就好，例如, 相对当前位置往后移动一个字节：`fseek(fp,1,SEEK_CUR)`; 中间的值就是偏移量。 如果你要往前移动一个字节，直接改为负值就可以：`fseek(fp,-1,SEEK_CUR)`。



### 二进制I/O函数
下面两个函数用于二进制输入和输出
```c
size_t fread(void *ptr, size_t size_of_elements,size_t  number_of_elements, FILE *a_file);
              
size_t fwrite(const void *ptr, size_t size_of_elements,size_t number_of_elements, FILE *a_file);

```