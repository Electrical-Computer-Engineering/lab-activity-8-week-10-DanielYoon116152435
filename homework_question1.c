#include <stdio.h>
#include <string.h>

#define MAX_WORDS 5
#define MAX_LENGTH 39

char *ToPigLatin(char *word)
{
    int length = strlen(word);
    int i;
    int Capital_Index;
    int First_Vowel = -1;
    char temp[MAX_LENGTH];

    if (word[0] >= 'A' && word[0] <= 'Z')
    {
        Capital_Index = 1; // check whether the first letter of the word starts with capital letter or not.
    }
    else
    {
        Capital_Index = 0;
    }

    for (i = 0; word[i] != '\0'; i++)
    { // finding vowels
        if (word[i] == 'a' || word[i] == 'e' || word[i] == 'i' || word[i] == 'o' || word[i] == 'u' || word[i] == 'A' || word[i] == 'E' || word[i] == 'I' || word[i] == 'O' || word[i] == 'U' || (word[i] == 'y' && i > 0) || (word[i] == 'Y' && i > 0))
        {
            First_Vowel = i;
            break;
        }
    }

    if (First_Vowel <= 0)
    {
        strcpy(temp, word);
        if (First_Vowel == 0)
        { // if starts with vowel
            strcat(temp, "way");
        }
        else
        { // if the word contains no vowel at all,
            strcat(temp, "ay");
        }
    }
    else
    { // if the word contains at least one vowel but not at start point,
        int j = 0;
        for (i = First_Vowel; word[i] != '\0'; i++, j++)
        { // from the point where the first vowel begins to the point of the word end stores into the temp.
            temp[j] = word[i];
        }
        for (i = 0; i < First_Vowel; i++, j++)
        { // rest of the characters of the word until i reaches to the point where the first vowel begins are stored into the temp.
            temp[j] = word[i];
        }
        // add 'ay' at the end of the word
        temp[j++] = 'a';
        temp[j++] = 'y';
        temp[j] = '\0'; // null-terminating
    }

    if (Capital_Index)
    { // If the word was captialized,
        if (temp[0] >= 'a' && temp[0] <= 'z')
        {
            temp[0] = temp[0] - 'a' + 'A'; // start letter of temp should be capitalized and
        }
        for (i = 1; temp[i] != '\0'; i++)
        { // the rest characters of temp should be lowercased.
            if (temp[i] >= 'A' && temp[i] <= 'Z')
            {
                temp[i] = temp[i] - 'A' + 'a';
            }
        }
    }

    strcpy(word, temp);
    return word;
}

int main()
{
    char words[MAX_WORDS][MAX_LENGTH]; // 5 words with each string length of 39.

    printf("Input 5 words: ");
    for (int i = 0; i < MAX_WORDS; ++i)
    {
        scanf("%s", words[i]); // each word entered will be stored for words[i] right after entering space. If my input is string Hamburger Rhythm queen zippitydoodah, then word[0] = "string", word[1] = "Hamburger",, and so on.
    }

    printf("Pig Latin version of the 5 words:\n");
    for (int i = 0; i < MAX_WORDS; ++i)
    {
        printf("%s ", ToPigLatin(words[i])); // Convert and print each word
    }
    printf("\n");
}
