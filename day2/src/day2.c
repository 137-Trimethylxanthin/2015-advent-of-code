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

static int min(int a, int b)
{
    return a < b ? a : b;
}

static void parse_into_arr(const char *content, int **arr)
{
    int count = 0;
    for (int i = 0; i < strlen(content); i++)
    {
        if (content[i] == '\n')
        {
            count++;
        }
    }
    *arr = (int *)malloc(count * sizeof(int));
    int index = 0;
    char *token = strtok(content, "\n");
    while (token != NULL)
    {
        // 12x34x45\n
        int l, w, h;
        sscanf(token, "%dx%dx%d", &l, &w, &h);
        l = l * w;
        w = w * h;
        h = h * l;

        int minimum = min(min(l, w), h);
        (*arr)[index] = ((2 * l) + (2 * w) + (2 * h)) + minimum;
        index++;
        token = strtok(NULL, "\n");
        }
    int total = 0;
    for (int i = 0; i < count; i++)
    {
        total += (*arr)[i];
    }
    printf("Total: %d\n", total);

}

int main(int argc, char const *argv[])
{
    char *content = NULL;
    read_content("input.txt", &content);
    if (content == NULL)
    {
        return 1;
    }

    int *arr = NULL;
    parse_into_arr(content, &arr);


    return 0;
}
