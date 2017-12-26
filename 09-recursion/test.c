#include <stdio.h>
#include <stdlib.h>

double factorial(unsigned int num){
    if(num > 1){
        return num * factorial(num -1);
    }
    return 1;
}


int fibonaci(int i)
{
    if(i < 2){
        return i;
    }
    return fibonaci(i -1) + fibonaci(i-2);
}

void test()
{
    int i = 15;
    printf("%d 的阶乘为 %f\n",i,factorial(i));
}

void test1()
{
    int i;
    for (i = 0; i < 10; i++)
    {
       printf("%d\t\n", fibonaci(i));
    }
}

int main()
{
    test1();
    return EXIT_SUCCESS;
}