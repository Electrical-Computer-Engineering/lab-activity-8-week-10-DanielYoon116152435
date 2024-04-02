// Dnaiel Yoon 116152435

#include <stdio.h>
#define MAX 32

int my_isalpha(char ch)
{
    if (ch >= 'A' && ch <= 'Z' || ch >= 'a' && ch <= 'z')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int my_isdigit(char ch)
{
    if (ch >= '0' && ch <= '9')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int my_is_upper(char ch)
{
    if (ch >= 'A' && ch <= 'Z')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

char my_to_upper(char ch)
{
    if (ch >= 'a' && ch <= 'z')
    {
        ch = ch - 'a' + 'A';
        return ch;
    }
    else
    {
        return ch;
    }
}

char my_to_lower(char ch)
{
    if (ch >= 'A' && ch <= 'Z')
    {
        ch = ch - 'A' + 'a';
        return ch;
    }
    else
    {
        return ch;
    }
}

int main()
{
    printf("Command\n1-check if the input is alphabet.\n2-check if the input is digit.\n3-Check if the input is upper case letter.\n4-Switch the input into upper case if it is lower case.\n5-Switch the input into lower case if it is upper case.\n6-Re-enter the input.\n7-To END THE PROGRAM.\n");
    char array[MAX];
    int command;
    printf("Enter an input: ");
    fgets(array, sizeof(array), stdin);

    while (1)
    {
        printf("Enter the command number: ");
        scanf("%d", &command);
        getchar();

        if (command == 1)
        {
            int i = 0;
            for (i; array[i] != '\0'; i++)
            {
                if (my_isalpha(array[i]))
                {
                    printf("%c is a letter.\n", array[i]);
                }
                if (!my_isalpha(array[i]))
                {
                    printf("%c is not a letter.\n", array[i]);
                }
            }
        }
        else if (command == 2)
        {
            int i = 0;
            for (i; array[i] != '\0'; i++)
            {
                if (my_isdigit(array[i]))
                {
                    printf("%c is a digit.\n", array[i]);
                }
                if (!my_isdigit(array[i]))
                {
                    printf("%c is not a digit.\n", array[i]);
                }
            }
        }
        else if (command == 3)
        {
            int i = 0;
            for (i; array[i] != '\0'; i++)
            {
                if (my_is_upper(array[i]))
                {
                    printf("%c is an Upper case letter.\n", array[i]);
                }
                if (!my_is_upper(array[i]))
                {
                    printf("%c is not an Upper case letter.\n", array[i]);
                }
            }
        }
        else if (command == 4)
        {
            int i = 0;
            for (i; array[i] != '\0'; i++)
            {
                printf("%c", my_to_upper(array[i]));
            }
        }
        else if (command == 5)
        {
            int i = 0;
            for (i; array[i] != '\0'; i++)
            {
                printf("%c", my_to_lower(array[i]));
            }
        }
        else if (command == 6)
        {
            printf("Re-enter the input: ");
            fgets(array, sizeof(array), stdin);
        }
        else if (command == 7)
        {
            printf("Program ENDS.\n");
            break;
        }
        else
        {
            printf("wrong command. Try agian.\n");
            printf("Enter the command number: ");
            scanf("%d", &command);
            getchar();
        }
    }
}