#include "define.h"

void carikursikosong(int indexfilm) {
    printf("\n== Kursi kosong untuk film: %s ==\n", namafilm[indexfilm]);
    int adaKosong = 0;
    for (int i = 0; i < totalbaris; i++) {
        for (int j = 0; j < totalkolom; j++) {
            if (status[indexfilm][i][j] == 0) {
                printf("%s ", labelkursi[i][j]);
                adaKosong = 1;
            }
        }
        printf("\n");
    }
    if (!adaKosong) {
        printf("Tidak ada kursi kosong.\n");
    }
}