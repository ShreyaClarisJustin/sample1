#include <stdio.h>
int StringLength(char *s)
{
    int l = 0;
    while (*s != '\0')
    {
        l++;
        s++;
    }
    return l;
}
void StringCopy(char *s1, char *s2)
{
    while (*s1 != '\0')
    {
        *s2 = *s1;
        s1++;
        s2++;
    }
    *s2 = '\0';
}
int StringCompare(char *s1, char *s2)
{
    while (*s1 != '\0' && *s2 != '\0')
    {
        if (*s1 != *s2)
        {
            return *s1 - *s2;
        }
        s1++;
        s2++;
    }
    return *s1 - *s2;
}
void StringConcat(char *s1, char *s2)
{
    while (*s1 != '\0')
    {
        s1++;
    }
    while (*s2 != '\0')
    {
        *s1 = *s2;
        s1++;
        s2++;
    }
    *s1 = '\0';
}
int main()
{
    int n;
    char ch;

printf("Menu:\n1-String length\n2-String copy\n3-String comparison\n4-String concatenation\n");
do
{
        printf("Enter your choice:");
        scanf("%d", &n);
        switch (n)
        {
        case 1:
        {
            char s[50];
            printf("Enter string: ");
            scanf("%s", s);
            printf("Length of string: %d\n", StringLength(s));
            break;
        }
        case 2:
        {
            char s1[50], s2[50];
            printf("Enter string: ");
            scanf("%s", s1);
            StringCopy(s1, s2);
            printf("Copied string: %s\n", s2);
            break;
        }
        case 3:
        {
            char s1[50], s2[50];
            printf("Enter string 1: ");
            scanf("%s", s1);
            printf("Enter string 2: ");
            scanf("%s", s2);
            int comp = StringCompare(s1, s2);
            if (comp == 0)
            {
                printf("Both strings are equal\n");
            }
            else
            {
                printf("Strings are not equal\n");
            }
            break;
        }
        case 4:
        {
            char s1[50], s2[50];
            printf("Enter string 1: ");
            scanf("%s", s1);
            printf("Enter string 2: ");
            scanf("%s", s2);
            StringConcat(s1, s2);
            printf("Concatenated string: %s\n", s1);

            break;
        }
        default:
            printf("Invalid");
        }
        printf("Do you want to continue? (y/n) ");
        scanf(" %c", &ch);
}
while(ch == 'y');
return 0;
}