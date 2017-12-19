#include <stdio.h>

#define MAX  3

//指针的声明和赋值
int test0()
{
    int var = 20;//实际变量的声明
    int *ip;//指针变量的声明
    ip = &var;//在指针变量中存储 var 的地址
    
    printf("Address of var variable: %p\n", &var  );
    
    printf("Address stored in ip variable: %p\n",ip);
    
    printf("Value of *ip variable: %d\n",*ip);
    
    return 0;
}

/*
    c中的NULL指针
    在变量声明的时候，如果没有确切的地址可以赋值，为指针变量赋一个 NULL 值是一个良好的编程习惯。
    赋为 NULL 值的指针被称为空指针。
 */
int test1()
{
    int *ptr = NULL;
    printf("ptr 的值是 %p\n",ptr);//ptr 的值是 0x0
    return 0;
}

/* 递增一个指针 */
void test2(){
//    const int MAX = 3;
    int  var[] = {10, 100, 200};
    int  i, *ptr;
    
    /* 指针中的数组地址 */
    ptr = var;
    for ( i = 0; i < MAX; i++)
    {
        printf("存储地址：var[%d] = %p\n", i, ptr );
        printf("存储值：var[%d] = %d\n", i, *ptr );
        /* 移动到下一个位置 */
        ptr++;
    }
}

/*递减一个指针*/
void test3()
{
//    const int MAX = 3;
    int  var[] = {10, 100, 200};
    int  i, *ptr;
    
    /* 指针中最后一个元素的地址 */
    ptr = &var[MAX-1];
    for ( i = MAX; i > 0; i--)
    {
        printf("存储地址：var[%d] = %p\n", i-1, ptr );
        printf("存储值：var[%d] = %d\n", i-1, *ptr );
        
        /* 移动到下一个位置 */
        ptr--;
    }
}

/*指针的比较*/
void test4()
{
//    const int MAX = 3;
    int  var[] = {10, 100, 200};
    int  i, *ptr;
    
    /* 指针中第一个元素的地址 */
    ptr = var;
    i = 0;
    while ( ptr <= &var[MAX - 1] )
    {
        
        printf("Address of var[%d] = %p\n", i, ptr );
        printf("Value of var[%d] = %d\n", i, *ptr );
        
        /* 指向下一个位置 */
        ptr++;
        i++;
    }
}

/*指针数组*/
void test5()
{
    int var[] = {10,20,30};
    int i, *ptr[MAX];
    for(i = 0;i < MAX;i++){
        ptr[i] = &var[i];//赋值为整数的地址
    }
    for(i = 0; i < MAX; i++){
        printf("Value of var[%d] = %d\n",i, *ptr[i]);
    }
}

/*字符型指针数组,可以用一个指向字符的指针数组来储存一个字符串列表*/
void test6()
{
    char *names[] = {"name1","name2","name3"};
    int i = 0;
    for (i = 0;i < MAX; i++){
        printf("Value of names[%d] = %s\n", i, names[i]);
    }
    
}

/*指向指针的指针*/
void test7()
{
    int var;
    int *ptr;
    int **pptr;
    int ***ppptr;
    var = 3000;
    
    
    ptr = &var;//获取var的地址
    pptr = &ptr;//使用运算符&获取ptr的地址
    ppptr = &pptr;
    
    
    printf("var, %p, %d\n", &var ,var);
    printf("*ptr,  %p, %d\n", ptr, *ptr);
    printf("**ptr, %p, %d\n", pptr, **pptr);
    printf("***ppptr, %p, %d\n", ppptr, ***ppptr);
}

int main()
{
    test7();
}
