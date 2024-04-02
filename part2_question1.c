// Dnaiel Yoon 116152435

#include <stdio.h>
#define MAX 32

int my_strcmp(char str1[], char str2[])
{
    int i = 0;
    while (str1[i] != '\0' && str2[i] != '\0')
    {
        if (str1[i] == str2[i])
        {
            i++;
        }
        else
        {
            i = 0;
            break;
        }
    }
    if (i != 0)
        return 1;
    if (i == 0)
        return 0;
}

int my_strncmp(char str1[], char str2[], int n)
{
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (str1[i] == str2[i])
        {
            count++;
        }
        else
        {
            return 1;
        }
    }
    if (count == n)
        return 0;
}

char *my_strcpy(char dest[], char src[])
{
    int i = 0;
    while (src[i] != '\0')
    {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0'; // null terminating
    return dest;
}

char *my_strcat(char dest[], char src[])
{
    int i = 0;
    while (dest[i] != '\0')
    {
        i++;
    }
    
    int j;
    for (j = 0; src[j] != '\0'; j++)
    {
        dest[i] = src[j];
        i++;
    }

    dest[i] = '\0'; // null-terminating
    printf("in concar %s", dest);
    return dest;
}

char *my_reverse(char dest[], char src[])
{
    int i = 0;
    while (src[i] != '\0')
    {
        i++;
    }
    int k = 0;
    for (int j = i - 1; j >= 0; j--)
    {
        dest[k++] = src[j];
    }
    dest[k] = '\0';
    return dest;
}

int main()
{
    printf("Command\n1-Check if both inputs are equal.\n2-Check if first n characters of both inputs are equal.\n3-Copies the second string into the first string.\n4-Append the second string at the end of the first string.\n5-Stores the reversed second string into the first string.\n6-To END THE PROGRAM.\n");
    char str1[MAX];
    char str2[MAX];
    int command;
    printf("Enter inputs.\n");
    printf("The first string: ");
    fgets(str1, sizeof(str1), stdin);

    printf("The second string: ");
    fgets(str2, sizeof(str2), stdin);

    while (1)
    {
        printf("Enter the command number: ");
        scanf("%d", &command);
        getchar();
        int n = 0;

        if (command == 1)
        {
            if (!my_strcmp(str1, str2))
            {
                printf("Two strings are equal as "
                       "%s"
                       "\n",
                       str1);
            }
            else if (my_strcmp(str1, str2))
            {
                printf("Two strings are different.\n");
            }
        }
        else if (command == 2)
        {
            printf("Enter the first (n) characters to compare: ");
            scanf("%d", &n);
            getchar();

            if (!my_strncmp(str1, str2, n))
            {
                printf("The first %d characters of both strings are the same.\n", n);
            }
            else if (my_strncmp(str1, str2, n))
            {
                printf("The first %d characters of both strings are not the same.\n", n);
            }
        }
        else if (command == 3)
        {
            printf("Updated string1:\n");
            printf("%s\n", my_strcpy(str1, str2));
        }
        else if (command == 4)
        {
            printf("Updated string1:\n");
            my_strcat(str1, str2);
            printf("%s", str1);
        }
        else if (command == 5)
        {
            printf("Updated string1:\n");
            my_reverse(str1, str2);
            printf("%s", str1);
        }
        else if (command == 6)
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