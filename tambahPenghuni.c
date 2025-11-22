#include <stdio.h>
#include "header/kamar.h"

void tambah_penghuni(kamar ruangan[], int jumlah) {
    int noKamar;
    int index;
    int statusBayar;

    printf("Masukkan nomor kamar: ");
    scanf("%d", &noKamar);
    

    if (noKamar < 1 || noKamar > jumlah) {
        printf("\nNomor kamar tidak valid\n");
        return;
    }
    index = noKamar - 1;

    if (ruangan[index].statusKamar == 1) {
        printf("Kamar %d sudah terisi oleh %s.\n", noKamar, ruangan[index].nama);
        return;
    }

    printf("Masukkan Nama Penghuni: ");
    scanf("%44s", ruangan[index].nama);

    while(1) {
        printf("Masukkan status bayar(1 sudah / 0 belum): ");
        scanf("%d", &statusBayar);
        if (statusBayar == 1) {
            ruangan[index].statusBayar = 1;
            printf("Oke cuan!\n");
            break;
        } else if (statusBayar == 0) {
            ruangan[index].statusBayar = 0;
            printf("jangan lupa di tagih!\n");
            break;  
        } else {
            printf("Status bayar tidak valid, pilih antara 0 dan 1\n");
        }

    }

    ruangan[index].nomor       = noKamar;
    ruangan[index].statusKamar = 1;
}
