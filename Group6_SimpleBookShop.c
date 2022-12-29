#include <stdio.h>  //Standard input & output header file.
#include <conio.h>  //Console input & output header file. [We have used getch() function.]
#include <string.h> //String header file. [We have used strcmp(), strlwr(), strcpy() function]

int SerialNumber; // Declare a integer variable that can be used by all the function.
struct book
{
    char bName[50];
    char bAuthor[30];
    float bPrice;
    int bCopies;
};
struct book lib[500]; // Declare struct arrary variable that can be used by all the function.

// Function prototype.
void ShowWelcomeMessage();
void ShowGoodByeMessage();
void ShowMenuOption();
void ShowBooks();
void AddBook();
void SearchBook();
void ShowNumberOfBooks();

// main function.
int main()
{
    SerialNumber = 0; /*First SerialNumber = 0
      This number will increase if user add a book.*/

    ShowWelcomeMessage(); // Function call. It will show the welcome message.
    ShowMenuOption();     // It will show the Menu option.

    int navigator; // integer variable for switch case.
    while (1)
    {
        printf("\n");
        printf("Enter your choice : ");
        scanf("%d", &navigator); // It will take a integer and store it to navigator.
        printf("\n");
        fflush(stdin); /*Without fflush function, If the user input a character or string in
        [scanf("%d",&navigator);-line 38] it will make a infinite loop.
        The purpose of fflush(stdin) is to clean (or flush) the output buffer and transfer the buffered
        data into Terminal or Disk.*/

        switch (navigator) // if the navigator is 1 to 6 then it will do certain tasks.
        {
        case 1:
            ShowMenuOption(); // If the user enter 1 then call ShowMenuOption() and show the Menu option.
            break;
        case 2:
            ShowBooks(); // If the user enter 2 then call ShowBooks() function and show all the added books.
            break;
        case 3:
            AddBook(); // If the user enter 3 then call AddBook() function.
            break;
        case 4:
            SearchBook(); // If the user enter 4 then call SearchBook() function.
            break;
        case 5:
            ShowNumberOfBooks(); // If the user enter 5 then call ShowNumberOfBooks() function.
            break;
        case 6:
            ShowGoodByeMessage(); // If the user enter 6 then call ShowGoodByeMessage() function.
            getch();              // Program will wait before ending for user to enter any key
            return 0;             // and program will end right here.
            break;
        default:                          // If user enter invalid input (navigator<1 || navigator>6)
            printf("\nInvalid Input.\n"); // Show a Invalid message.
            ShowMenuOption();             // call ShowMenuOption()
            break;
        }
        navigator = 0;
    }
}
// Function Definition.
void ShowWelcomeMessage()
{
    // Welcome message
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
    // Goodbye message
    printf("**************************************************\n");
    printf("\n");
    printf("Thank you for using Simple Book Management System\n");
    printf("\n");
    printf("**************************************************\n");
}
void ShowMenuOption()
{
    // Menu option
    printf("Please enter a menu option number:\n");
    printf("1) Display this menu.\n");
    printf("2) Show all available books.\n");
    printf("3) Add a book to the book shop.\n");
    printf("4) Search a book by tittle.\n");
    printf("5) Display the total number of books.\n");
    printf("6) Exit from this book shop.\n");
    printf("\n");
}
void ShowBooks() // Definition of ShowBooks() function.
{
    if (SerialNumber == 0) // If user do not add any books then the condition is true and print this message.
        printf("Shelfs are empty.\n");
    else // If user add any books then SerialNumber!=0.
    {
        printf("List of books:\n\n");
        int i;                             // Declare a variable for loop.
        for (i = 0; i < SerialNumber; i++) // loop will run until i<SerialNumber.
        {
            printf("Book title: %s", lib[i].bName);
            printf("Book author: %s", lib[i].bAuthor);
            printf("Book price: %.2f\n", lib[i].bPrice);
            printf("Copies: %d\n\n", lib[i].bCopies);
        }
    }
}
void AddBook() // Definition of void AddBook() function
{
    if (SerialNumber <= 500) // We can add maximum 500 books in this program
    {
        printf("Enter book title: ");
        fgets(lib[SerialNumber].bName, 50, stdin);

        printf("Enter book author: ");
        fgets(lib[SerialNumber].bAuthor, 50, stdin);

        printf("Enter book price: ");
        scanf("%f", &lib[SerialNumber].bPrice);
        fflush(stdin);
        // to clean (or flush) the output buffer and transfer the buffered data into Terminal or Disk.

        printf("Enter number of copies: ");
        scanf("%d", &lib[SerialNumber].bCopies);
        fflush(stdin);
        // to clean (or flush) the output buffer and transfer the buffered data into Terminal or Disk.

        ++SerialNumber; // SerialNumber will increase if user adds book.
    }
    else // When we reach to maximum book added it will show this message.
        printf("You can add maximum 500 book.\n");
}
void SearchBook() // Definition of void SearchBook() function
{
    int i, x = 0;
    char searchtitle[50], title[50]; // Declare a variable to store a string

    printf("Enter book title to search: ");
    fgets(searchtitle, 50, stdin);
    strupr(searchtitle); // It will make the string upper case stored in searchtitle veriable.

    printf("\n");
    for (i = 0; i < SerialNumber; i++)
    {
        strcpy(title, lib[i].bName); // It will copy the []
        strupr(title);
        if (strcmp(searchtitle, title) == 0) // Compare two string
        {
            printf("Book title: %s", lib[i].bName);
            printf("Book author: %s", lib[i].bAuthor);
            printf("Book price: %.2f\n", lib[i].bPrice);
            printf("Copies: %d\n\n", lib[i].bCopies);
            x++; // x will increase if book matches
        }
    }
    if (x == 0)
        printf("Book not found.\n");
    // If Search do not match then x will 0 it and will print this message.
}
void ShowNumberOfBooks() // Definition of void ShowNumberOfBooks() function
{                        // total number of books is SerialNumber.
    printf("Total number of books in the shop: %d\n", SerialNumber);
}
