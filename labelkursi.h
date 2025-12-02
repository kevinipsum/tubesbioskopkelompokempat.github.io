#include "define.h"

void initKursiLabel() {
    char row = 'A';
    for (int i = 0; i < totalbaris; i++) {
        for (int j = 0; j < totalkolom; j++) {
            sprintf(labelkursi[i][j], "%c%d", row, j + 1);
        }
        row++;
    }
}