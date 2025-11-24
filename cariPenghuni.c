#include <stdio.h>
#include "header/kamar.h"


int stringCompare(char str1[], char str2[]) {
    int i = 0;
    while (str1[i] == str2[i]) {
        if (str1[i] == '\0' || str2[i] == '\0') {
            break;
        }
        i++;
    }
    return str1[i] - str2[i];
}

void cari_penghuni(kamar ruangan[], int jumlah) {
    int i;
    char nama[100];
    
    printf("Masukkan Nama yang ingin dicari: ");
    scanf("%s", &nama);

    if(stringCompare(nama, ruangan[i].nama) == 0) {
        printf("Nama Penghuni: %s\n", ruangan[i].nama);
        printf("Nomor Kamar: %d\n", ruangan[i].nomor);
        printf("Status Bayar: %s\n", ruangan[i].statusBayar == 1 ? "Lunas" : "Belum Lunas");
        printf("Status Kamar: %s\n", ruangan[i].statusKamar == 1 ? "Terisi" : "Kosong");
    } else {
        printf("Pe--nghuni tidak ditemukan\n");
    }
}
