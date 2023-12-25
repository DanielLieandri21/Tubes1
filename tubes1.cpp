#include "tubes1.h"
#include <iostream>

//create list
void createList_Artis(listartis &L){
    first(L) = NULL;
    last(L) = NULL;
}
void createList_Film(listfilm &L){
    first(L) = NULL;
}

// create elemen
addressartis alokasi_Artis(string nama, int tahun){
    addressartis P = new elmlist_artis;
    info(P).namaArtis = nama;
    info(P).tahun_Lahir = tahun;
    next(P) = NULL;
    prev(P) = NULL;
    return P;
}
addressfilm alokasi_Film(string nama, int tahun){
    addressfilm P = new elmlist_film;
    info(P).namaFilm = nama;
    info(P).tahun_Terbit = tahun;
    next(P) = NULL;
    return P;
}
addressrelasi createElm_Relasi(addressfilm Film){
    addressrelasi P = new elmlist_relasi;
    nextfilm(P) = Film;
    next(P) = NULL;
    return P;
}

//cari
addressartis cariArtis(listartis L, string cari){
    addressartis p = first(L);
    while (p != NULL) {
        if (cari == info(p).namaArtis){
            return  p;
        }
        p = next(p);
    }
    return NULL;
}
addressfilm cariFilm(listfilm L, string cari){
    addressfilm p = first(L);
    while (p != NULL) {
        if (cari == info(p).namaFilm){
            return p;
        }
        p = next(p);
    }
    return NULL;
}

//add
void insertLast_Artis(listartis &L, addressartis P){
    if (first(L) == NULL && last(L) == NULL){
        first(L) = P;
        last(L) = P;
    }else{
        next(P) = first(L);
        prev(P) = last(L);
        next(last(L)) = P;
        prev(first(L)) = P;
        last(L) = P;
    }
}
void insertAfter_Film(listfilm &L, addressfilm P){
    addressfilm Y;
    addressfilm Prec;
    if (first(L) == NULL){
        first(L) = P;
    }else{
        Prec = first(L);
        while (next(Prec) != Y){
            Prec = next(Prec);
        }
        next(P) = next(Prec);
        next(Prec) = P;
    }
}
void insertRelasi(listartis &LArtis, listfilm &LFilm, string artis, string film){
    addressartis Partis = cariArtis(LArtis, film);

    if (Partis == NULL){
        cout << "Aktor/Aktris tidak ditemukan. Pastikan input dengan benar" << endl;;
    } else {
        addressfilm Pfilm = cariFilm(LFilm, film);
        if (Partis == NULL){
            cout << "Film tidak ditemukan. Pastikan input dengan benar" << endl;
        } else {
            addressrelasi Prelasi = createElm_Relasi(Pfilm);
            if (nextRelasi(Partis) == NULL){
                nextRelasi(Partis) = Prelasi;
            } else {
                addressrelasi q = nextRelasi(Partis);
                while (next(q) != Nil){
                    q = next(q);
                }
                next(q) = Prelasi;
            }
        }
    }
}

