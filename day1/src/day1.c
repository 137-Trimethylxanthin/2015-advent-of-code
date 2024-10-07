#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static void read_content(const char *filename, char **content)
{
    FILE *file = fopen(filename, "r");
    if (file == NULL)
    {
        printf("File not found\n");
        *content = NULL;
        return;
    }
    fseek(file, 0, SEEK_END);
    long length = ftell(file);
    fseek(file, 0, SEEK_SET);
    printf("Length: %ld\n", length);
    *content = (char *)malloc((length + 1) * sizeof(char));
    fread(*content, 1, length, file);
    (*content)[length] = '\0'; // Add null terminator
    fclose(file);
}

int main(int argc, const char *argv[])
{
    char *content = NULL;
    read_content("input.txt", &content);
    if (content != NULL)
    {
        printf("%s\n", content);
        free(content); // Free allocated memory
    }

    int *floor = (int *)malloc(sizeof(int));
    *floor = 0;

    for (int i = 0; i < strlen(content); i++)
    {
        if (content[i] == '(')
        {
            (*floor)++;
        }
        else if (content[i] == ')')
        {
            (*floor)--;
        }
        if (*floor == -1)
        {
            printf("Basement: %d\n", i + 1);
        }
    }

    printf("Floor: %d\n", *floor);


    return 0;
}