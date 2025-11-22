#ifndef KAMAR_H
#define KAMAR_H
#include <stdbool.h>

typedef struct {
    int nomor;
    char nama[45];
    int statusBayar;
    int statusKamar;   
} kamar;

void tambah_penghuni(kamar ruangan[], int jumlah);
void tampilkan_kamar(kamar ruangan[], int jumlah);
void edit_kamar(kamar ruangan[], int jumlah);
void kosongkan_kamar(kamar ruangan[], int jumlah);
void cari_penghuni(kamar ruangan[], int jumlah);
void keluar();


#endif // KAMAR_H