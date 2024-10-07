#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    FILE *file = fopen("input.txt", "r");
    if (file == NULL)
    {
        printf("File not found\n");
        return 1;
    }

    fseek(file, 0, SEEK_END);
    int length_of_file = ftell(file);
    fseek(file, 0, SEEK_SET);
    

    printf("Length of file: %d\n", length_of_file);
    int half = length_of_file / 2;
    int houses = 1;
    int x = 0, y = 0;

    //year 1
    int **already_visited = (int **)malloc(sizeof(int) * length_of_file);
    for (int i = 0; i < length_of_file; i++)
    {
        already_visited[i] = (int *)malloc(sizeof(int) * length_of_file);
    }

    //year 2
    int **already_visited_year2 = (int **)malloc(sizeof(int) * length_of_file);
    for (int i = 0; i < length_of_file; i++)
    {
        already_visited_year2[i] = (int *)malloc(sizeof(int) * length_of_file);
    }

    int current_turn = 0;
    int x_santa = 0, y_santa = 0;
    int x_robot = 0, y_robot = 0;
    int houses_year2 = 1;

    int c;

    already_visited[x + half][y + half] = 1;
    already_visited_year2[x_santa + half][y_santa + half] = 1;
    while ((c = fgetc(file)) != EOF)
    {

        int tempx = 0;
        int tempy = 0;
        switch (c)
        {
        case '^':
            tempy++;
            break;
        case 'v':
            tempy--;
            break;
        case '>':
            tempx++;
            break;
        case '<':
            tempx--;
            break;
        default:
            break;
        }
        

        x += tempx;
        y += tempy;

        if (already_visited[x + half][y + half] == 0)
        {
            houses++;
            already_visited[x + half][y + half] = 1;
        }

        if (current_turn == 0)
        {
            x_santa += tempx;
            y_santa += tempy;

            if (already_visited_year2[x_santa + half][y_santa + half] == 0)
            {
                houses_year2++;
                already_visited_year2[x_santa + half][y_santa + half] = 1;
            }
            current_turn = 1;
        }
        else
        {
            x_robot += tempx;
            y_robot += tempy;

            if (already_visited_year2[x_robot + half][y_robot + half] == 0)
            {
                houses_year2++;
                already_visited_year2[x_robot + half][y_robot + half] = 1;
            }
            current_turn = 0;
        }
    }

    printf("Houses (day 1): %d\n", houses);

    printf("Houses together (day 2): %d\n", houses_year2);    

    return 0;
}
