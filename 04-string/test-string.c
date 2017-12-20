#include <stdio.h>
#include <string.h>


void test()
{
    char greeting[6] = {'H','e','l','l','o','\0'};
    
    printf("Greeting message: %s\n",greeting);
}

void test1()
{
    char str1[12] = "Hello";
    char str2[12] = "World";
    char str3[12];
    int  len ;
    
    /* 复制 str1 到 str3 */
    strcpy(str3, str1);
    printf("strcpy( str3, str1) :  %s\n", str3 );
    
    /* 连接 str1 和 str2 */
    strcat( str1, str2);
    printf("strcat( str1, str2):   %s\n", str1 );
    
    /* 连接后，str1 的总长度 */
    len = strlen(str1);
    printf("strlen(str1) :  %d\n", len );
}

int main()
{
    test1();
    
    return 0;
}
