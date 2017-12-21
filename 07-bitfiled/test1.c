#include <stdio.h>
#include <string.h>

struct
{
    unsigned int widthValidate;
    unsigned int heighValidate;
} status1;

struct
{
    unsigned int widthValidate:1;
    unsigned int heighValidate:1;
} status2;

struct 
{
    unsigned int age : 3;
} Age;

void test()
{
    printf("Memory size occupied by status1 : %lu\n",sizeof(status1));//8
    
    printf("Memory size occupied by status2 : %lu\n",sizeof(status2));//4
    
}

void test1()
{

    printf( "Sizeof( Age ) : %lu\n", sizeof(Age) );//4
    Age.age = 5;
    printf( "Age.age : %d\n", Age.age );//5

    Age.age = 7;
    printf( "Age.age : %d\n", Age.age );//7

    Age.age = 9;
    printf( "Age.age : %d\n", Age.age );//1
    // 9转换成2进制->10001取后三位001即会输出1
}

int main()
{
    test1();
    return 0;
}
