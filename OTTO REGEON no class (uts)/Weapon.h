#include <iostream>
#include <stdlib.h>
using namespace std;

class Weapon{
    public:
        string nama;
        int harga;
        int atk;
};

void weapon_creation(){
    Weapon pb;
    pb.nama = "Pedang Besi";
    pb.harga = 0;
    pb.atk = 10;

    Weapon pbb;
    pbb.nama = "Pedang Besi Besar";
    pbb.harga = 1200;
    pbb.atk = 12;

    Weapon pbk;
    pbk.nama = "Pedang Besi Kecil";
    pbk.harga = 900;
    pbk.atk = 8;

    Weapon bk;
    bk.nama = "Busur Kayu";
    bk.harga = 1250;
    bk.atk = 13;

    Weapon tbk;
    tbk.nama = "Tombak kayu";
    tbk.harga = 800;
    tbk.atk = 10;

    Weapon ktl;
    ktl.nama = "Ketapel";
    ktl.harga = 1000;
    ktl.atk = 9;
    
}