#include "define.h"

void simpanTiketDanBill(int indexfilm, char kodeKursi[][panjangkode], int jumlah, int bayar, int kembalian) {
    FILE *fp = fopen("tiket.txt", "a");
    if (!fp) {
        printf("Error membuka tiket.txt\n");
        return;
    }

    char tanggal[20];
    sekarangTanggal(tanggal, sizeof(tanggal));
    int totalHarga = jumlah * hargatiket;

    fprintf(fp, "==================== TIKET BIOSKOP ====================\n");
    fprintf(fp, "|| Film            : %-31s||\n", namafilm[indexfilm]);
    fprintf(fp, "|| Studio          : %-31d||\n", studiofilm[indexfilm]);
    fprintf(fp, "|| Jam             : %-31s||\n", jamfilm[indexfilm]);
    fprintf(fp, "|| Tanggal         : %-31s||\n", tanggal);
    fprintf(fp, "|| Jumlah Tiket    : %-31d||\n", jumlah);
    fprintf(fp, "|| Harga per Tiket : Rp %-28d||\n", hargatiket);
    fprintf(fp, "|| Total Harga     : Rp %-28d||\n", totalHarga);
    fprintf(fp, "|| Bayar           : Rp %-28d||\n", bayar);
    fprintf(fp, "|| Kembalian       : Rp %-28d||\n", kembalian);

    char kursiStr[maksbuffer];
    formatKursiRapi(kodeKursi, jumlah, kursiStr, sizeof(kursiStr));

    char *token = strtok(kursiStr, ",");
    int count = 0;
    fprintf(fp, "|| Kursi           : ");
    while (token) {
        while (*token == ' ') token++;
        fprintf(fp, "%s", token);
        count++;
        token = strtok(NULL, ",");
        if (token && count < 5) {
            fprintf(fp, ", ");
        } else {
            int padding = 35 - (count * 8);  
            if (padding < 0) padding = 0;
            for (int i = 0; i < padding; i++) fputc(' ', fp);
            fprintf(fp, "||\n");
            if (token) {
                fprintf(fp, " || %-16s: ", "");
            }
            count = 0;
        }
    }
    fprintf(fp, "=======================================================\n\n");
    fclose(fp);
}