// delete
void deleteRelasi(addressartis &artis, addressrelasi &p){
    if (p == NULL){
        cout << "Film tidak ditemukan. Pastikan input benar" << endl;
    } else if (p == nextRelasi(artis)){
        if (next(nextRelasi(artis)) == NULL){
            nextRelasi(artis) = NULL;
        } else {
            nextRelasi(artis) = next(p);
            next(p) = NULL;
        }
    } else {
        addressrelasi q = nextRelasi(artis);
        while (next(q) != p){
            q = next(q);
        }
        if (next(p) == Nil){
            next(q) = Nil;
        } else {
            next(q) = next(p);
            next(p) = Nil;
        }
    }
}
void deleteFirst_Artis(listartis &L, addressartis P){
    addressartis Q;
    if (first(L) == NULL && last(L) == NULL){
        cout << "List Kosong" << endl;
        P = NULL;
    }else if (next(first(L)) == last(L)){
        P = first(L);
        first(L) = NULL;
        last(L) = NULL;
        next(P) = NULL;
        prev(P) = NULL;
    }else{
        P = first(L);
        Q = first(L);
        while (next(Q) != first(L)){
            Q = next(Q);
        }
        next(Q) = next(P);
        first(L) = next(P);
        prev(first(L)) = last(L);
        next(P) = NULL;
        prev(P) = NULL;
    }
}
void deleteAfter_Film(listfilm &L, addressfilm P){
    addressfilm Q;
    addressfilm Prec;
    if (first(L) == NULL){
        cout << "List Kosong" << endl;
        P = NULL;
    }else if (next(first(L)) == NULL){
        P = first(L);
        first(L) = NULL;
    }else{
        P = first(L);
        while (next(P) != Q){
            Prec = P;
            P = next(P);
        }
        next(Prec) = Q;
        next(P) = NULL;
    }
}
void hapusFilmDanRelasiDariArtis(listartis &Lartis, listfilm &Lfilm, string film){
    addressfilm adrP = cariFilm(Lfilm, film);
    addressartis p = first(Lartis);
    addressrelasi q;
    while (p != NULL) {
        q = nextRelasi(p);
        while(q != NULL){
            if (info(nextfilm(q)).namaFilm == film){
                deleteRelasi(p, q);
            }
            q = next(q);
        }
        p = next(p);
    }
    deleteAfter_Film(Lfilm,adrP);
}

