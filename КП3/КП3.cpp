#include <iostream>
#include <string>

//
#include <windows.h>
#include <conio.h>
//
#include <ctime>
#include <chrono>
#include <thread>
//
#pragma warning(disable : 4996)
//
#include <io.h>
#include <fcntl.h>
//
#include <fstream>
using namespace std;
using namespace std::chrono;


void XDiraction();
void YDiraction();

//mapo
//const int HEIGTH = 10;
//const int WIDTH = 20;
//const int AREA = WIDTH * HEIGTH;
//char minimap[HEIGTH][WIDTH + 1] = {
//"####################",
//"#p                 #",
//"#                  #",
//"#                  #",
//"#                  #",
//"#                  #",
//"#                  #",
//"#                  #",
//"#                  #",
//"####################" };

//UI
const int HEIGTH = 65-12;
const int WIDTH = 189;
const int AREA = WIDTH * HEIGTH;

const int ENEMYHEIGTH = HEIGTH - 16;//7,16-7
const int ENEMYWIDTH = WIDTH - 11;

//const int UPDELAY = 7+1;
//const int DOWNDELAY = 9+1;
//const int RIGHTDELAY = 11+1;
//const int LEFTDELAY = 1 + 1;
//поменять фон для консоли
string minimap[HEIGTH] = {
    "############################################################################################################################################################################################",
    "#                                                                                                                                                                                          #",
    "#                                                                                                                                                                                          #",
    "#                                                                                                                                                                                          #",
    "#                                                                                                                                                                                          #",
    "#                                                                                                                                                                                          #",
    "#                                                                                                                                                                                          #",
    "#                                                                                                                                                                                          #",
    "#                                                                                                                                                                                          #",
    "#                                                                                                                                                                                          #",
    "#                                                                                                                                                                                          #",
    "#                                                                                                                                                                                          #",
    "#                                                                                                                                                                                          #",
    "#                                                                                                                                                                                          #",
    "#                                                                                                                                                                                          #",
    "#                                                                                                                                                                                          #",
    "#                                                                                                                                                                                          #",
    "#                                                                                                                                                                                          #",
    "#                                                                                                                                                                                          #",
    "#                                                                                                                                                                                          #",
    "#                                                                                                                                                                                          #",
    "#                                                                                                                                                                                          #",
    "#                                                                                                                                                                                          #",
    "#                                                                                                                                                                                          #",
    "#                                                                                                                                                                                          #",
    "#                                                                                                                                                                                          #",
    "#                                                                                                                                                                                          #",
    "#                                                                                                                                                                                          #",
    "#                                                                                                                                                                                          #",
    "#                                                                                                                                                                                          #",
    "#                                                                                                                                                                                          #",
    "#                                                                                                                                                                                          #",
    "#                                                                                                                                                                                          #",
    "#                                                                                                                                                                                          #",
    "#                                                                                                                                                                                          #",
    "#                                                                                                                                                                                          #",
    "#                                                                                                                                                                                          #",
    "#                                                                                                                                                                                          #",
    "#                                                                                                                                                                                          #",
    "#                                                                                                                                                                                          #",
    "#                                                                                                                                                                                          #",
    "#                                                                                                                                                                                          #",
    "#                                                                                                                                                                                          #",
    "#                                                                                                                                                                                          #",
    "#                                                                                                                                                                                          #",
    "#                                                                                                                                                                                          #",
    "#                                                                                                                                                                                          #",
    "#                                                                                                                                                                                          #",
    "#                                                                                  ``````````````````                                                                                      #",
    "#                                                                                  ``````````````````                                                                                      #",
    "#                                                                                  ``````````````````                                                                                      #",
    "#                                                                                  ``````````````````                                                                                      #",
    "############################################################################################################################################################################################"
};
//5*10 размер блока
const string alert[12] = {                                                                                                              
    "#                                                            #                                                               #                                                             #",
    "#                                                            #                                                               #                                                             #",
    "#     MONEY: {:04}                                            #                                                               #                                                             #",
    "#                                                            #                                                               #                                                             #",
    "#     HP: {:04}                                               #                                                               #                                                             #",
    "#                                                            #                                                               #                                                             #",
    "#     TIME: {:04}                                             #                                                               #                                                             #",
    "#                                                            #                                                               #                                                             #",
    "#     INVENTORY: {:04}                                        #                                                               #                                                             #",
    "#                                                            #                                                               #                                                             #",
    "#                                                            #                                                               #                                                             #",
    "############################################################################################################################################################################################",
};

