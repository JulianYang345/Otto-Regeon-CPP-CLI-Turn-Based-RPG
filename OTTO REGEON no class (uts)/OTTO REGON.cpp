#include <iostream>
#include <stdlib.h>
#include <fstream>
#include "Screen.cpp"
#include "Story.cpp"
using namespace std;

//Variable declaration
bool battle;
bool game;
bool town;
bool blacksmith;
char start;
int cost = 50;
int turn;
int i;

//Character defining
//parameter: hp/maxhp/mp/maxmp/atk/def/money/lvl/exp
float Character [7][9] = {{100,100,50,50,20,10,0,1,0}, //Otto
                        {50,50,30,30,20,10,10,1,50}, //Wild wolf
                        {150,150,45,45,40,20,50,5,150}, //Goblin
                        {200,200,60,60,75,30,100,8,250}, // Kobolt
                        {1000,1000,40,40,60,40,400,15,500}, // orc
                        {500,500,60,60,125,120,1000,25,1500}, // Dark Knight
                        {1500,1500,80,80,150,135,5000,35,5000} // Hitachi
                        };

//Character name
string Character_name [7] = {"Otto", "Wild Wolf", "Goblin", "Kobolt", "Orc", "Dark Knight", "Hitachi"};

// Save //lauren
int SaveGame(){    
    ofstream savefile ("ottosavedgame.txt");
    if(! savefile){
        cout << "Sorry: there was a problem, and I couldn't save your game!" << endl;
        return -1;
    }
    savefile << Character[0][0] << "\n"             
             << Character[0][1] << "\n"             
             << Character[0][2] << "\n"
             << Character[0][3] << "\n"
             << Character[0][4] << "\n"
             << Character[0][5] << "\n"
             << Character[0][6] << "\n"
             << Character[0][7] << "\n"
             << Character[0][8] << "\n"
             << cost << "\n"
             << counter << endl;
    savefile.close();
    return 0;
}

// Load //lauren
int LoadGame(){
    ifstream loadfile("ottosavedgame.txt");
    if(!loadfile){
        cout << "Error! Cannot load game." << endl;
        return -1;
    }

    string temporaryString;

    getline(loadfile, temporaryString);
        Character[0][0] = atof(temporaryString.c_str());

    getline(loadfile, temporaryString);
        Character[0][1] = atof(temporaryString.c_str());
         
    getline(loadfile, temporaryString);
        Character[0][2] = atof(temporaryString.c_str());

    getline(loadfile, temporaryString);
        Character[0][3] = atof(temporaryString.c_str());

    getline(loadfile, temporaryString);
        Character[0][4] = atof(temporaryString.c_str());
    
    getline(loadfile, temporaryString);
        Character[0][5] = atof(temporaryString.c_str());

    getline(loadfile, temporaryString);
        Character[0][6] = atof(temporaryString.c_str());

    getline(loadfile, temporaryString);
        Character[0][7] = atof(temporaryString.c_str());
    
    getline(loadfile, temporaryString);
        Character[0][8] = atof(temporaryString.c_str());

    getline(loadfile, temporaryString);
        cost = atoi(temporaryString.c_str());

    getline(loadfile, temporaryString);
        counter = atoi(temporaryString.c_str());
    loadfile.close();
    return 0;
}

// New game
void new_game(){
    Character[0][0] = 100;
    Character[0][1] = 100;
    Character[0][2] = 50;
    Character[0][3] = 50;
    Character[0][4] = 20;
    Character[0][5] = 10;
    Character[0][6] = 0;
    Character[0][7] = 1;
    Character[0][8] = 0;
    cost = 50;
    counter = 0;
}

// level up system //hezel
void levelup(){
    while (Character[0][8] >= 100 * Character[0][7]){
        Character[0][7]++;
        Character[0][1]+=50;
        Character[0][0]=Character[0][1];
        Character[0][3]+=25;
        Character[0][2]=Character[0][3];
        Character[0][4]+= 5;
        Character[0][5]+= 2.5;
        Character[0][8]-= 100* Character[0][7];
    }
    cout << "Level  = " << Character[0][7]<<endl;
    cout << "Max hp = " << Character[0][1]<<endl;
    cout << "Max mp = " << Character[0][3]<<endl;
    cout << "Attack = " << Character[0][4]<<endl;
    cout << "Defense = " << Character[0][5]<<endl;
    cout << "Current EXP = " << Character[0][8]<<endl;
    battle = false;
}

