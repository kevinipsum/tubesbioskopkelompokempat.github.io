// #include "define.h"

// void simpanStatusKeFile(int indexfilm) {
//     char filename[maksbuffer];
//     char safeName[50];
//     int k = 0;
//     for (size_t i = 0; namafilm[indexfilm][i] != '\0' && k < sizeof(safeName) - 1; i++) {
//         char c = namafilm[indexfilm][i];
//         if (c == ' ') safeName[k++] = '_';
//         else safeName[k++] = c;
//     }
//     safeName[k] = '\0';
//     snprintf(filename, sizeof(filename), "status_%s.txt", safeName);

//     FILE *fp = fopen(filename, "w");
//     if (!fp) {
//         printf("Error: Gagal membuka %s untuk menulis.\n", filename);
//         return;
//     }

//     fprintf(fp, "Status kursi untuk film: %s\n", namafilm[indexfilm]);
//     fprintf(fp, "Format: A1[K] = kosong, A1[T] = terisi\n\n");
//     for (int i = 0; i < totalbaris; i++) {
//         for (int j = 0; j < totalkolom; j++) {
//             char kursiStr[8];
//             snprintf(kursiStr, sizeof(kursiStr), "%s[%c]", labelkursi[i][j], status[indexfilm][i][j] ? 'T' : 'K');
//             fprintf(fp, "%-7s", kursiStr);
//         }
//         fprintf(fp, "\n");
//     }
//     fclose(fp);
//     printf("Status disimpan ke file: %s\n", filename);
// }