// show
void showArtis(listartis L){
    cout << "===================================" << endl;
    cout << "Daftar Artis :" << endl;
    addressartis p = first(L);
    while (p != NULL) {
        cout << "-----------------------------------" << endl;
        cout << "Nama Aktor/Aktris : " << info(p).namaArtis << endl;
        cout << "Tahun Lahir : " << info(p).tahun_Lahir << endl;
        p = next(p);
    }
    cout << "===================================" << endl << endl;
}
void showFilm(listfilm L){
    cout << "===================================" << endl;
    cout << "Daftar Film :" << endl;
    addressfilm p = first(L);
    while (p != NULL) {
        cout << "-----------------------------------" << endl;
        cout << "Judul Film : " << info(p).namaFilm << endl;
        cout << "Tahun Terbit : " << info(p).tahun_Terbit << endl;
        p = next(p);
    }
    cout << "===================================" << endl << endl;
}
void showFilmDanArtis(listartis L){
    cout << "===================================" << endl;
    cout << "Daftar Artis dan Film yang dimainkannya :" << endl;
    addressartis p = first(L);
    addressrelasi q;
    while (p != NULL) {
        cout << "-----------------------------------" << endl;
        cout << "Nama Aktor/Aktris : " << info(p).namaArtis << endl;
        cout << "Tahun Lahir : " << info(p).tahun_Lahir << endl;
        q = nextRelasi(p);
        if (q == NULL){
            cout << "Artis ini tidak memiliki Film yang dimainkan" << endl;
        } else {
            cout << "Film : " << endl;
            while(q != NULL){
                cout << "Judul Film : " << info(nextfilm(q)).namaFilm << endl;
                cout << "Tahun Terbit : " << info(nextfilm(q)).tahun_Terbit << endl;
                q = next(q);
            }
        }
        p = next(p);
    }
    cout << "===================================" << endl << endl;
}
void showFilmBerdasarkanArtis(listartis L, string artis){
    cout << "===================================" << endl;
    cout << "Film yang dimainkan" << endl <<"oleh " << artis << " adalah : " << endl;
    addressartis p = cariArtis(L, artis);
    addressrelasi q = nextRelasi(p);
    while(q != NULL){
        cout << "-----------------------------------" << endl;
        cout << "Judul Film : " << info(nextfilm(q)).namaFilm << endl;
        cout << "Tahun Terbit : " << info(nextfilm(q)).tahun_Terbit << endl;
        q = next(q);
    }
    cout << "===================================" << endl << endl;
}
void showArtisBerdasarkanFilm(listartis L, listfilm Lfilm, string film){
    addressfilm Pfilm = cariFilm(Lfilm, film);
    if (Pfilm == NULL){
        cout << "Film tidak ditemukan. Pastikan input dengan benar" << endl;;
    }else{
        cout << "===================================" << endl;
        addressartis p = first(L);
        addressrelasi q;
        cout << "Judul filmnya " << film << " adalah : " << endl;
        while (p != NULL) {
            q = nextRelasi(p);
            while(q != NULL){
                if (nextfilm(q) == Pfilm){
                    cout << "-----------------------------------" << endl;
                    cout << "Nama Aktor/Aktris : " << info(p).namaArtis << endl;
                    cout << "Tahun Lahir : " << info(p).tahun_Lahir << endl;
                }
                q = next(q);
            }
            p = next(p);
        }
        cout << "===================================" << endl << endl;
    }
}
void showTOPartis(listartis L){
    cout << "===================================" << endl;
    cout << "Daftar TOP Aktor/Aktris :" << endl;
    addressartis p = first(L);
    addressartis palingTOP = Nil;
    int FilmTerbanyak = 0;
    int tahunTerbanyak = 0;
    addressartis tidakTOP = Nil;
    int FilmTersedikit = 999999;
    addressrelasi q;
    while (p != NULL) {
        int FilmDimainkan = 0;
        int tahunTerbaruArtisbermain = 0;
        cout << "-----------------------------------" << endl;
        cout << "Nama Aktor/Aktris : " << info(p).namaArtis << endl;
        cout << "Tahun Lahir : " << info(p).tahun_Lahir << endl;
        q = nextRelasi(p);
        while(q != NULL){
            if(tahunTerbaruArtisbermain < info(nextfilm(q)).tahun_Terbit){
                tahunTerbaruArtisbermain = info(nextfilm(q)).tahun_Terbit;
            }
            q = next(q);
            FilmDimainkan++;
        }
        if (FilmTersedikit > FilmDimainkan && tahunTerbaruArtisbermain > 2018){
            tahunTerbanyak = tahunTerbaruArtisbermain;
            FilmTersedikit = FilmDimainkan;
            tidakTOP = p;
        }
        if (FilmTerbanyak < FilmDimainkan && tahunTerbaruArtisbermain > 2018){
            tahunTerbanyak = tahunTerbaruArtisbermain;
            FilmTerbanyak = FilmDimainkan;
            palingTOP = p;
        }
        cout << "Film yand dimainkan : " << FilmDimainkan << endl;
        p = next(p);
    }
    cout << "-----------------------------------" << endl;
    if(palingTOP == NULL && tidakTOP == NULL){
        cout << "TIdak ada Artis yang memainkan" << endl << "film dalam 5 tahun terakhir" << endl;
    } else {
        cout << "Artis paling TOP (dalam 5 tahun terakhir) : " << endl << info(palingTOP).namaArtis << " (" << FilmTerbanyak << " Film)" << endl << endl;
        cout << "Artis yang tidak TOP (dalam 5 tahun terakhir) : " << endl << info(tidakTOP).namaArtis << " (" << FilmTersedikit << " film)" << endl;
    }
    cout << "===================================" << endl << endl;
}

