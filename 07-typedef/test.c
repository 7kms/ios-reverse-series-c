#include <stdio.h>
#include <string.h>

typedef struct Books
{
   char  title[50];
   char  author[50];
   char  subject[100];
   int   book_id;

} Book;

int main()
{
    Book book;

    strcpy(book.title,"C 教程");
    strcpy(book.author,"C 教程");
    strcpy(book.subject,"C 教程");
    book.book_id = 111;
    printf("Memory of struct Book occupy %lu\n", sizeof(book));


    printf( "书标题 : %s\n", book.title);
    printf( "书作者 : %s\n", book.author);
    printf( "书类目 : %s\n", book.subject);
    printf( "书 ID : %d\n", book.book_id);
    return 0;
}