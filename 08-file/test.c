#include <stdio.h>
 


void test()
{
    FILE *fp = NULL;
    fp = fopen("/tmp/test.txt", "w+");
    fprintf(fp, "This is testing for fprintf...\n");
    fputs("This is testing for fputs...\n", fp);
    fclose(fp);
}

void test1()
{
    FILE *fp = NULL;
    char buff[255];
    fp = fopen("/tmp/test.txt","r");
    fscanf(fp, "%s", buff);
    printf("1 : %s\n", buff );//fscanf() 方法只读取了 This，因为它在后边遇到了一个空格

    fgets(buff, 255, fp);
    printf("2: %s\n", buff );// 调用 fgets() 读取剩余的部分，直到行尾
    
    fgets(buff, 255, fp);
    printf("3: %s\n", buff );// fgets() 完整地读取第二行
    fclose(fp);
}


void test2()
{
    FILE *fp = NULL;
    fp = fopen("./test.txt", "r+");  // 确保 test.txt 文件已创建
    fprintf(fp, "This is testing for fprintf...\n");   
    fseek(fp, 10, SEEK_SET);
    if (fputc(65,fp) == EOF) {
        printf("fputc fail");   
    }   
    fclose(fp);
}
int main()
{
  test2();
}
