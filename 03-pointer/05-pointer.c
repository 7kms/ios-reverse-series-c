#include <stdio.h>
#include <stdlib.h>


/*
    函数指针:
    函数指针是指向函数的指针变量
    函数指针可以像一般函数一样,用于调用函数,传递参数
    函数指针变量的声明:
    typedef int (*fun_ptr)(int,int);//声明一个指向同样参数,返回值的函数指针类型
 
 
    回调函数:
    函数指针变量可以作为某个函数的参数来使用,回调函数就是一个通过函数指针调用的函数.
 
 */


//接受一个函数指针作为参数,供其调用
//size_t 是一种数据类型，近似于无符号整型，但容量范围一般大于 int 和 unsigned。这里使用 size_t 是为了保证 arraysize
void populate_array(int *array,size_t arraySize, int(*getNextValue)(void))
{
    for(size_t i = 0; i< arraySize; i++){
        array[i] = getNextValue();
    }
}

// 获取随机值
int getNextRandomValue(void)
{
    return rand();
}


int max(int x, int y)
{
    return x > y ? x : y;
}

//定义函数指针
void test()
{
    int (*p)(int,int) = &max;//声明一个指向函数的指针p, &可以省略
    int a,b,c,d;
    printf("Please input 3 numbers\n");
    scanf("%d,%d,%d",&a,&b,&c);
    
    d = p(p(a,b),c);
    printf("The maximum number is %d\n",d);
    
}

//使用回调函数
void test1()
{
    int myarray[10];
    populate_array(myarray,10,getNextRandomValue);
    for(int i = 0; i< 10; i++){
        printf("%d\n",myarray[i]);
    }
}


int main()
{

    test1();
}

