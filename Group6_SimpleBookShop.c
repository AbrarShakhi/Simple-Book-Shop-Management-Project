#include<stdio.h>
#include<conio.h>
#include<string.h> 
#include<stdlib.h> 

int SerialNumber;
struct book
{
    char bName[50];
    char bAuthor[30];
    float bPrice;
    int bCopies;
};
struct book lib[500];

void ShowWelcomeMessage();
void ShowGoodByeMessage();
void ShowMenuOption();
void ShowBooks();
void AddBook();
int SearchBook();
void ShowNumberOfBooks();

int main()
{
    SerialNumber=0;
    int navigator;

    ShowWelcomeMessage();
    ShowMenuOption();
    again :
    printf("\n");
    printf("Enter your choice : ");
    scanf("%d",&navigator);
    printf("\n");
    switch(navigator)
    {
        case 1:
            ShowMenuOption();
        break;
        case 2:
            ShowBooks();
        break;
        case 3:
            AddBook();
        break;
        case 4:
            SearchBook();
        break;
        case 5:
            ShowNumberOfBooks();
        break;
        case 6:
            system("cls");
            ShowGoodByeMessage();
            return 0;
        break;
        default:
            printf("\nInvalid Inout.\n");
            ShowMenuOption();
            goto again;
        break;
    }
    goto again;
}

void ShowWelcomeMessage()
{
    system("cls");
    printf("*****************************************\n");
    printf("\n");
    printf("Welcome to Simple Book Management System.\n");
    printf("\n");
    printf("*****************************************\n");
    printf("\n");
    printf("\n");
}
void ShowGoodByeMessage()
{
    printf("**************************************************\n");
    printf("\n");
    printf("Thank you for using Simple Book Management System\n");
    printf("\n");
    printf("**************************************************\n");
    getch();
}
void ShowMenuOption()
{
    printf("Please enter a menu option number:\n");
    printf("1) Display this menu.\n");
    printf("2) Show all available books.\n");
    printf("3) Add a book to the book shop.\n");
    printf("4) Search a book by tittle.\n");
    printf("5) Display the total number of books.\n");
    printf("6) Exit from this book shop.\n");
    printf("\n");
}
void ShowBooks()
{
    if (SerialNumber==0)
        printf("Opps! Looks like shelfs are empty.\n");
    else
    {
        int i;
        printf("List of books:\n\n");
        for (i=0; i<SerialNumber; i++)
        {
            printf("Book title: %s", lib[i].bName);
            printf("Book author: %s", lib[i].bAuthor);
            printf("Book price: %.2f\n", lib[i].bPrice);
            printf("Copies: %d\n\n", lib[i].bCopies);
        }
    }
}
void AddBook()
{
    fflush(stdin);
    printf("Enter book title: ");
    fgets(lib[SerialNumber].bName, 50, stdin);
    
    printf("Enter book author: ");
    fgets(lib[SerialNumber].bAuthor, 50, stdin);

    printf("Enter book price: ");
    scanf("%f", &lib[SerialNumber].bPrice);

    printf("Enter number of copies: ");
    scanf("%d", &lib[SerialNumber].bCopies);

    ++SerialNumber;
}
int SearchBook()
{
    char searchtitle[50];
    fflush(stdin);
    printf("Enter book title to search: ");
    fgets(searchtitle, 50, stdin);
    printf("\n");
    int i, x=0;
    for (i=0; i<SerialNumber; i++)
    {
        if (strcmp(searchtitle, lib[i].bName)==0)
        {
            printf("Book title: %s", lib[i].bName);
            printf("Book author: %s", lib[i].bAuthor);
            printf("Book price: %.2f\n", lib[i].bPrice);
            printf("Copies: %d\n\n", lib[i].bCopies);
            x++;
        }
    }
    if(x==0) printf("Book not found.\n");

    return 0;
}
void ShowNumberOfBooks()
{
    printf("Total number of books in the shop: %d\n", SerialNumber);
}