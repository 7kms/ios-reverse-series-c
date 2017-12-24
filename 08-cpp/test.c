#include <stdio.h>

#define  message_for(a, b)  \
    printf(#a " and " #b ": We love you!\n")

#define tokenpaster(n) printf("token" #n "=%d\n",token##n)

#define square(x) ((x) * (x))

#define square_1(x) (x * x)

//预定义宏
void test()
{
   printf("File :%s\n", __FILE__ );
   printf("Date :%s\n", __DATE__ );
   printf("Time :%s\n", __TIME__ );
   printf("Line :%d\n", __LINE__ );
   printf("ANSI :%d\n", __STDC__ );
}

void tes1()
{
     message_for(Carole, Debra);
}

void test2()
{
    int token12 = 12;
    tokenpaster(12);
}

void test3()
{
   printf("square 5+4 is %d\n", square(5+4));  
   printf("square_1 5+4 is %d\n", square_1(5+4)); 
    //square   等价于   （5+4）*（5+4）=81
    // square_1 等价于   5+4*5+4=29
}

int main()
{
    test3();
   return 0;
}