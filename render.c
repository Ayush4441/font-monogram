#include <stdio.h>
#include <stdlib.h>

#include "font_monogram.h"

void usage(char *exec) {
    printf("Usage: %s <char_code>\n", exec);
    printf("\t\t<char_code> Decimal character code between 32 and 126\n");
}

void render(uint8_t *bitmap) {
    int x,y;
    int set;
    int mask;
    for (y = 0; y < FONT_MONOGRAM_HEIGHT; y++) {
        for (x = 0; x < FONT_MONOGRAM_WIDTH; x++) {
            set = bitmap[y] & 1 << x;
            printf("%c", set ? 'X' : ' ');
        }
        printf("\n");
    }
}

int main(int argc, char **argv) {
    int ord;
    if (argc != 2) {
        usage(argv[0]);
        return 1;
    }
    ord = atoi(argv[1]);
    if (ord > FONT_MONOGRAM_LAST_CHAR || ord < FONT_MONOGRAM_FIRST_CHAR) {
        usage(argv[0]);
        return 2;
    }
    uint8_t *bitmap = font_monogram[ord - FONT_MONOGRAM_FIRST_CHAR];

    render(bitmap);
    return 0;
}