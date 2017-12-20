#include <stdio.h>
#include <string.h>

struct Books
{
    char title[50];
    char author[50];
    char subject[100];
    int book_id;
};


void printBook(struct Books book);
void printBook2(struct Books *book);

/*
 访问结构体成员
 */
void test()
{
    struct Books Book1;
    /*Book1 详述*/
    strcpy(Book1.title,"C Progromming");
    strcpy(Book1.author,"Nuha Ali");
    strcpy(Book1.subject,"C Programming Tutorial");
    Book1.book_id = 232939;

    //输出信息
    printf("Book 1 title: %s\n",Book1.title);
    printf("Book 1 author: %s\n",Book1.author);
    printf("Book 1 subject: %s\n",Book1.subject);
    printf("Book 1 is: %d\n",Book1.book_id);
}

/*结构体传参*/
void test1()
{
    struct Books Book1;
    
    /*Book1 详述*/
    strcpy(Book1.title,"C Progromming");
    strcpy(Book1.author,"Nuha Ali");
    strcpy(Book1.subject,"C Programming Tutorial");
    Book1.book_id = 232939;
    printBook(Book1);
}

void test2()
{
    struct Books Book1;
    
    /*Book1 详述*/
    strcpy(Book1.title,"C Progromming");
    strcpy(Book1.author,"Nuha Ali");
    strcpy(Book1.subject,"C Programming Tutorial");
    Book1.book_id = 232939;
    printBook2(&Book1);
}

int main()
{
    test1();
    test2();
}


void printBook(struct Books book)
{
    //输出信息
    printf("Book  title: %s\n",book.title);
    printf("Book author: %s\n",book.author);
    printf("Book  subject: %s\n",book.subject);
    printf("Book  is: %d\n",book.book_id);
}


/*
    指向结构体的指针
 */
void printBook2(struct Books *book)
{
    //输出信息
    printf("Book  title: %s\n",book->title);
    printf("Book author: %s\n",book->author);
    printf("Book  subject: %s\n",book->subject);
    printf("Book  is: %d\n",book->book_id);
}




