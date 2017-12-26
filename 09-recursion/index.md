# 递归

递归指的是在函数的定义中使用函数自身的方法。

语法格式如下:
```c
void recursion()
{
   recursion(); /* 函数调用自身 */
}

int main()
{
   recursion();
}
```

C 语言支持递归，即一个函数可以调用其自身。但在使用递归时，程序员需要注意定义一个从函数退出的条件，否则会进入死循环。

### 数的阶乘

```c

double factorial(unsigned int num){
    if(num > 1){
        return num * factorial(num -1);
    }
    return 1;
}

int main()
{
    int i = 15;
    printf("%d 的阶乘为 %f\n",i,factorial(i));
    return 0;
}
```


### 斐波那契数列

```c
#include <stdio.h>
#include <stdlib.h>

int fibonachi(int i)
{
    if(i < 2){
        return i;
    }
    return fibonachi(i -1) + fibonachi(i-2);
}


int main()
{
    int i;
    for (i = 0; i < 10; i++)
    {
       printf("%d\t\n", fibonaci(i));
    }
    return EXIT_SUCCESS;
}
```