#include <stdio.h>
#include "header/kamar.h"

void tampilkan_kamar(kamar ruangan[], int jumlah) {
    int i;

    printf("+----------+----------------------+---------------+----------------+\n");
    printf("| No Kamar | Nama                 | Status Kamar  | Status Bayar   |\n");
    printf("+----------+----------------------+---------------+----------------+\n");

    for (i = 0; i < jumlah; i++) {
        int no = i + 1;
        const char *nama;
        const char *statusKamar;
        const char *statusBayar;

        if (ruangan[i].statusKamar == 0) {
            nama        = "-";
            statusKamar = "Kosong";
            statusBayar = "-";
        } else {
            if (ruangan[i].nama[0] == '\0') {
                nama = "-";
            } else {
                nama = ruangan[i].nama;
            }

            statusKamar = "Terisi";
            if (ruangan[i].statusBayar == 1) {
                statusBayar = "Lunas";
            } else {
                statusBayar = "Belum Lunas";
            }
        }

        printf("| %-8d | %-20s | %-13s | %-14s |\n", no, nama, statusKamar, statusBayar);
    }

    printf("+----------+----------------------+---------------+----------------+\n");
}