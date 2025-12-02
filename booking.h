#include "define.h"

void bookingkursi(int indexfilm) {
    int jumlah;

    // ⬇️ DITAMBAHKAN: Perulangan sampai input jumlah tiket valid
    while (1) {
        printf("Masukkan jumlah tiket yang ingin dibeli (1-%d): ", makskursi);

        if (scanf("%d", &jumlah) != 1) {
            printf("Input tidak valid! Masukkan angka.\n");
            while (getchar() != '\n');
            continue;
        }

        if (jumlah < 1 || jumlah > makskursi) {
            printf("Jumlah tiket tidak valid! Harus 1-%d.\n", makskursi);
            continue;
        }

        break; // input benar → keluar loop
    }
    // ⬆️ HANYA BLOK INI YANG DITAMBAHKAN


    char kodeKursi[makskursi][panjangkode];
    int indices[makskursi][2];

    printf("Masukkan kode kursi (misal a1 c3 c4):\n");
    for (int i = 0; i < jumlah; i++) {
        while (1) {
            printf("Kursi %d: ", i + 1);

            if (scanf("%3s", kodeKursi[i]) != 1) {
                printf("Input tidak valid, coba lagi.\n");
                while (getchar() != '\n');
                continue;
            }

            toUppercase(kodeKursi[i]);

            int r, c;
            if (!kodeToIndex(kodeKursi[i], &r, &c)) {
                printf("Kode kursi %s invalid! Silakan masukkan ulang.\n", kodeKursi[i]);
                continue;
            }

            if (status[indexfilm][r][c] == 1) {
                printf("Kursi %s sudah terisi! Pilih kursi lain.\n", kodeKursi[i]);
                continue;
            }

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

    char konfir;
    while (1) {
        printf("\nKonfirmasi booking? (y/n): ");
        scanf(" %c", &konfir);
        konfir = tolower(konfir);

        if (konfir == 'y' || konfir == 'n')
            break;

        printf("Input tidak valid! Masukkan hanya 'y' atau 'n'.\n");
    }

    if (konfir == 'n') {
        printf("Booking dibatalkan.\n");
        return;
    }

    int totalHarga = jumlah * hargatiket;
    printf("Total harga: Rp %d\n", totalHarga);

    int bayar;
    while (1) {
        printf("Masukkan jumlah uang: Rp ");

        if (scanf("%d", &bayar) != 1) {
            printf("Input tidak valid! Masukkan angka.\n");
            while (getchar() != '\n');
            continue;
        }

        if (bayar < totalHarga) {
            printf("Uang tidak cukup! Total: Rp %d, Uang Anda: Rp %d\n", totalHarga, bayar);
            continue;
        }

        break;
    }

    int kembalian = bayar - totalHarga;

    for (int i = 0; i < jumlah; i++) {
        status[indexfilm][indices[i][0]][indices[i][1]] = 1;
    }

    simpanTiketDanBill(indexfilm, kodeKursi, jumlah, bayar, kembalian);

    printf("Booking BERHASIL. Tiket tersimpan di tiket.txt\nKembalian: Rp %d\n", kembalian);
}