//input
void inputMLL(listartis &La, listfilm &Lf){
    addressartis Pa;
    addressfilm Pf;
    addressrelasi Pr;
    addressrelasi q;
    int input;
    printInput();
    cin >> input;
    while (input != 0) {
        string NamaArtis, judulFilm;
        int tahunLahir, tahunTerbit;
        cout << endl << endl;
        switch (input) {
            case 1:
                printHeader("Tambah Aktor/Aktris");
                cout << "Input Nama : ";
                cin >> NamaArtis;
                cout << "Input Tahun Lahir : ";
                cin >> tahunLahir;
                insertLast_Artis(La, alokasi_Artis(NamaArtis, tahunLahir));
                break;
            case 2:
                printHeader("Tambah Film");
                cout << "Input Judul Film : ";
                cin.ignore();
                getline(cin, judulFilm);
                cout << "Input Tahun Terbit Film : ";
                cin >> tahunTerbit;
                insertAfter_Film(Lf, alokasi_Film(judulFilm, tahunTerbit));
                break;
            case 3:
                printHeader("Tambah Relasi");
                cout << "Input Nama Aktor/Aktris: ";
                cin.ignore();
                getline(cin, NamaArtis);
                cout << "Input Judul Film : ";
                cin.ignore();
                getline(cin, judulFilm);
                insertRelasi(La, Lf, NamaArtis, judulFilm);
                break;
            case 4:
                printHeader("Hapus Aktor/Aktris");
                cout << "Input Nama Aktor/Aktris : ";
                cin.ignore();
                getline(cin, NamaArtis);
                Pa = cariArtis(La, NamaArtis);
                deleteFirst_Artis(La, Pa);
                break;
            case 5:
                printHeader("Hapus Film");
                cout << "Input Judul Film : ";
                cin.ignore();
                getline(cin, judulFilm);
                Pf = cariFilm(Lf, judulFilm);
                deleteAfter_Film(Lf, Pf);
                break;
            case 6:
                printHeader("Hapus Relasi");
                cout << "Input Nama Aktor/Aktris : ";
                cin >> NamaArtis;
                cout << "Input Judul Film : ";
                cin.ignore();
                getline(cin, judulFilm);
                Pa = cariArtis(La, NamaArtis);
                q = nextRelasi(Pa);
                while(q != NULL && info(nextfilm(q)).namaFilm == judulFilm){
                    q = next(q);
                }
                Pr = q;
                deleteRelasi(Pa, Pr);
                break;
            case 7:
                printHeader("Hapus Film dan Relasi dari Aktor/Aktris");
                cout << "Input Judul Film : ";
                cin.ignore();
                getline(cin, judulFilm);
                hapusFilmDanRelasiDariArtis(La, Lf, judulFilm);
                break;
            case 8:
                showArtis(La);
                break;
            case 9:
                showFilm(Lf);
                break;
            case 10:
                showFilmDanArtis(La);
                break;
            case 11:
                printHeader("Show Film yang dibintangi oleh Aktor/Aktris tertentu");
                cout << "Input Judul Film : ";
                cin.ignore();
                getline(cin, judulFilm);
                showFilmBerdasarkanArtis(La, judulFilm);
                break;
            case 12:
                printHeader("Show Aktor/Aktris yang membintangi Film tertentu");
                cout << "Input Nama Aktor/Aktris : ";
                cin.ignore();
                getline(cin, NamaArtis);
                showArtisBerdasarkanFilm(La, Lf, NamaArtis);
                break;
            case 13:
                showTOPartis(La);
                break;
        }
        balikInput();
        printInput();
        cin >> input;
    }
}
void printInput(){
    cout << "===================================" << endl;
    cout << "--------    Menu MULTI LINKED LIST   ------------" << endl;
    cout << "-----------------------------------" << endl;
    cout << "Add :" << endl;
    cout << "1. Add Aktor/Aktris" << endl;
    cout << "2. Add Film" << endl;
    cout << "3. Add Relasi" << endl;
    cout << "Hapus :" << endl;
    cout << "4. Hapus Aktor/Aktris" << endl;
    cout << "5. Hapus Film" << endl;
    cout << "6. Hapus Relasi" << endl;
    cout << "7. Hapus Film dan Relasi dari Aktor/Aktris" << endl;
    cout << "Show :" << endl;
    cout << "8. Show Aktor/Aktris" << endl;
    cout << "9. Show Film" << endl;
    cout << "10. Show Aktor/Aktris dan Film" << endl;
    cout << "11. Show Film yang dibintangi oleh Aktor/Aktris tertentu" << endl;
    cout << "12. Show Aktor/Aktris yang membintangi Film tertentu" << endl;
    cout << "13. Show Aktor/Aktris TOP" << endl;
    cout << "Exit :" << endl;
    cout << "0. Exit" << endl;
    cout << "-----------------------------------" << endl;
    cout << "===================================" << endl;
    cout << "Input : ";
}
void printHeader(string title){
    cout << "-----------------------------------" << endl;
    cout << title << endl;
    cout << "-----------------------------------" << endl;
}

void balikInput(){
    char y;
    cout << "Ketik apasaja untuk kembali ke menu ";
    cin >> y;
    cout << endl << endl;
}
