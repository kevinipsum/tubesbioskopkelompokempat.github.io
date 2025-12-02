#include <stdio.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
#include <stdlib.h>
#include "fitur.h"

int main() {
    initKursiLabel();
    memset(status, 0, sizeof(status));

    int menu;
    printf("=== PROGRAM BOOKING BIOSKOP ===\n");
    do {
        printf("\033[1;36m\n===========================================\n\033[0m");   // Cyan
printf("\033[1;33m|           MENU UTAMA BIOSKOP            |\033[0m\n");     // Yellow title
printf("\033[1;36m===========================================\033[0m\n");

printf("\033[1;32m| 1 |\033[0m Tampilkan kursi untuk sebuah film\n");
printf("\033[1;32m| 2 |\033[0m Cari kursi kosong\n");
printf("\033[1;32m| 3 |\033[0m Hitung jumlah kursi kosong\n");
printf("\033[1;32m| 4 |\033[0m Booking kursi\n");
printf("\033[1;31m| 0 |\033[0m Keluar\n");

printf("\033[1;36m===========================================\033[0m\n");
printf("Pilih menu: ");

        if (scanf("%d", &menu) != 1) {
            printf("Input tidak valid!\n");
            while (getchar() != '\n');
            menu = -1;
            continue;
        }

        int indexfilm;
        switch (menu) {
            case 1:
                indexfilm = pilih();
                if (indexfilm >= 0) tampilkankursi(indexfilm);
                break;
            case 2:
                indexfilm = pilih();
                if (indexfilm >= 0) carikursikosong(indexfilm);
                break;
            case 3:
                indexfilm = pilih();
                if (indexfilm >= 0) {
                    int total = hitungkursikosong(indexfilm);
                    printf("Total kursi kosong untuk '%s' = %d\n", namafilm[indexfilm], total);
                }
                break;
            case 4:
                indexfilm = pilih();
                if (indexfilm >= 0) bookingkursi(indexfilm);
                break;
            case 0:
                printf("Keluar...\n");
                break;
            default:
                printf("Pilihan tidak valid!\n");
        }
    } while (menu != 0);

    return 0;
}