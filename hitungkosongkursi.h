#include "define.h"

int hitungkursi(int indexfilm, int row, int col) {
    if (row >= totalbaris) return 0;
    if (col >= totalkolom) return hitungkursi(indexfilm, row + 1, 0);
    int count = (status[indexfilm][row][col] == 0) ? 1 : 0;
    return count + hitungkursi(indexfilm, row, col + 1);
}

int hitungkursikosong(int indexfilm) {
    return hitungkursi(indexfilm, 0, 0);
}