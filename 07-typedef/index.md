C 语言提供了 `typedef` 关键字，您可以使用它来为类型取一个新的名字。下面的实例为单字节数字定义了一个术语 BYTE：
```c
typedef unsigned char BYTE;
```
在定义完这个类型之后,标识符`BYTE`可作为类型`unsigned char`的缩写(别名)
```c
BYTE  b1,b2;
```

可以用`typedef`来为用户定义的数据类型取一个新的名字,
可以对结构体使用 typedef 来定义一个新的数据类型名字，然后使用这个新的数据类型来直接定义结构变量

```c
#include <stdio.h>
#include <string.h>

typedef struct Books
{
   char  title[50];
   char  author[50];
   char  subject[100];
   int   book_id;

} Book;

int main()
{
    Book book;

    strcpy(book.title,"C 教程");
    strcpy(book.author,"C 教程");
    strcpy(book.subject,"C 教程");
    book.book_id = 111;
    printf("Memory of struct Book occupy %lu\n", sizeof(book));


    printf( "书标题 : %s\n", book.title);
    printf( "书作者 : %s\n", book.author);
    printf( "书类目 : %s\n", book.subject);
    printf( "书 ID : %d\n", book.book_id);
    return 0;
}
```


##### typedef vs #define

1. `typedef` 仅限于为类型定义符号名称，`#define` 不仅可以为类型定义别名，也能为数值定义别名，比如您可以定义 1 为 ONE。
2. `typedef` 是由编译器执行解释的，`#define` 语句是由预编译器进行处理的。


```c
#include <stdio.h>
 
#define TRUE  1
#define FALSE 0
 
int main( )
{
   printf( "TRUE 的值: %d\n", TRUE);
   printf( "FALSE 的值: %d\n", FALSE);
 
   return 0;
}
```