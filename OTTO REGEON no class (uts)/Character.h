#include <iostream>
#include <stdlib.h>
using namespace std;

int choice;

class Char{
    public:
        string nama;
        int hp;
        int maxhp;
        int atk;
        int watk;
        int def;
        int money;
        int lvl;
        int exp;
    
};

void char_creation(){
    Char otto;
    otto.hp = 100;
    otto.maxhp = 100;
    otto.atk = 10;
    otto.watk = 20;
    otto.def = 5;
    otto.money = 0;
    otto.lvl = 1;
    otto.exp = 0;

    Char serigala;
    serigala.nama = "Serigala";
    serigala.hp = 50;
    serigala.maxhp = 50;
    serigala.atk = 10;
    serigala.def = 5;
    serigala.money = 0;
    serigala.lvl = 1;
    serigala.exp = 50;
}