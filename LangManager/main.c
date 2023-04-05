#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define max_file 1000

struct student
{
    char first_name[30];
    char last_name[30];
    char language[30];
    char age[4];
};

void menu ()
{
    printf("Select one option by choosing the corresponding number:\n");
    printf("1. Show details of all students\n");
    printf("2. Add a new student\n");
    printf("3. Show all students that study a specific language\n");
    printf("4. Search a student by their last name\n");
    printf("5. Search a student by their first name\n");
    printf("6. Remove a certain student from the database\n");
    printf("7. Close program\n");
}
void option1 (FILE *p)    //shows the details of all students
{
    char c[200];
    p=fopen("..\\file.txt", "r");
    if (p==NULL)
        printf("File cannot be opened\n");
    while (fgets(c, sizeof (c), p))
        printf(c);
    fclose(p);
}
void option2 ()    //adds a new student
{
    FILE *p=fopen("..\\file.txt", "a+");
    fputs("\n", p);
    char c[50];

    printf("Please introduce the student's first name:\n");
    scanf ("%s", c);
    if (c[0]>='a' && c[0]<='z')
        c[0]-=32;
    fputs(c, p);

    fputs(" ", p);
    printf("Please introduce the student's last name:\n");
    scanf ("%s", c);
    if (c[0]>='a' && c[0]<='z')
        c[0]-=32;
    fputs(c, p);

    fputs(" ", p);
    printf("Please introduce the language studied by the student:\n");
    scanf ("%s", c);
    fputs(c, p);

    fputs(" ", p);
    printf("Please introduce the student's age:\n");
    scanf ("%s", c);
    fputs(c, p);

    fclose(p);
}
int size_of_file ()
{
    FILE *p=fopen("..\\file.txt", "r");
    int k=0;
    char file[max_file];
    char c;

    if (p == NULL)
    {
        printf("The file is empty %s");
        return 0;
    }

    for (c = getc(p); c != EOF; c = getc(p))
        if (c == '\n')
            k++;
    fclose(p);
    return k;
}
void option3 ()  //shows all students that study a specific language
{
    int k=size_of_file()+1;
    struct student s[k];
    FILE *p=fopen("..\\file.txt", "r");
    if (p==NULL)
    {
        printf("File cannot be open\n");
        exit(1);
    }
    for (int i=0; i<k; i++)
    {
        char c[200];
        fgets(c, sizeof (c), p);
        char *word=strtok(c, " ");
        int contor=1;
        while (word!=NULL)
        {
            if (contor==1)
                strcpy(s[i].first_name, word);
            else if (contor==2)
                strcpy(s[i].last_name, word);
            else if (contor==3)
                strcpy(s[i].language, word);
            else if (contor==4)
                strcpy(s[i].age, word);

            contor++;
            word=strtok(NULL, " ");
        }
    }
    printf("Please introduce the language:\n");
    char language[30];
    int ok=0;
    scanf("%s", language);
    for (int i=0; i<k; i++)
    {
        if (strcmp(s[i].language, language)==0)
        {
            printf("%s %s %s %s", s[i].first_name, s[i].last_name, s[i].language, s[i].age);
            ok=1;
        }
    }
    if(ok==0)
        printf("There are no students studying this language.");
    fclose(p);
}

void option4 ()   //searches a student by their last name
{
    int k=size_of_file()+1;
    struct student s[k];
    FILE *p=fopen("..\\file.txt", "r");
    if (p==NULL)
    {
        printf("File cannot be open\n");
        exit(1);
    }
    for (int i=0; i<k; i++)
    {
        char c[200];
        fgets(c, sizeof (c), p);
        char *word=strtok(c, " ");
        int contor=1;
        while (word!=NULL)
        {
            if (contor==1)
                strcpy(s[i].first_name, word);
            else if (contor==2)
                strcpy(s[i].last_name, word);
            else if (contor==3)
                strcpy(s[i].language, word);
            else if (contor==4)
                strcpy(s[i].age, word);

            contor++;
            word=strtok(NULL, " ");
        }
    }
    printf("Please introduce the last name of the student you are looking for:\n");
    char last_name[30];
    int ok=0;
    scanf("%s", last_name);
    for (int i=0; i<k; i++)
    {
        if (strcmp(s[i].last_name, last_name)==0)
        {
            printf("%s %s %s %s", s[i].first_name, s[i].last_name, s[i].language, s[i].age);
            ok=1;
        }
    }
    if(ok==0)
        printf("There are no students with this last name.");
    fclose(p);
}

