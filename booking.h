#include "define.h"

void bookingkursi(int indexfilm) {
    int jumlah;
    printf("Masukkan jumlah tiket yang ingin dibeli (1-%d): ", makskursi);
    if (scanf("%d", &jumlah) != 1 || jumlah < 1 || jumlah > makskursi) {
        printf("Jumlah tiket tidak valid\n");
        while (getchar() != '\n');
        return;
    }

    char kodeKursi[makskursi][panjangkode];
    int indices[makskursi][2];

    printf("Masukkan kode kursi (misal a1 c3 c4):\n");
    for (int i = 0; i < jumlah; i++) {
        while (1) {  // LOOP VALIDASI KODE KURSI
            printf("Kursi %d: ", i + 1);

            if (scanf("%3s", kodeKursi[i]) != 1) {
                printf("Input tidak valid, coba lagi.\n");
                while (getchar() != '\n');
                continue;  // ulangi input kursi
            }

            toUppercase(kodeKursi[i]);

            int r, c;
            if (!kodeToIndex(kodeKursi[i], &r, &c)) {
                printf("Kode kursi %s invalid! Silakan masukkan ulang.\n", kodeKursi[i]);
                continue;  // ulangi input
            }

            if (status[indexfilm][r][c] == 1) {
                printf("Kursi %s sudah terisi! Silakan pilih kursi lain.\n", kodeKursi[i]);
                continue;  // ulangi input
            }

            // VALID → SIMPAN INDEX
            indices[i][0] = r;
            indices[i][1] = c;
            break;
        }
    }

    printf("Kursi dipilih: ");
    for (int i = 0; i < jumlah; i++) {
        printf("%s", kodeKursi[i]);
        if (i < jumlah - 1) printf(", ");
    }

    printf("\nKonfirmasi booking? (y/n): ");
    char konfir;
    scanf(" %c", &konfir);
    if (tolower(konfir) != 'y') {
        printf("Booking dibatalkan\n");
        return;
    }

    int totalHarga = jumlah * hargatiket;
    printf("Total harga: Rp %d\n", totalHarga);
    printf("Masukkan jumlah uang: Rp ");
    int bayar;
    if (scanf("%d", &bayar) != 1 || bayar < totalHarga) {
        printf("Uang tidak cukup\n");
        while (getchar() != '\n');
        return;
    }

    int kembalian = bayar - totalHarga;

    for (int i = 0; i < jumlah; i++) {
        status[indexfilm][indices[i][0]][indices[i][1]] = 1;
    }

    simpanTiketDanBill(indexfilm, kodeKursi, jumlah, bayar, kembalian);

    printf("Booking BERHASIL. Tiket tersimpan di tiket.txt\nKembalian: Rp %d\n", kembalian);
}