// Function to get the current date and time as a string.
string getPresentDateTime()
{
    // Declare a time_t variable to hold the current time.
    time_t tt;
    // Declare a pointer to a tm struct to hold the local
    // time.
    struct tm* st;

    // Get the current time.
    time(&tt);
    // Convert the current time to local time.
    st = localtime(&tt);
    // Return the local time as a string.
    return asctime(st);
}


//поменять размер шрифта


//enemy

//int HP;
//int speed;
//int damage;
//int direction;

int posx = 93;
int posy = 8;

//struct controlPoint {
//    int posx;
//    int posy;
//};

const int CP_COUNT = 10;

//int CP_posx[CP_COUNT] = { 65, 65 };
//int CP_posy[CP_COUNT] = { 5, 24 }; //пока не работает

int CP_posx[CP_COUNT];
int CP_posy[CP_COUNT];

void CPListing() {
    for (int i = 2; i < CP_COUNT; i++) {
        //CP_posx[i] = rand() % ((WIDTH - RIGHTDELAY) + LEFTDELAY + 1) + LEFTDELAY;
        //CP_posy[i] = rand() % ((HEIGTH - DOWNDELAY) + UPDELAY + 1) + UPDELAY;
        CP_posx[i] = rand() % WIDTH;
        CP_posy[i] = 8 + rand() % HEIGTH;
        //cout << CP_posx[i] << CP_posx[i] << endl;
    }
}

void MoveEnemy(int dx, int dy) {
    int newX = posx + dx;
    int newY = posy + dy;

    if (minimap[newY][newX] == ' ') {
        minimap[posy][posx] = ' ';
        posx = newX;
        posy = newY;
        minimap[posy][posx] = 'E';
    }

}

int minBuff;

const int NEARESTCPS = 2;

int bufferX[NEARESTCPS];
int bufferY[NEARESTCPS];

int randomCP;
int pointX;
int pointY;

void NearestCPCalculation() {

    //вычисление ближайших контрольных точек()
    for (int j = 0; j < NEARESTCPS; j++) {//* или 3 ближайшие точки (2 проще)
        int distance = AREA;
        for (int i = 0; i < CP_COUNT; i++) {
            //Если меньше чем расстояние до точки и уникальное значение и не текущая позиция
            if (distance > abs(CP_posx[i] - posx) + abs(CP_posy[i] - posy) && distance != bufferX[0] && distance != bufferX[1] && abs(CP_posx[i] - posx) + abs(CP_posy[i] - posy) != 0) {
                distance = abs(CP_posx[i] - posx) + abs(CP_posy[i] - posy);
                minBuff = i;
            }
        }
        bufferX[j] = CP_posx[minBuff];
        bufferY[j] = CP_posy[minBuff];
    }
    //вычисление целевой точки и направления движения (должно наступать глобально при нахождении на контрольной точке)
    randomCP = rand() % (NEARESTCPS - 1);
    pointX = bufferX[randomCP];//значения должны быть по одному индексу
    pointY = bufferY[randomCP];
}


void XDiraction() {
    if (pointX - posx > 0) {
        //Right
        MoveEnemy(1, 0);
    }
    if (pointX - posx < 0) {
        //Left
        MoveEnemy(-1, 0);
    }
    //else {
    //    //YDir
    //    YDiraction();
    //}
}

