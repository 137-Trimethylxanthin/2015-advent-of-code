#include <stdio.h>
#include <stdlib.h>

int min_of_three(int a, int b, int c) {
    int min = a;
    if (b < min) min = b;
    if (c < min) min = c;
    return min;
}


int calculate_paper(int l, int w, int h) {
    int side1 = l * w;
    int side2 = w * h;
    int side3 = h * l;
    int smallest_side = min_of_three(side1, side2, side3);
    
    return 2 * (side1 + side2 + side3) + smallest_side;
}

int calculate_ribbon(int l, int w, int h) {
    int smallest_perimeter = min_of_three(2 * (l + w), 2 * (w + h), 2 * (h + l));
    int volume = l * w * h;

    return smallest_perimeter + volume;
}

int main() {
    FILE *file = fopen("input.txt", "r");
    if (file == NULL) {
        printf("Error opening file\n");
        return 1;
    }

    int l, w, h;
    int total_paper = 0;
    int total_ribbon = 0;

    while (fscanf(file, "%dx%dx%d", &l, &w, &h) == 3) {
        total_paper += calculate_paper(l, w, h);
        total_ribbon += calculate_ribbon(l, w, h);
    }

    fclose(file);

    printf("Total square feet of wrapping paper needed: %d\n", total_paper);
    printf("Total feet of ribbon needed: %d\n", total_ribbon);

    return 0;
}