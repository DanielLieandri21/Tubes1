#ifndef TUBES1_H_INCLUDED
#define TUBES1_H_INCLUDED

#include <iostream>
#include <stdio.h>
#define Nil NULL
#define info(P) (P)->info
#define next(P) (P)->next
#define nextfilm(P) (P)->nextfilm
#define prev(P) (P)->prev
#define nextRelasi(P) (P)->nextRelasi
#define first(L) ((L).first)
#define last(L) ((L).last)
using namespace std;

//typedef address
typedef struct elmlist_artis *addressartis;
typedef struct elmlist_film *addressfilm;
typedef struct elmlist_relasi *addressrelasi;
// tipe bentukan
struct artis{
    string namaArtis;
    int tahun_Lahir;
};
struct film{
    string namaFilm;
    int tahun_Terbit;
};
//typedef infotype
typedef struct artis infotypeartis;
typedef struct film infotypefilm;
//elemen
struct elmlist_artis {
    infotypeartis info;
    addressartis next;
    addressartis prev;
    addressrelasi nextRelasi;
};
struct elmlist_film {
    infotypefilm info;
    addressfilm next;
};
struct elmlist_relasi {
    addressrelasi next;
    addressfilm nextfilm;
};
// list
struct listartis{
    addressartis first;
    addressartis last;
};
struct listfilm{
    addressfilm first;
};
//create list
void createList_Artis(listartis &L);
void createList_Film(listfilm &L);
// create elemen
addressartis alokasi_Artis(string nama, int tahun);
addressfilm alokasi_Film(string nama, int tahun);
addressrelasi createElm_Relasi(addressfilm Film);
//cari
addressartis cariArtis(listartis L, string cari);
addressfilm cariFilm(listfilm L, string cari);
// add
void insertLast_Artis(listartis &L, addressartis P);
void insertAfter_Film(listfilm &L, addressfilm P);
void insertRelasi(listartis &LArtis, listfilm &LFilm, string artis, string film);
//delete
void deleteRelasi(addressartis &artis, addressrelasi &p);
void deleteFirst_Artis(listartis &L, addressartis P);
void deleteAfter_Film(listfilm &L, addressfilm P);
void hapusFilmDanRelasiDariArtis(listartis &Lartis, listfilm &Lfilm, string film);
//show
void showArtis(listartis L);
void showFilm(listfilm L);
void showFilmDanArtis(listartis L);
void showFilmBerdasarkanArtis(listartis L, string artis);
void showArtisBerdasarkanFilm(listartis L, listfilm Lfilm, string film);
void showTOPartis(listartis L);
//input
void printInput();
void printHeader(string title);
void balikInput();
void inputMLL(listartis &La, listfilm &Lf);
#endif

