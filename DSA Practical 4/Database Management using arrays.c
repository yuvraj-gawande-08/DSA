#include <stdio.h>
struct Student
{
    int rollno;
    char name[20];
    float marks;
};
struct Student s[50];
int n = 0;
void create();
void display();
void modify();
void search();
void sort();
int main()
{
    int ch;
    do
    {
        printf("\n\n1. Create");
        printf("\n2. Display");
        printf("\n3. Modify");
        printf("\n4. Search");
        printf("\n5. Sort");
        printf("\n6. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            create();
            break;
        case 2:
            display();
            break;

        case 3:
            modify();
            break;
        case 4:
            search();
            break;
        case 5:
            sort();
            break;
        case 6:
            printf("Exit");
            break;
        default:
            printf("Invalid Choice");
        }
    } while (ch != 6);
    return 0;
}
void create()
{
    int i;
    printf("\nEnter number of students: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        printf("\nEnter Roll No: ");
        scanf("%d", &s[i].rollno);
        printf("Enter Name: ");
        scanf("%s", s[i].name);
        printf("Enter Marks: ");
        scanf("%f", &s[i].marks);
    }
}

void display()
{
    int i;
    printf("\nRoll No\t\tName\t\tMarks");
    for (i = 0; i < n; i++)
    {
        printf("\n%d\t\t%s\t\t%.2f",
               s[i].rollno,
               s[i].name,
               s[i].marks);
    }
}
void modify()
{
    int roll, i;
    printf("\nEnter Roll No to modify: ");
    scanf("%d", &roll);
    for (i = 0; i < n; i++)
    {
        if (s[i].rollno == roll)
        {
            printf("Enter New Name: ");
            scanf("%s", s[i].name);
            printf("Enter New Marks: ");
            scanf("%f", &s[i].marks);
            printf("\nRecord Modified");
            return;
        }
    }
    printf("\nRecord Not Found");
}
void search()
{
    int roll, i;
    printf("\nEnter Roll No to search: ");
    scanf("%d", &roll);

    for (i = 0; i < n; i++)
    {
        if (s[i].rollno == roll)
        {
            printf("\nRoll No: %d", s[i].rollno);
            printf("\nName: %s", s[i].name);
            printf("\nMarks: %.2f", s[i].marks);
            return;
        }
    }
    printf("\nRecord Not Found");
}
void sort()
{
    int i, j;
    struct Student temp;
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - 1 - i; j++)
        {
            if (s[j].rollno > s[j + 1].rollno)
            {
                temp = s[j];
                s[j] = s[j + 1];
                s[j + 1] = temp;
            }
        }
    }
    printf("\nDatabase Sorted");
}
