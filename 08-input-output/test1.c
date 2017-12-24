#include <stdio.h>


void test()
{
    float f;
    printf("Enter a number: ");
    // %f 匹配浮点型数据
    scanf("%f",&f);
    printf("Value = %f\n", f);
}

/* getchar putchar */
void test1()
{
   int c;
   printf( "Enter a value :");
   c = getchar();
   printf("\nYou entered: ");
   putchar(c);//向屏幕输出一个整数,并且返回一个整数
   printf( "\n");
}



/*
    char * gets(char *s)
    int puts(const char *s)
*/
void test2()
{
    char str[100];
    printf("Enter a value: ");
    gets(str);
    printf( "\nYou entered: ");
    puts(str);
}

/*
    int scanf(char *format,...)
    printf(char *format,...)
*/
void test3()
{
    char str[5];
    int i;
    int tmp;
    tmp = printf( "Enter a value :");
    printf("%d\n",tmp);
    scanf("%s %d", str, &i);
    printf( "\nYou entered: %s %d ", str, i);
    printf("\n");
}

void test4()
{
    char str[5];
    printf( "Enter a value :%lu",sizeof(str));

    fgets( str,sizeof(str),stdin );

    printf( "\nYou entered: ");
    puts( str );
}
int main()
{
    test4();
    return 0;
}