void YDiraction() {
    if (pointY - posy > 0) {
        //Up
        MoveEnemy(0, -1);
    }
    if (pointY - posy < 0) {
        //Down
        MoveEnemy(0, 1);
    }
    //else {
    //    //XDir
    //    XDiraction();
    //}
}
void DiractionCalculation() {
    //if (pointX - posx == 0 && pointY - posy == 0) {
    //    NearestCPCalculation();
    //}

    if (pointX - posx < pointY - posy) {
        YDiraction();
    }
    if (pointX - posx > pointY - posy) {
        XDiraction();
    }
    else {
        NearestCPCalculation();
    }

}
void debuginf();
void debuginf(bool T);

//player
int PHP = 2;
//int Pspeed = 1;
//int Pdamage = 1;
int Pposx = 92;
int Pposy = 50;

int money = 0;
int timer = 0;


void GetItem(int x, int y );

int lastSpace = 0;

void gotoxy(int x, int y) {
    COORD pos = { x, y };
    HANDLE output = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(output, pos);
}
void hideCursor() {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO info;
    GetConsoleCursorInfo(hConsole, &info);
    info.bVisible;
    SetConsoleCursorInfo(hConsole, &info);
}
void debuginf() {
    for (int i = 0; i < CP_COUNT; i++) {
        cout << CP_posx[i] << "|" << CP_posy[i] << endl;

    }
    cout << pointX << "|" << pointY << endl;
    cout << "|||" << Pposx << "|" << Pposy << endl;
    
}

void drawAlert() {
    cout << alert[1] << endl;
    cout << alert[1] << endl;
    cout << vformat(alert[2], make_format_args(money)) << endl;
    cout << alert[1] << endl;
    cout << vformat(alert[4], make_format_args(PHP)) << endl;
    cout << alert[1] << endl;
    cout << vformat(alert[6], make_format_args(timer)) << endl;
    cout << alert[1] << endl;
    cout << vformat(alert[8], make_format_args(lastSpace)) << endl;
    cout << alert[1] << endl;
    cout << alert[1] << endl;
    cout << alert[11];
}
void drawmap() {
    
    //cout << "test" << endl;
    for (int i = 0; i < HEIGTH; i++) {
        cout << minimap[i] << endl;

    }
    drawAlert();
    //debuginf(true);
    gotoxy(0, 0);
}
void movePlayer(int dx, int dy) {
    int newX = Pposx + dx;
    int newY = Pposy + dy;
    if (minimap[newY][newX] == 'X') {
        if (lastSpace != 8) {
            GetItem(newX,newY);
            minimap[Pposy][Pposx] = ' ';
            Pposx = newX;
            Pposy = newY;
            minimap[Pposy][Pposx] = 'p';
        }
    }
    if (minimap[newY][newX] == ' ') {
        minimap[Pposy][Pposx] = ' ';
        Pposx = newX;
        Pposy = newY;
        minimap[Pposy][Pposx] = 'p';
    }
    if (minimap[newY][newX] == '`') {
        ClearInventory();
        minimap[Pposy][Pposx] = '`';
        Pposx = newX;
        Pposy = newY;
        minimap[Pposy][Pposx] = 'p';
    }
}
struct Item {
    string name;
    int cost;
    int type;
};
const int ALLITEMS = 20;
const int ITEMSONGROUND = 10;

Item inventory[9];

Item itemlist[ALLITEMS];

int I_posx[ITEMSONGROUND];
int I_posy[ITEMSONGROUND];

//void ItemCheckpickUp(int X, int Y) {
//
//}
void ClearInventory() {

}
void GetItem(int x, int y) {
    int randItemID = rand() % (ALLITEMS-1);
    inventory[lastSpace] = itemlist[randItemID];
    lastSpace += 1;
    for (int i = 0; i < ITEMSONGROUND; i++) {
        if (I_posx[i] == x && I_posy[i] == y) {
            I_posx[i] = rand() % WIDTH;
            I_posy[i] = rand() % HEIGTH;
           
            
        }
    }

}
void ItemSpawning(){
    for (int i = 0; i < ITEMSONGROUND; i++) {
        minimap[I_posy[i]][I_posx[i]] = 'X';
    }
}
void ItemsListing() {

    for (int i = 0; i < ITEMSONGROUND; i++) {
        I_posx[i] = rand() % WIDTH;
        I_posy[i] = rand() % HEIGTH;
    }
}



