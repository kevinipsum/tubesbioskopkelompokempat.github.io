#include "define.h"

int kodeToIndex(const char *kode, int *row, int *col) {
    size_t len = strlen(kode);
    if (len < 2 || len > 3) return 0;
    char r = toupper(kode[0]);
    if (r < 'A' || r >= 'A' + totalbaris) return 0;
    int c = atoi(&kode[1]);
    if (c < 1 || c > totalkolom) return 0;
    *row = r - 'A';
    *col = c - 1;
    return 1;
}

void toUppercase(char *str) {
    for (; *str; ++str) *str = toupper(*str);
}

void sekarangTanggal(char *buffer, size_t size) {
    time_t t = time(NULL);
    struct tm *tm = localtime(&t);
    snprintf(buffer, size, "%02d-%02d-%04d", tm->tm_mday, tm->tm_mon + 1, tm->tm_year + 1900);
}

typedef struct {
    char row;
    int start, end;
} SeatGroup;

void formatKursiRapi(char kodeKursi[][panjangkode], int jumlah, char *outBuff, size_t buffSize) {
    SeatGroup groups[makskursi];
    int groupCount = 0;

    for (int i = 0; i < jumlah - 1; i++) {
        for (int j = 0; j < jumlah - 1 - i; j++) {
            if ((kodeKursi[j][0] > kodeKursi[j + 1][0]) ||
                (kodeKursi[j][0] == kodeKursi[j + 1][0] && atoi(&kodeKursi[j][1]) > atoi(&kodeKursi[j + 1][1]))) {
                char tmp[panjangkode];
                strcpy(tmp, kodeKursi[j]);
                strcpy(kodeKursi[j], kodeKursi[j + 1]);
                strcpy(kodeKursi[j + 1], tmp);
            }
        }
    }

    groups[0].row = kodeKursi[0][0];
    groups[0].start = groups[0].end = atoi(&kodeKursi[0][1]);
    groupCount = 1;

    for (int i = 1; i < jumlah; i++) {
        char cRow = kodeKursi[i][0];
        int cSeat = atoi(&kodeKursi[i][1]);
        SeatGroup *last = &groups[groupCount - 1];

        if (cRow == last->row && cSeat == last->end + 1) {
            last->end = cSeat;
        } else {
            groups[groupCount].row = cRow;
            groups[groupCount].start = groups[groupCount].end = cSeat;
            groupCount++;
        }
    }

    outBuff[0] = 0;
    for (int i = 0; i < groupCount; i++) {
        char temp[20];
        if (groups[i].start == groups[i].end)
            snprintf(temp, sizeof(temp), "%c%d", groups[i].row, groups[i].start);
        else
            snprintf(temp, sizeof(temp), "%c%d-%c%d", groups[i].row, groups[i].start, groups[i].row, groups[i].end);
        if (i > 0) strncat(outBuff, ", ", buffSize - strlen(outBuff) - 1);
        strncat(outBuff, temp, buffSize - strlen(outBuff) - 1);
    }
}