void option5 ()   //searches a student by their first name
{
    int k=size_of_file()+1;
    struct student s[k];
    FILE *p=fopen("..\\file.txt", "r");
    if (p==NULL)
    {
        printf("File cannot be open\n");
        exit(1);
    }
    for (int i=0; i<k; i++)
    {
        char c[200];
        fgets(c, sizeof (c), p);
        char *word=strtok(c, " ");
        int contor=1;
        while (word!=NULL)
        {
            if (contor==1)
                strcpy(s[i].first_name, word);
            else if (contor==2)
                strcpy(s[i].last_name, word);
            else if (contor==3)
                strcpy(s[i].language, word);
            else if (contor==4)
                strcpy(s[i].age, word);

            contor++;
            word=strtok(NULL, " ");
        }
    }
    printf("Please introduce the first name of the student you are looking for:\n");
    char first_name[30];
    int ok=0;
    scanf("%s", first_name);
    for (int i=0; i<k; i++)
    {
        if (strcmp(s[i].first_name, first_name)==0)
        {
            printf("%s %s %s %s", s[i].first_name, s[i].last_name, s[i].language, s[i].age);
            ok=1;
        }
    }
    if(ok==0)
        printf("There are no students with this first name.");
    fclose(p);
}

void option6()  //removes a student
{
    int k=size_of_file()+1;
    struct student s[k];
    FILE *p=fopen("..\\file.txt", "r");
    if (p==NULL)
    {
        printf("File cannot be open\n");
        exit(1);
    }
    for (int i=0; i<k; i++)
    {
        char c[200];
        fgets(c, sizeof (c), p);
        char *word=strtok(c, " ");
        int contor=1;
        while (word!=NULL)
        {
            if (contor==1)
                strcpy(s[i].first_name, word);
            else if (contor==2)
                strcpy(s[i].last_name, word);
            else if (contor==3)
                strcpy(s[i].language, word);
            else if (contor==4)
                strcpy(s[i].age, word);

            contor++;
            word=strtok(NULL, " ");
        }
    }
    fclose(p);

    char last_name[30], first_name[30];
    int ok=0;
    printf("Please introduce student's first name:\n");
    scanf("%s", first_name);
    printf("Please introduce student's last name:\n");
    scanf("%s", last_name);

    FILE *t=fopen("..\\file.txt", "w");
    for (int i=0; i<k; i++)
    {
        if (strcmp(s[i].last_name, last_name)!=0 || strcmp(s[i].first_name, first_name)!=0)
        {
            ok=1;
            fputs(s[i].first_name, t);
            fputs(" ", t);
            fputs(s[i].last_name, t);
            fputs(" ", t);
            fputs(s[i].language, t);
            fputs(" ", t);
            fputs(s[i].age, t);
        }
    }
    if(ok==0)
        printf("There is no student with this name.");
    else
        printf("The student was successfully removed from the database.");
    fclose(t);
}

int main(){
    int option;
    FILE *p;
    menu();
    scanf("%d", &option);
    while (option!=7)
    {
        if (option==1)
        {
            option1(p);

            printf("\n\n");
            menu();
            scanf("%d", &option);
        }
        if (option==2)
        {
            option2();
            printf("The new student was successfully added to the database.");

            printf("\n\n");
            menu();
            scanf("%d", &option);
        }
        if (option==3)
        {
            option3();

            printf("\n\n");
            menu();
            scanf("%d", &option);
        }
        if (option==4)
        {
            option4();

            printf("\n\n");
            menu();
            scanf("%d", &option);
        }
        if (option==5)
        {
            option5();

            printf("\n\n");
            menu();
            scanf("%d", &option);
        }
        if (option==6)
        {
            option6();

            printf("\n\n");
            menu();
            scanf("%d", &option);
        }
    }
}