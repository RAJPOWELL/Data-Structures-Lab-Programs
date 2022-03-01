#include <stdio.h>
#include <string.h>

char str[20], pat[20], rep[20];
int patCheck(char str[], char pat[]);
void replace(char str[], char pat[], char rep[], int start, int end);

void main()
{
    int end, start;
    printf("Enter the String \n");
    scanf("%s", &str);
check:
    printf("Enter  valid Pattern to Search \n");
    scanf("%s", &pat);
    end = patCheck(str, pat);
    if (end == 0)
    {
        printf("Pattern Doesn't Exist \n");
        goto check;
    }
    end--;
    start = end - strlen(pat) + 1;
    printf("Enter Replacing String \n");
    scanf("%s", &rep);
    replace(str, pat, rep, start, end);
    printf("The String after replacing the pattern is %s \n", str);
}

int patCheck(char str[], char pat[])
{
    int i = 0, count = 0;
    while (i < strlen(str))
    {
        if (count == strlen(pat))
            break;
        else if (str[i] == pat[count])
            count++;
        else
            count = 0;
        i++;
    }
    return (count > 0) ? i : 0;
}

void replace(char str[], char pat[], char rep[], int start, int end)
{
    int offset, i, temp = start;
    if (strlen(pat) < strlen(rep))
    {
        offset = strlen(rep) - strlen(pat) - 1;
        for (i = offset + strlen(str); i > end; i--)
            str[i] = str[i - 1];
        for (i = 0; i < strlen(rep); i++)
        {
            str[temp] = rep[i];
            temp++;
        }
    }
    else if (strlen(pat) > strlen(rep))
    {
        offset = strlen(pat) - strlen(rep) - 1;

        for (i = end - offset; i < strlen(str); i++)
            str[i] = str[i + offset + 1];
        for (i = 0; i < strlen(rep); i++)
        {
            str[temp] = rep[i];
            temp++;
        }
    }
    else
    {
        for (i = 0; i < strlen(rep); i++)
        {
            str[temp] = rep[i];
            temp++;
        }
    }
    return;
}