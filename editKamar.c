#include <stdio.h>
#include "header/kamar.h"

void edit_kamar(kamar ruangan[], int jumlah) {
    int noKamar;
    int index;
    int pilihan;
    
    printf("Kamar nomor berapa yang mau diedit?: ");
    scanf("%d", &noKamar);
    
    if (noKamar < 1 || noKamar > jumlah) {
        printf("\nNomor kamar tidak valid\n");
        return;
    }
    
    index = noKamar - 1;
    if(ruangan[index].statusKamar == 0) {
        printf("\nKamar %d kosong\n", noKamar);
        return;
    }

    printf("Data Kamar Saat ini: \n");
    printf("Nama\t\t: %s\n", ruangan[index].nama);
    printf("Status Bayar\t: %s\n", ruangan[index].statusBayar == 1 ? "Lunas" : "Belum Lunas");

    printf("Pilih yang ingin diubah\n");
    printf("1. Nama Penghuni \n");
    printf("2. Status Bayar \n");
    printf("Pilih: ");
    scanf("%d", &pilihan);

    switch(pilihan) {
        case 1:
            printf("\nMasukkan nama penghuni baru: ");
            scanf("%s", &ruangan[index].nama);
            while(1) {
                printf("Masukkan status bayar(1 sudah / 0 belum): ");
                scanf("%d", &ruangan[index].statusBayar);
    
                if(ruangan[index].statusBayar == 1) {
                    ruangan[index].statusBayar = 1;
                    printf("Oke cuan!\n");
                    break;
                } else if (ruangan[index].statusBayar == 0) {
                    ruangan[index].statusBayar = 0;
                    printf("jangan lupa di tagih!\n");
                    break;
                } else {
                    printf("Status bayar tidak valid, pilih antara 0 dan 1\n");
                }
            }
            return;

        case 2:
            while(1) {
                printf("Masukkan status bayar(1 sudah / 0 belum): ");
                scanf("%d", &ruangan[index].statusBayar);
                if(ruangan[index].statusBayar == 1) {
                    ruangan[index].statusBayar = 1;
                    printf("Oke cuan!\n");
                    break;
                } else if (ruangan[index].statusBayar == 0) {
                    ruangan[index].statusBayar = 0;
                    printf("jangan lupa di tagih!\n");
                    break;
                } else {
                    printf("Status bayar tidak valid, pilih antara 0 dan 1\n");
                }
            }
            return;
    }
}
