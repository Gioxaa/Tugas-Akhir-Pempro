#include <stdio.h>
#include "header/kamar.h"

int hapusKamar(kamar ruangan[], int jumlah, int i) {
    ruangan[i].nama[0] = '\0';
    ruangan[i].statusBayar = 0;
    ruangan[i].statusKamar = 0;
}


void kosongkan_kamar(kamar ruangan[], int jumlah) {
    int noKamar;
    int i;

    printf("Masukkan nomor kamar yang ingin di kosongkan: ");
    scanf("%d", &noKamar);

    if(noKamar < 1 || noKamar > jumlah) {
        printf("\nNomor kamar tidak valid\n");
        return;
    }

    i = noKamar - 1;
    if(ruangan[i].statusKamar == 0) {
        printf("\nKamar %d kosong\n", noKamar);
        return;
    }
    hapusKamar(ruangan, jumlah, i);
    printf("\nKamar %d berhasil di kosongkan\n", noKamar);
}
