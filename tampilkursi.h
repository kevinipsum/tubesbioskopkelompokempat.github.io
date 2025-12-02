#include "define.h"

void tampilkankursi(int indexfilm) {
    printf("\n== Kursi untuk film: %s (Studio %d, Jam %s) ==\n",
           namafilm[indexfilm], studiofilm[indexfilm], jamfilm[indexfilm]);

    for (int i = 0; i < totalbaris; i++) {
        printf("%c: ", 'A' + i);

        for (int j = 0; j < totalkolom; j++) {
            char statusChar = status[indexfilm][i][j] ? 'T' : 'K';

            const char *warna =
                (statusChar == 'K') ? "\033[1;32m" : "\033[1;31m";  
                
            printf("%s%s[%c]\033[0m  ",
                   labelkursi[i][j],
                   warna,
                   statusChar);
        }
        printf("\n");
    }
}
