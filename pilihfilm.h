#include "define.h"

const char *namafilm[jumlahfilm] = {
    "Avengers Endgame",
    "Wicked",
    "Pengabdi Setan"
};
const int studiofilm[jumlahfilm] = {1, 2, 3};
const char *jamfilm[jumlahfilm] = {"13.20", "14.50", "16.00"};

char labelkursi[totalbaris][totalkolom][panjangkode];
int status[jumlahfilm][totalbaris][totalkolom];

int pilih() {
    int pilihan;

    printf("\033[1;36m========================================\033[0m\n");
    printf("\033[1;33m|              PILIH FILM              |\033[0m\n");
    printf("\033[1;36m========================================\033[0m\n");

    for (int i = 0; i < jumlahfilm; i++) {
        printf("%d. %s (Studio %d) - %s\n", i + 1, namafilm[i], studiofilm[i], jamfilm[i]);
    }

    printf("\033[1;36m========================================\033[0m\n");
    printf("Pilih film (1-%d): ", jumlahfilm);
    if (scanf("%d", &pilihan) != 1) {
        printf("Input tidak valid!\n");
        while (getchar() != '\n');
        return -1;
    }
    if (pilihan < 1 || pilihan > jumlahfilm) {
        printf("Pilihan film tidak valid\n");
        return -1;
    }
    return pilihan - 1;
    printf("\033[1;36m========================================\033[0m\n");
}
