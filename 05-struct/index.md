# 结构体
> c数组允许定义可存储想通类型数据项的变量,`结构`是c编程中另一种用户自定义的可用的数据类型,它允许您存储不同类型的数据项.


##### 定义结构

struct语句定义了一个包含多个成员的新的数据类型,struct语句的格式如下:

```c
struct [structure tag]
{
    member definition;
    member definition;
    ...
    member definition;
    
}[one or more structure variables];
```
`structure tag`是可选的,每个member definition是标准的变量定义,比如int i;或者 float f;或者其他有效的变量定义.在最后一个分好之前,可以指定一个或者多个结构变量,这是可选的.

```c
struct Books
{
    char title[50];
    char author[50];
    char subject[100];
    int book_id;
} book;
```

##### 访问成员
```c
/*
 访问结构体成员
 */
void test()
{
    struct Books Book1;
    /*Book1 详述*/
    strcpy(Book1.title,"C Progromming");
    strcpy(Book1.author,"Nuha Ali");
    strcpy(Book1.subject,"C Programming Tutorial");
    Book1.book_id = 232939;

    //输出信息
    printf("Book 1 title: %s\n",Book1.title);
    printf("Book 1 author: %s\n",Book1.author);
    printf("Book 1 subject: %s\n",Book1.subject);
    printf("Book 1 is: %d\n",Book1.book_id);
}
```
##### 指向结构体的指针

```c
//定义指向结构体的指针
struct Books *struct_pointer;
//赋值
struct_pointer = &Book1;
//取值
struct_pointer->title;

```

```c
/*
    指向结构体的指针
 */
void printBook2(struct Books *book)
{
    //输出信息
    printf("Book  title: %s\n",book->title);
    printf("Book author: %s\n",book->author);
    printf("Book  subject: %s\n",book->subject);
    printf("Book  is: %d\n",book->book_id);
}
```
##### 位域

> 有些信息在存储时，并不需要占用一个完整的字节，而只需占几个或一个二进制位

位域的定义和结构体相仿:

```c
struct 位域结构名
{
    位域列表
};
```

其中`位域列表`形式为:

```c
类型说明符 位域名: 位域长度;
```
例如:
```c
struct bs 
{
    int a:8;
    int b:2;
    int c:6;
} data;

//说明 data 为 bs 变量，共占两个字节。其中位域 a 占 8 位，位域 b 占 2 位，位域 c 占 6 位。
```
```c
struct packed_struct {
  unsigned int f1:1;
  unsigned int f2:1;
  unsigned int f3:1;
  unsigned int f4:1;
  unsigned int type:4;
  unsigned int my_int:9;
} pack;
// packed_struct 包含了 6 个成员：四个 1 位的标识符 f1..f4、一个 4 位的 type 和一个 9 位的 my_int。
```

位域的使用:

位域的使用和结构成员的使用相同，其一般形式为：

```c
位域变量名.位域名
位域变量名->位域名
```

使用位域的注意点:
1. 一个位域必须存储在同一个字节中,不能夸两个字节.如一个字节所剩空间不足以存放另一位域时,应从下一单元起存放该位域.也可以有意使某位域从下一单元开始.

```c
struct bs{
    unsigned a:4;
    unsigned  :4; //空域
    unsigned b:4; //从下一单元开始存放
    unsigned c:4;
};
//在这个位域定义中，a 占第一字节的 4 位，后 4 位填 0 表示不使用，b 从第二字节开始，占用 4 位，c 占用 4 位
```

2. 由于位域不允许跨两个字节，因此位域的长度不能大于一个字节的长度，也就是说不能超过8位二进位。如果最大长度大于计算机的整数字长，一些编译器可能会允许域的内存重叠，另外一些编译器可能会把大于一个域的部分存储在下一个字中。

3. 位域可以是无名位域，这时它只用来作填充或调整位置。无名的位域是不能使用的。

```c
struct bs{
    int a:1;
    int  :2;    /* 该 2 位不能使用 */
    int b:3;
    int c:2;
};
```
4. 位域在本质上就是一种结构类型，不过其成员是按二进位分配的.



##### 结构体占用的存储空间

```c

#include <stdio.h>

typedef struct
{
    unsigned char a;
    unsigned int  b;
    unsigned char c;
} debug_size1_t;

typedef struct
{
    unsigned char a;
    unsigned char b;
    unsigned int  c;
} debug_size2_t;

int main(void)
{
    printf("debug_size1_t size=%lu,debug_size2_t size=%lu\r\n", sizeof(debug_size1_t), sizeof(debug_size2_t));
    //debug_size1_t size=12,debug_size2_t size=8
    return 0;
}

//1.debug_size1_t 存储空间分布为a(1byte)+空闲(3byte)+b(4byte)+c(1byte)+空闲(3byte)=12(byte)。
//2.debug_size2_t 存储空间分布为a(1byte)+b(1byte)+空闲(2byte)+c(4byte)=8(byte)。

```


