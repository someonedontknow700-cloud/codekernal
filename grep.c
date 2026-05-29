#include <stdio.h>
#include <string.h>

int main()
{
    char filename[100], pattern[100], temp[200];
    FILE *fp;

    printf("Enter file name: ");
    scanf("%s", filename);

    printf("Enter the pattern: ");
    scanf("%s", pattern);

    fp = fopen(filename, "r");

    if (fp == NULL)
    {
        printf("Error opening file.\n");
        return 1;
    }

    while (fgets(temp, sizeof(temp), fp) != NULL)
    {
        if (strstr(temp, pattern))
        {
            printf("%s", temp);
        }
    }

    fclose(fp);
    return 0;
}