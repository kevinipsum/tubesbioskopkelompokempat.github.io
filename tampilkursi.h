#include "define.h"

void tampilkankursi(int indexfilm) {
    printf("\n== Kursi untuk film: %s (Studio %d, Jam %s) ==\n",
           namafilm[indexfilm], studiofilm[indexfilm], jamfilm[indexfilm]);
    for (int i = 0; i < totalbaris; i++) {
        printf("%c: ", 'A' + i);
        for (int j = 0; j < totalkolom; j++) {
            char buf[8];
            snprintf(buf, sizeof(buf), "%s[%c]", labelkursi[i][j], status[indexfilm][i][j] ? 'T' : 'K');
            printf("%-7s", buf);
        }
        printf("\n");
    }
}