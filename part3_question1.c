// Daniel Yoon 116152435
#include <stdio.h>

#define MAX 10

int main()
{
    char str[MAX];
    printf("Enter the input stirng (string consists of 10 characters): ");
    fgets(str, sizeof(str), stdin);

    int i = 0;
    while (str[0] != '\0') // loop breaks whenever the string is empty
    {
        i = 0;

        printf("%s\n", str);

        for (i = 0; str[i] != '\0'; i++)
        {
            str[i] = str[i + 1];
        }
        str[i] = '\0'; // null-terminating for after the last character.
    }
}
