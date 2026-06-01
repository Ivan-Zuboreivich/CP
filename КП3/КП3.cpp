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
const int HEIGTH = 65;
const int WIDTH = 189;
const int AREA = WIDTH * HEIGTH;

const int ENEMYHEIGTH = HEIGTH - 16;//7,16-7
const int ENEMYWIDTH = WIDTH - 11;

const int UPDELAY = 7+1;
const int DOWNDELAY = 9+1;
const int RIGHTDELAY = 11+1;
const int LEFTDELAY = 1 + 1;
//поменять фон для консоли
wchar_t minimap[HEIGTH][WIDTH] = {
    L"############################################################################################################################################################################################",
    L"#                                                                                                                                                                                          #",
    L"#   HP      0                                                                                                                                                                              #",
    L"#                                                                                                                                                                                          #",
    L"#   Money   0000                                                                                                                                                                           #",
    L"#                                                                                                                                                                                          #",
    L"############################################################################################################################################################################################",
    L"#                                                                                                                                                                                #         #",
    L"#                                                                                                                                                                                #         #",
    L"#                                                                                                                                                                                #         #",
    L"#                                                                                                                                                                                #         #",
    L"#                                                                                                                                                                                #         #",
    L"#                                                                                                                                                                                #         #",
    L"#                                                                                                                                                                                #         #",
    L"#                                                                                                                                                                                #         #",
    L"#                                                                                                                                                                                #         #",
    L"#                                                                                                                                                                                #         #",
    L"#                                                                                                                                                                                #         #",
    L"#                                                                                                                                                                                #         #",
    L"#                                                                                                                                                                                #         #",
    L"#                                                                                                                                                                                #         #",
    L"#                                                                                                                                                                                #         #",
    L"#                                                                                                                                                                                #         #",
    L"#                                                                                                                                                                                #         #",
    L"#                                                                                                                                                                                #         #",
    L"#                                                                                                                                                                                #         #",
    L"#                                                                                                                                                                                #         #",
    L"#                                                                                                                                                                                #         #",
    L"#                                                                                                                                                                                #         #",
    L"#                                                                                                                                                                                #         #",
    L"#                                                                                                                                                                                #         #",
    L"#                                                                                                                                                                                #         #",
    L"#                                                                                                                                                                                #         #",
    L"#                                                                                                                                                                                #         #",
    L"#                                                                                                                                                                                #         #",
    L"#                                                                                                                                                                                #         #",
    L"#                                                                                                                                                                                #         #",
    L"#                                                                                                                                                                                #         #",
    L"#                                                                                                                                                                                #         #",
    L"#                                                                                                                                                                                #         #",
    L"#                                                                                                                                                                                #         #",
    L"#                                                                                                                                                                                #         #",
    L"#                                                                                                                                                                                #         #",
    L"#                                                                                                                                                                                #         #",
    L"#                                                                                                                                                                                #         #",
    L"#                                                                                                                                                                                #         #",
    L"#                                                                                                                                                                                #         #",
    L"#                                                                                                                                                                                #         #",
    L"#                                                                                                                                                                                #         #",
    L"#                                                                                                                                                                                #         #",
    L"#                                                                                                                                                                                #         #",
    L"#                                                                                                                                                                                #         #",
    L"#                                                                                                                                                                                #         #",
    L"#                                                                                                                                                                                #         #",
    L"#                                                                                                                                                                                #         #",
    L"#                                                                                           p                                                                                    #         #",
    L"############################################################################################################################################################################################",
    L"#                                                                                                                                                                                          #",
    L"#                                                                                                                                                                                          #",
    L"#                                                                                                                                                                                          #",
    L"#                                                                                                                                                                                          #",
    L"#                                                                                                                                                                                          #",
    L"#                                                                                                                                                                                          #",
    L"#                                                                                                                                                                                          #",
    L"############################################################################################################################################################################################",

};
//5*10 размер блока


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

//HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);  // Получить консоль
//
//CONSOLE_FONT_INFOEX fontInfo;
//GetCurrentConsoleFontEx(hConsole, TRUE, &fontInfo); // Получить текущий шрифт
//
//// Поменять какие-то параметры
//wcsncpy(L"Arial Cyr", fontInfo.FaceName, LF_FACESIZE);  // Имя
//fontInfo.dwFontSize.X = 10; // Размер (в логических единицах)
//
//SetCurrentConsoleFontEx(hConsole, TRUE, &fontInfo); // Установить новый
// 
// 
// ▒ ▒#░▉◧▣◀☘☙

//тесты всякой шняги

