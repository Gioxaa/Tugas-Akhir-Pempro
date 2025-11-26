#include <stdio.h>
#include <stdlib.h>
#include "header/kamar.h"
#define jumlahKamar 10


#include <windows.h>
int main() {
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    kamar ruangan[10];

    int opsi; 

    for (int i=0; i<jumlahKamar; i++) {
        ruangan[i].nomor = i+1;
        ruangan[i].nama[0] = '\0';
        ruangan[i].statusBayar = 0;
        ruangan[i].statusKamar = 0;
    }

    do {
        printf("\n\n╔═══════════════════════════════════════════╗\n");
        printf("║        Selamat datang di aplikasi         ║\n");
        printf("║           Manajemen Kost!                 ║\n");
        printf("╠═══════════════════════════════════════════╣\n");
        printf("║ 1. Tambahkan Penghuni                     ║\n");
        printf("║ 2. Tampilkan Seluruh Data kamar           ║\n");
        printf("║ 3. Edit Data Kamar                        ║\n");
        printf("║ 4. Kosongkan Kamar                        ║\n");
        printf("║ 5. Cari Penghuni                          ║\n");
        printf("║ 6. Keluar                                 ║\n");
        printf("╚═══════════════════════════════════════════╝\n");
        printf("Silahkan pilih opsi diatas: ");
        scanf("%d", &opsi);



        switch (opsi)
        {
            case 1:
                tambah_penghuni(ruangan, jumlahKamar);
                break;
            case 2:
                tampilkan_kamar(ruangan, jumlahKamar);
                break;
            case 3:
                edit_kamar(ruangan, jumlahKamar);
                break;
            case 4:
                kosongkan_kamar(ruangan, jumlahKamar);
                break;
            case 5:
                cari_penghuni(ruangan, jumlahKamar);
                break;
            case 6:
                keluar();
                break;
            default:
                printf("Opsi tidak valid\n");
                break;
        }
    } while(opsi != 6);
    return 0;
}