void ItemsValueListing() {
    ifstream itemss("Items.txt");
    string items;
    getline(itemss, items);
    ifstream costss("Costs.txt");
    string costs;
    getline(costss, costs);
    for (int i = 0; i < ALLITEMS; i++) {
        string line;
        int j = 0;
        for (;; j++) {
            if (items[j] == ',') { break; }
            line += items[j];
        }
        itemlist[i].name = line;
    }
    for (int i = 0; i < ALLITEMS; i++) {
        string line;
        int j = 0;
        for (;; j++) {
            if (costs[j] == ',') { break; }
            line += costs[j];
        }
        itemlist[i].cost = to_integer(line);
    }
    itemss.close();
    costss.close();
}
void debuginf(bool T) {
    for (int i = 0; i < CP_COUNT; i++) {
        cout << I_posx[i] << "|" << I_posy[i] << endl;

    }
    cout << pointX << "|" << pointY << endl;
    cout << "|||" << Pposx << "|" << Pposy << endl;

}

int main()
{
    //для оптимизации вывода
    char buf[10000];
    setvbuf(stdout, buf, _IOFBF, sizeof(buf));
    setlocale(LC_ALL, "ru");
    //Попытка в кастомные симолы
    //_setmode(_fileno(stdout), _O_U16TEXT);
    //_setmode(_fileno(stdin), _O_U16TEXT);
    //_setmode(_fileno(stderr), _O_U16TEXT);
    srand(time(NULL));
    //Изменение окна консоли (что-то из этого не работает)
    HANDLE hWnd = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD bufferSize = { 1920, 1080 };
    HWND hWindowConsole = GetConsoleWindow();
    RECT r;
    system("color F0");
    GetWindowRect(hWindowConsole, &r); //stores the console's current dimensions
    MoveWindow(hWindowConsole, r.left, r.top, 1920, 1080, TRUE);

    CPListing();

    ItemsListing();
    ItemSpawning();

    hideCursor();
    drawmap();

    while (true) {
        //NearestCPCalculation();
        //DiractionCalculation();
        if (_kbhit()) {
            int ch = _getch();
            if (ch == 0 || ch == 224) {
                ch = _getch();
                DiractionCalculation();
                switch (ch) {
                case 72: movePlayer(0, -1); break;//вверх
                case 80: movePlayer(0, 1); break;//вниз
                case 75: movePlayer(-1, 0); break;//влево
                case 77: movePlayer(1, 0); break;//вправо
                }
                
                drawmap();
                ItemSpawning();
            }
        }
    }
    //struct Item {
    //    string name;
    //    int cost;
    //    int type;
    //    int hp;// сколько падений переживет
    //    bool is_hard;//Тяжелый ли
    //    bool is_sost;//Составной ли
    //};

    //Item* inventory[9];
    //Item* Item_list[35];


    //controlPoint* CPs[CP_COUNT];
    //CPs[0].posx = 65;
    //CPs[0]->posy = 5;//координаты трейлера
    //CPs[1]->posx = 65;
    //CPs[1]->posy = 24;//координаты спавна бабайки
    //for (int i = 2;i < CP_COUNT; i++) {
    //    CPs[i]->posx = rand() % WIDTH;
    //    CPs[i]->posy = rand() % HEIGTH;
    //    cout << CPs[i]->posx << CPs[i]->posy << endl;
    //}




    //while (true) {

    //    gotoxy(0, 0);
    //    cout << "test" << endl;
    //    cout << map << endl;
    //    //if(0x77)//w
    //    //if(0x61)//a
    //    //if(0x73)//s
    //    //if(0x64)//d
    //    if (GetKeyState('A') & 0x8000) {

    //    }
    //    if (GetKeyState('W') & 0x8000) {
    //        cout << "w" << endl;
    //    }
    //    if (GetKeyState('S') & 0x8000) {
    //        cout << "s" << endl;
    //    }
    //    if (GetKeyState('D') & 0x8000) {
    //        cout << "d" << endl;
    //    }
    //}
}

