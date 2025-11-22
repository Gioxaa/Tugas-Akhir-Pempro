#include <stdio.h>
#include "header/kamar.h"

void tambah_penghuni(kamar ruangan[], int jumlah) {
    int noKamar;
    int index;
    int statusBayar;

    printf("Masukkan nomor kamar: ");
    scanf("%d", &noKamar);

    // validasi nomor
    if (noKamar < 1 || noKamar > jumlah) {
        printf("\nNomor kamar tidak valid\n");
        return;
    }

    // baru di sini hitung index
    index = noKamar - 1;

    // cek apakah kamar sudah terisi
    if (ruangan[index].statusKamar == 1) {
        printf("Kamar %d sudah terisi oleh %s.\n", noKamar, ruangan[index].nama);
        return;
    }

    printf("Masukkan Nama Penghuni: ");
    scanf("%44s", ruangan[index].nama);

    printf("Masukkan status bayar(1 sudah / 0 belum): ");
    scanf("%d", &statusBayar);

    if (statusBayar == 1) {
        ruangan[index].statusBayar = 1;
        printf("Oke cuan!\n");
    } else {
        ruangan[index].statusBayar = 0;
        printf("jangan lupa di tagih!\n");
    }

    ruangan[index].nomor       = noKamar;
    ruangan[index].statusKamar = 1;
}
