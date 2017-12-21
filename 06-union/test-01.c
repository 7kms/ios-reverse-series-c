#include <stdio.h>
#include <string.h>

union Data
{
    int i;
    float f;
    char str[20];
};


void test()
{
    union Data data;
    printf( "Memory size occupied by data : %lu\n", sizeof(data));
    //共用体占用的内存应该足够存储其中最大的成员
    
    data.i = 10;
    data.f = 220.5;
    strcpy(data.str,"C Programming");
    
    printf("data.i : %d\n", data.i);
    printf("data.f : %f\n", data.f);
    printf("data.str : %s\n", data.str);
    //我们可以看到共用体的 i 和 f 成员的值有损坏
    //因为最后赋给变量的值占用了内存位置，这也是 str 成员能够完好输出的原因
}


//所有的成员都能完好输出，因为同一时间只用到一个成员
void test1()
{
    union Data data;
    
    data.i = 10;
    printf( "data.i : %d\n", data.i);
    
    data.f = 220.5;
    printf( "data.f : %f\n", data.f);
    
    strcpy( data.str, "C Programming");
    printf( "data.str : %s\n", data.str);
}


int main()
{
    test1();
    return 0;
}



