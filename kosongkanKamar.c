#include <stdio.h>
#include "header/kamar.h"

void kosongkan_kamar(kamar ruangan[], int jumlah) {
    int i=0;
    int noKamar;
    int index;

    noKamar = index + 1;

    printf("Masukkan nomor kamar yang ingin di kosongkan: ");
    scanf("%d", &noKamar);

    if(noKamar < 1 || noKamar > jumlah) {
        printf("\nNomor kamar tidak valid\n");
        return;
    }

    index = noKamar - 1;
    if(ruangan[index].statusKamar == 0) {
        printf("\nKamar %d kosong\n", noKamar);
        return;
    }

    ruangan[index].nama[0] = '\0';
    ruangan[index].statusBayar = 0;
    ruangan[index].statusKamar = 0;
    printf("\nKamar %d berhasil di kosongkan\n", noKamar);

    
}