// Blacksmith // hezel
void blacksmith_screen(){
    while (blacksmith == true){
    cout << "|---------------------------------------|" <<endl;
    cout << "|                                       |" <<endl;
    cout << "|                                       |" <<endl;
    cout << "|                                       |" <<endl;
    cout << "|                                       |" <<endl;
    cout << "|                                       |" <<endl;
    cout << "|          Kamu lagi? kalah ya?         |" <<endl;
    cout << "|         (Hezel sang blacksmith)       |" <<endl;
    cout << "|          Upgrade senjata? y/n         |" <<endl;
    cout << "|            Harga: "<< cost << " G" << endl;
    cout << "|               Attack + 5              |"<<endl;
    cout << "|                                       |" <<endl;
    cout << "|                                       |" <<endl;
    cout << "|                                       |" <<endl;
    cout << "|                                       |" <<endl;
    cout << "|                                       |" <<endl;
    cout << "|                                       |" <<endl;
    cout << "|                                       |" <<endl;
    cout << "|---------------------------------------|" <<endl;
    cout << "Choice? ";
    cin >> choice1;
    system("cls");
    if (choice1 == "y"){
        if ((Character[0][6] - cost) <= 0 ){
            cout << "Not enough money, go grind more :)" <<endl;
            blacksmith = false;
        }
        else {
            Character [0][4] += 5;
            Character [0][6] -= cost;
            cost += 50;
            cout << "Weapon upgraded succesfully" <<endl;
            cout << "Money left: " << Character[0][6] <<endl;
        }
    }
    else {
        blacksmith = false;
    }
    }
}

// See stat //Daniel
void Stat(){
    cout << "|---------------------------------------|" <<endl;
    cout << "|                                       |" <<endl;
    cout << "|                                       |" <<endl;
    cout << "|                                       |" <<endl;
    cout << "|                                       |" <<endl;
    cout << "|                                       |" <<endl;
    cout << "|            Level  = " << Character[0][7]<<endl;
    cout << "|            Max hp = " << Character[0][1]<<endl;
    cout << "|            Max mp = " << Character[0][3]<<endl;
    cout << "|            Attack = " << Character[0][4]<<endl;
    cout << "|            Defense = " << Character[0][5]<<endl;
    cout << "|            Current EXP = " << Character[0][8]<<endl;
    cout << "|            Exp to next level  = " << (Character[0][8] - 100* Character[0][7])<<endl;
    cout << "|            Money  = " << Character[0][6]<< " G" <<endl;
    cout << "|                                       |" <<endl;
    cout << "|                                       |" <<endl;
    cout << "|                                       |" <<endl;
    cout << "|                                       |" <<endl;
    cout << "|---------------------------------------|" <<endl;
    cout << "Continue? ";
    cin >> choice1;
    system("cls");
}

//Battle screen //jul
void battle_screen(){
    if (Character [i][0] <= 0){
        cout << "You win" <<endl;
        cout << "Money gain =  " << Character[i][6]<< " G"<<endl;
        cout << "Exp gain =  " << Character[i][8]<<endl;
        cout << "Exp left till next level: " << (Character[0][8] - 100* Character[0][7])<<endl;
        Character[0][6] += Character [i][6];
        Character[0][8] += Character [i][8];
        if (Character[0][8] >= 100 * Character[0][7]){
            levelup();
        }
        battle = false;
    }
    else if (Character [0][0] <= 0){
        cout << "You lose" <<endl;
        battle = false;
    }
    else{
    cout << "|---------------------------------------|" <<endl;
    cout << "|"<< Character_name[i] <<endl;
    cout << "|Hp:"<<Character[i][0]<<'/' <<Character[i][1] <<endl;
    cout << "|MP:"<<Character[i][2]<<'/' <<Character[i][3] <<endl;
    cout << "|                                       |" <<endl;
    cout << "|                                       |" <<endl;
    cout << "|                                       |" <<endl;
    cout << "|                                       |" <<endl;
    cout << "|"<< Character_name[0] <<endl;
    cout << "|Hp:" <<Character[0][0]<<'/' <<Character[0][1] <<endl;
    cout << "|Mp:" <<Character[0][2]<<'/' <<Character[0][3] <<endl;
    cout << "|---------------------------------------|" <<endl;
    cout << "|                                       |" <<endl;
    cout << "|      1. Attack          3. Skill      |" <<endl;
    cout << "|                                       |" <<endl;
    cout << "|      2. Defends         4. Run        |" <<endl;
    cout << "|                                       |" <<endl;
    cout << "|---------------------------------------|" <<endl;
    cout << "Turn: " << turn <<endl;
    cout << "Choice? ";
    cin >> choice;
    system("cls");
    }
}

