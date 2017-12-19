#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void getSeconds(unsigned long *par);

double getAverage(int *arr,int size);

int * getRandom();

/*传递指针给函数*/
void test()
{
    unsigned long sec;
    
    getSeconds(&sec);
    
    printf("Number of seconds: %ld\n",sec);
}


/*传递指针给函数*/
void test1()
{
    int balance[5] = {1000, 2, 3, 17, 50};
    double avg;
    avg = getAverage(balance,5);
    printf("Average value is: %f\n",avg);
}

void test2()
{
    int *p;
    int i;
    p = getRandom();
    for(i = 0; i< 10;i++){
        printf("*(p + [%d]): %d\n", i , *(p + i));
    }
}


int main()
{
    test2();
    return 0;
}


void getSeconds(unsigned long *par)
{
    *par = time(NULL);//获取当前秒数
    return ;
}

/*
 能接受指针作为参数的函数，也能接受数组作为参数，如下所示
 */
double getAverage(int *arr, int size)
{
    int i,sum = 0;
    double avg;
    for(i = 0; i < size; i++){
        sum += arr[i];
    }
    avg = (double)sum/size;
    return avg;
}

int * getRandom()
{
    static int r[10];
    int i;
    srand((unsigned)time(NULL));
    for (i = 0; i < 10; i++) {
        r[i] = rand();
        printf("%d\n",r[i]);
    }
    return r;
}
