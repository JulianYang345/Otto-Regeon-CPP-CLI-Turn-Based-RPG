#include <iostream>
#include <stdlib.h>
using namespace std;

string choice;

void title_screen(){

    cout << "|---------------------------------------|" << endl;
    cout << "|   ###  ##### #####  ###               |" << endl;
    cout << "|  #   #   #     #   #   #              |" << endl;
    cout << "|  #   #   #     #   #   #              |" << endl;
    cout << "|  #   #   #     #   #   #              |" << endl;
    cout << "|   ###    #     #    ###               |" << endl;
    cout << "|                                       |" << endl;
    cout << "|  ####  #####  ###  #####  ###  #   #  |" << endl;
    cout << "|  #   # #     #     #     #   # ##  #  |" << endl;
    cout << "|  ###   ##### # ### ##### #   # # # #  |" << endl;
    cout << "|  #  #  #     #   # #     #   # #  ##  |" << endl;
    cout << "|  #   # #####  ###  #####  ###  #   #  |" << endl;
    cout << "|---------------------------------------|" << endl;
    cout << "|                                       |" << endl;
    cout << "|              1. New Game              |" << endl;
    cout << "|              2. Load Game             |" << endl;
    cout << "|              3. exit                  |" << endl;
    cout << "|                                       |" << endl;    
    cout << "|---------------------------------------|" << endl;
    cout << "Choice? ";
    cin >> choice;
    system("cls");
}

void town_screen(){
    cout << "|---------------------------------------|" <<endl;
    cout << "|                                       |" <<endl;
    cout << "|                                       |" <<endl;
    cout << "|                                       |" <<endl;
    cout << "|                                       |" <<endl;
    cout << "|                                       |" <<endl;
    cout << "|                                       |" <<endl;
    cout << "|            1. Lanjut Story            |" <<endl;
    cout << "|            2. Training                |" <<endl;
    cout << "|            3. Blacksmith              |" <<endl;
    cout << "|            4. See Stats               |" <<endl;
    cout << "|            5. Save Game               |" <<endl;
    cout << "|            6. Exit                    |" <<endl;
    cout << "|                                       |" <<endl;
    cout << "|                                       |" <<endl;
    cout << "|                                       |" <<endl;
    cout << "|                                       |" <<endl;
    cout << "|                                       |" <<endl;
    cout << "|---------------------------------------|" <<endl;
    cout << "Choice? ";
    cin >> choice;
    system("cls");
}

void battle_screen_base(){
    cout << "|---------------------------------------|" <<endl;
    cout << "|Enemy(name)                            |" <<endl;
    cout << "|Hp:100                                 |" <<endl;
    cout << "|MP:100                                 |" <<endl;
    cout << "|                                       |" <<endl;
    cout << "|                                       |" <<endl;
    cout << "|                                       |" <<endl;
    cout << "|                                       |" <<endl;
    cout << "|Otto:                                  |" <<endl;
    cout << "|Hp:100                                 |" <<endl;
    cout << "|Mp:100                                 |" <<endl;
    cout << "|---------------------------------------|" <<endl;
    cout << "|                                       |" <<endl;
    cout << "| 1. Attack      3. Skill     5. Run    |" <<endl;
    cout << "|                                       |" <<endl;
    cout << "| 2. Defends     4. Item      6. Dodge  |" <<endl;
    cout << "|                                       |" <<endl;
    cout << "|---------------------------------------|" <<endl;
    cout << "Choice? ";
    cin >> choice;
}

void Training_screen(){
    cout << "|---------------------------------------|" <<endl;
    cout << "|                                       |" <<endl;
    cout << "|                                       |" <<endl;
    cout << "|                                       |" <<endl;
    cout << "|                                       |" <<endl;
    cout << "|                                       |" <<endl;
    cout << "|                                       |" <<endl;
    cout << "|            1. Wild Wolf (lvl 1)       |" <<endl;
    cout << "|            2. Goblin (lvl 5)          |" <<endl;
    cout << "|            3. Kobolt (lvl 8)          |" <<endl;
    cout << "|            4. Orc (lvl 15)            |" <<endl;
    cout << "|            5. Dark knight (lvl 25)    |" <<endl;
    cout << "|            0. Exit                    |" <<endl;
    cout << "|                                       |" <<endl;
    cout << "|                                       |" <<endl;
    cout << "|                                       |" <<endl;
    cout << "|                                       |" <<endl;
    cout << "|                                       |" <<endl;
    cout << "|---------------------------------------|" <<endl;
    cout << "Choice? ";
    cin >> choice;
    system("cls");
}