//Skill Screen //jul
void skill_screen(){
    cout << "|---------------------------------------|" <<endl;
    cout << "|"<< Character_name[i] <<endl;
    cout << "|Hp:"<<Character[i][0]<<'/' <<Character[i][1] <<endl;
    cout << "|MP:"<<Character[i][2]<<'/' <<Character[i][3] <<endl;
    cout << "|                                       |" <<endl;
    cout << "|                                       |" <<endl;
    cout << "|                                       |" <<endl;
    cout << "|                                       |" <<endl;
    cout << "|"<< Character_name[0] <<endl;
    cout << "|Hp:" <<Character[0][0]<<'/' <<Character[0][1] <<endl;
    cout << "|Mp:" <<Character[0][2]<<'/' <<Character[0][3] <<endl;
    cout << "|---------------------------------------|" <<endl;
    cout << "|                                       |" <<endl;
    cout << "|   1. Slash        3. Heal             |" <<endl;
    cout << "|                                       |" <<endl;
    cout << "|   2. Stab         4. Heaven Judgement |" <<endl;
    cout << "|                                       |" <<endl;
    cout << "|---------------------------------------|" <<endl;
    cout << "Turn: " << turn <<endl;
    cout << "Choice? ";
    cin >> choice;
    system("cls");
}

// Enemy attack //jul
void enemy_attack(){
    if (Character[i][2] - 15 >= 0 && turn % 3 == 0){
        if ((Character [i][4]*2) - Character [0][5] <= 0){
            Character[0][0] -= 1;
            Character[i][2] -= 15;
        }
        else{
            Character[0][0] -= ((Character[i][4]*2) - Character[0][5]);
            Character[i][2] -= 15;
        }
    }
    else{
        if (Character [i][4] - Character [0][5]<= 0){
            Character[i][0] -= 1;
        }
        else{
            Character[0][0] -= (Character[i][4] - Character[0][5]);
        }
    }
}

// Defense //hezel
void defense(){
    if (Character[i][2] - 15 >= 0 && turn % 3 == 0){
        if ((Character [i][4]*2) - Character [0][5] <= 0){
            Character[0][0] -= 1;
            Character[i][2] -= 15;
        }
        else{
            Character[0][0] -= ((Character[i][4]*2) * 0.5);
            Character[i][2] -= 15;
        }
    }
    else{
        if (Character [i][4] - Character [0][5]<= 0){
            Character[i][0] -= 1;
        }
        else{
            Character[0][0] -= (Character[i][4] * 0.5);
        }
    }
}

