// Daniel Yoon 116152435
#include <stdio.h>
#include <string.h>

#define MAX 32

char *remove_match(char dest[], char str[])
{
    int length = strlen(dest);
    for (int i = 0; str[i] != '\0'; i++)
    {
        for (int j = 0; dest[j] != '\0'; j++)
        {
            if (str[i] == dest[j])
            {
                for (int k = j; k < length; k++)
                {
                    dest[k] = dest[k + 1];
                }
                length--; // decreasing length since length has decreased after shifting
                j--;      // adjusting j since shifted
            }
        }
    }

    return dest;
}

int main()
{

    char s1[MAX];
    char s2[MAX];

    printf("Enter the string: ");
    fgets(s1, sizeof(s1), stdin);

    printf("Enter the characters/ strings to remove: ");
    fgets(s2, sizeof(s2), stdin);

    remove_match(s1, s2);
    printf("%s", s1);
}
