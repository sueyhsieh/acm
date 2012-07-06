//Ecological Bin Packing

#include <stdio.h>
#include <string.h>

int main() {
    int bin[3][3];
    int bin_color[6][3]={ {0, 1, 2}, {0, 2, 1}, {1, 0, 2}, {1, 2, 0}, {2, 0, 1}, {2, 1, 0}  };
    char bin_char[6][4]={"BCG","BGC","CBG","CGB","GBC","GCB"};
    int total_glass;
    int check = 0;
    int min_move, curr_move;
    int i, j;

    while (scanf("%d%d%d%d%d%d%d%d%d", &bin[0][0], &bin[0][2], &bin[0][1], &bin[1][0], &bin[1][2], &bin[1][1], &bin[2][0], &bin[2][2], &bin[2][1]) == 9) {
        total_glass = 0;

        for(i = 0; i < 3; i++) {
            for(j = 0; j < 3; j++) {
                total_glass += bin[i][j];
            }
        }

        min_move = total_glass;

        for(i = 0; i < 6; i++) {
            curr_move = total_glass;
            for(j = 0; j < 3; j++) {
                curr_move = curr_move - bin[j][bin_color[i][j]];
            }

            if(curr_move < min_move) {
                min_move = curr_move;
                check = i;
            }
        }

        printf("%s %d\n", bin_char[check], min_move);
    }

    return 0;
}