//int wmain(int argc, wchar_t* argv[])
//{
//    _setmode(_fileno(stdout), _O_U16TEXT);
//    _setmode(_fileno(stdin), _O_U16TEXT);
//    _setmode(_fileno(stderr), _O_U16TEXT);
//
//    std::wcout << L"Unicode -- English -- Русский -- ░#▒▮ -- Español." << std::endl;
//    // или
//    wprintf(L"%s", L"Unicode -- English -- Русский -- Ελληνικά -- Español.\n");
//
//    //std::cout << 5;            // или printf("%d", 5);
//    //std::wcout << L"▮▮▮";
//
//    return 0;
//
//    // или wprintf(L"%s", L"привет");
//}
//Чтобы автоматически закрывать консоль при остановке отладки, включите параметр "Сервис" ->"Параметры" ->"Отладка" -> "Автоматически закрыть консоль при остановке отладки".12345678901234567
//int main() {
//    setlocale(LC_ALL, "ru");
//    _setmode(_fileno(stdout), _O_U16TEXT);
//    _setmode(_fileno(stdin), _O_U16TEXT);
//    _setmode(_fileno(stderr), _O_U16TEXT);
//    char32_t tasd = L'▉';
//    
//    wstring rrr = L" ▒ ▒#░▉";
//    //wprintf(L"%s",rrr);
//    wcout << rrr << endl;
//    int seconds;
//    HANDLE hWnd = GetStdHandle(STD_OUTPUT_HANDLE);
//    COORD bufferSize = { 1920, 1080 };
//    HWND hWindowConsole = GetConsoleWindow();
//    RECT r;
//    system("color F0");
//    GetWindowRect(hWindowConsole, &r); //stores the console's current dimensions
//    MoveWindow(hWindowConsole, r.left, r.top, 1920, 1080, TRUE);
//
//    //wcout << "Enter total number seconds for the counter ▒ ▒#░▉◧▣◀☘☙" << endl;
//    //cin >> seconds;
//    //while (seconds >= 1) {
//    //    // Print the current value of the counter along with
//    //    // the present date and time.
//    //    cout << "Time Remaining : " << seconds
//    //        << " : " + getPresentDateTime() << endl;
//
//    //    // Pause the program execution for 1 second.
//    //    this_thread::sleep_for(chrono::seconds(1));
//
//    //    // Decrement the counter.
//    //    seconds--;
//    //}
//    //cout << "Time's Up!" << endl;
//
//    //return 0;
//
//    //SetConsoleScreenBufferSize(hWindowConsole, bufferSize);
//}
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
        CP_posx[i] = rand() % 174;
        CP_posy[i] = 8 + rand() % 48;
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

//player
int PHP = 2;
//int Pspeed = 1;
//int Pdamage = 1;
int Pposx = 92;
int Pposy = 55;

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
void drawmap() {
    
    //cout << "test" << endl;
    for (int i = 0; i < HEIGTH; i++) {
        wcout << minimap[i] << endl;

    }
    gotoxy(0, 0);
}
void movePlayer(int dx, int dy) {
    int newX = Pposx + dx;
    int newY = Pposy + dy;
    if (minimap[newY][newX] == 'X') {
        if (lastSpace == 8) {
            GetItem();
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
}
struct Item {
    string name;
    int cost;
    int type;
};
const int ALLITEMS = 20;
const int ITEMSONGROUND = 10;

Item inventory[9];
int lastSpace = 0;
Item itemlist[ALLITEMS];

int I_posx[ITEMSONGROUND];
int I_posy[ITEMSONGROUND];

//void ItemCheckpickUp(int X, int Y) {
//
//}
void ClearInventory() {

}
void GetItem() {
    int randItemID = rand() % ALLITEMS;
    inventory[lastSpace] = itemlist[randItemID];
}
void ItemSpawning(){
    for (int i = 0; i < ITEMSONGROUND; i++) {
        minimap[I_posy[i]][I_posx[i]] = 'X';
    }
}
void ItemsListing() {
    for (int i = 0; i < ITEMSONGROUND; i++) {
        I_posx[i] = rand() % 174;
        I_posy[i] = 8 + rand() % 48;
    }
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

    //Изменение окна консоли (что-то из этого не работает)
    HANDLE hWnd = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD bufferSize = { 1920, 1080 };
    HWND hWindowConsole = GetConsoleWindow();
    RECT r;
    system("color F0");
    GetWindowRect(hWindowConsole, &r); //stores the console's current dimensions
    MoveWindow(hWindowConsole, r.left, r.top, 1920, 1080, TRUE);

    CPListing();

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


//if (GetKeyState('A') & 0x8000) {
//    test = 'a';
//    movePlayer(-1, 0);//levo
//}
//if (GetKeyState('W') & 0x8000) {
//    test = 'w';
//    movePlayer(0, -1);//vpered
//}
//if (GetKeyState('S') & 0x8000) {
//    test = 's';
//    movePlayer(0, 1);//nazad
//}
//if (GetKeyState('D') & 0x8000) {
//    test = 'd';
//    movePlayer(1, 0);//pravo
//}
//drawmap();
//    }