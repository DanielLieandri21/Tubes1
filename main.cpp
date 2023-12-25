#include "tubes1.h"
#include <iostream>

int main(int argc, const char * argv[]) {
    // inisialisasi
    listartis Lartis;
    listfilm Lfilm;

    // create list
    createList_Artis(Lartis);
    createList_Film(Lfilm);

    // input
    inputMLL(Lartis, Lfilm);

    // tambah data
    insertLast_Artis(Lartis, alokasi_Artis("Iqbaal Ramadhan", 1999));
    insertLast_Artis(Lartis, alokasi_Artis("Vanesha Prescilla", 1999));
    insertLast_Artis(Lartis, alokasi_Artis("Angga Yunanda", 2000));
    insertAfter_Film(Lfilm, alokasi_Film("Dilan 1990", 2018));
    insertAfter_Film(Lfilm, alokasi_Film("Mencuri Raden Saleh", 2022));
    insertAfter_Film(Lfilm, alokasi_Film("Mariposa", 2020));
    insertRelasi(Lartis, Lfilm, "Iqbaal Ramadhan", "Dilan 1990");
    insertRelasi(Lartis, Lfilm, "Iqbaal Ramadhan", "Mencuri Raden Saleh");
    insertRelasi(Lartis, Lfilm, "Vanesha Prescilla", "Dilan 1990");

    // fungsi show dan hapus
    showArtis(Lartis);
    showFilm(Lfilm);
    showFilmDanArtis(Lartis);
    showTOPartis(Lartis);
    showArtisBerdasarkanFilm(Lartis, Lfilm, "Dilan 1990");
    hapusFilmDanRelasiDariArtis(Lartis, Lfilm, "Dilan 1990");
    showFilmBerdasarkanArtis(Lartis, "Iqbaal Ramadhan");
    showFilmDanArtis(Lartis);
    addressartis Partis = cariArtis(Lartis, "Iqbaal Ramadhan");
    deleteFirst_Artis(Lartis, Partis);
    showFilmDanArtis(Lartis);

    return 0;
}