// Skill System //Daniel
void skill_system(){
    if (choice == "1"){ //slash
        if ((Character[0][2]-25) < 0){
            cout << "Mp is not enough to use skill"<<endl;
        }
        else {
            Character[0][2] -= 25;
            if ((Character [0][4]*2) - Character [i][5]  <= 0){
                Character[i][0] -= 1;
                enemy_attack();
                turn++;
            }
            else{
                Character [i][0] -= ((Character [0][4]*2) - Character [i][5]);  
                enemy_attack();
                turn++;
            }
        }
    }

    else if (choice == "2"){ //stab
        if ((Character[0][2]-10) < 0){
            cout << "Mp is not enough to use skill"<<endl;
        }
        else {
            Character[0][2] -= 10;
            if ((Character [0][4]*1.25) - Character [i][5]  <= 0){
                Character[i][0] -= 1;
                enemy_attack();
                turn++;
            }
            else{
                Character [i][0] -= ((Character [0][4]*1.25) - Character [i][5]);  
                enemy_attack();
                turn++;
            }
        }
    }

    else if (choice == "3"){ //Heal
        if ((Character[0][2]-30) < 0){
           cout << "Mp is not enough to use skill"<<endl; 
        }
        else {
            Character[0][2] -= 30;
            if ((Character[0][0] += (Character[0][4]*1.5)) >= Character[0][1]){
                Character[0][0] = Character[0][1];
                enemy_attack();
                turn++;
            }
            else{
            Character[0][0] += (Character[0][4]*1.5);
            enemy_attack();
            turn++;
            }
        }
    }

    else if (choice == "4"){ //Heaven judgment
        if (Character[0][2] < 0){
            cout << "Mp is not enough to use skill" <<endl;
        }
        else {
            Character[0][2] = 0;
            if ((Character [0][4]*8) - Character [i][5]  <= 0){
                Character[i][0] -= 1;
                enemy_attack();
                turn++;
            }
            else{
                Character [i][0] -= ((Character [0][4]*8) - Character [i][5]);  
                enemy_attack();
                turn++;
            }
        }
    }
}

// Battle System //jul
void battle_system(int i){
    if (choice == "1"){
        if (Character [0][4] - Character [i][5]  <= 0){
            Character[i][0] -= 1;
            enemy_attack();
            turn++;
        }
        else{
            Character [i][0] -= (Character [0][4] - Character [i][5]);  
            enemy_attack();
            turn++;
        }
    }
    else if (choice == "2"){
        defense();
        turn++;
    }

    else if (choice == "3"){
        skill_screen();
        skill_system();
    }

    else if (choice == "4"){
        battle = false;
    }
}

// Training System //Daniel
void training_system(){
    Training_screen();
    if (choice == "1"){
        i = 1;
        turn = 1;
        battle = true;
    }
    else if (choice == "2"){
        i = 2;
        turn = 1;
        battle = true;
    }
    else if (choice == "3"){
        i = 3;
        turn = 1;
        battle = true;
    }
    else if (choice == "4"){
        i = 4;
        turn = 1;
        battle = true;
    }
    else if (choice == "5"){
        i = 5;
        turn = 1;
        battle = true;
    }
    else{
        
    }
    do{
        battle_screen();
        battle_system(i);
    }
    while (battle == true);
    Character[i][0] = Character[i][1];
    Character[i][2] = Character[i][3];
    Character[0][0] = Character[0][1];
    Character[0][2] = Character[0][3];
}

// Town //lauren
void town_system(){
    town = true;
    while (town == true){
        town_screen();
        if (choice == "2"){
            training_system();
        }
        else if (choice == "5"){
            SaveGame();
            cout << "Game Saved Succesfully" << endl;
        }
        else if (choice == "4"){
            Stat();
        }
        else if (choice == "3"){
            blacksmith = true;
            blacksmith_screen();
        }
        else if (choice == "6"){
            break;
        }
        else if (choice == "1"){
            if (counter == 1){
                Story3();
                i = 6;
                turn = 1;
                battle = true;
                do{
                    battle_screen();
                    battle_system(i);
                }
                while (battle == true);
                if (Character[i][0] <= 0){
                    cout << "CONGRATULATIONS YOU HAVE FINISHED CHAPTER 1, TO BE CONTINUE " << endl;
                }
                else if (Character[0][0] <= 0){
                    cout << "You lose, go back to train" << endl;
                }
                Character[i][0] = Character[i][1];
                Character[i][2] = Character[i][3];
                Character[0][0] = Character[0][1];
                Character[0][2] = Character[0][3];
            }
        }
        else{

        }
    }    
}

//Main function //jul
int main(){
    cout << "Start game? y/n ";
    cin >> start;
    system("cls");
    if (start == 'y'){
        game = true;
    }

    while (game == true){
        title_screen();
        if (choice == "2"){
            LoadGame();
            cout << "Game Loaded Succesfully" << endl;
            town_system();
        }
        else if (choice == "3"){
            break;
        }
        else if (choice == "1"){
            new_game();
            Story1();
            town_system();
        }
    }
}