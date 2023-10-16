#include <iostream>
#include <conio.h>
#include <windows.h>
#include <ctime>
#define tab '\t';//все '\t' заменять на tab
using namespace std;
bool gameOver;
const int weight = 40;
const int height = 5;
int x, y , b = 0 , d = 0;
int score;
int fruitx, fruity , fruitx2, fruity2, bombx1 , bomby1 , bombx3, bomby3;
enum eDirection { STOP = 0, LEFT, RIGHT, DAWN, UP };
eDirection dir;

void Setup() {
    gameOver = false;
    dir = STOP;
    x = 1;
    y = height - 1;
    srand(time(NULL));//srand настраивает функцию rand , но чтобы значения ранд менялись ,то пишем time(NULL)
    //в данном коде srand(time(NULL)); можно не писать так как нет смысла , все и так генерируется при прохождении кода
    //в этих строках только первое определение все остальное потом
    fruitx = rand() % weight;
    fruity = 2;
    fruitx2 = rand() % weight;
    fruity2 = 2;
    bombx1 = rand() % weight;
    bomby1 = height - 1;
    bombx3 = rand() % weight;
    bomby3 = height - 1;
}
void Draw() {
    system("cls");
    setlocale(LC_ALL, "RUS");
    cout << "\t\t\"2D ИГРА:\"\n";
    cout << ' ';
    for (int i = 0; i <= weight; i++) {
        cout << '_';
    }
    for (int i = 0; i < height; i++) {
        cout << endl;
        for(int j = 0; j <= weight ; j++){
            if (j == 0) {
                cout << '|';
            }
            if (j == bombx1 && i == bomby1) {
                cout << 'O';
                continue;
            }
            if (j == bombx3 && i == bomby3) {
                cout << 'O';
                continue;
            }
            if (j == fruitx && i == fruity) {
                cout << '+';
                continue;
            }
            if (j == fruitx2 && i == fruity2) {
                cout << 'O';
                continue;
            }
            if (i == y && j == x) {
                cout << "0";
            }
            else if (j != weight + 1 && i != 2 || i == 0 ) {
                cout << ' ';
            }
            else if(i == 2) {
                cout << '_';
            }
            if (j == weight ) {
                cout << '|';
            }
        }
    }
    cout << endl;
    cout << ' ';
    for (int i = 0; i <= weight; i++) {
        cout << '`';
    }
    

}
void Input() {
    if (_kbhit()) {
        switch (_getch()) {
        case'a':
            dir = LEFT;
            break;            
        case'd':
            dir = RIGHT;
            break;
        case's':
            if (dir == RIGHT) {
                dir = DAWN;
                d = 1;
                break;
            }
            if (dir == LEFT) {
                dir = DAWN;
                d = 2;
                break;
            }
        case'w':
            if (dir == RIGHT) {
                dir = UP;
                b = 1;
                break;
            }
            if (dir == LEFT) {
                dir = UP;
                b = 2;
                break;
            }
        }

    }
}
void Logic() {
    if (dir) {
        
        if (dir == UP) {
            if (b == 1) {
                y = 2;
                x++;
            }
            if (b == 2) {
                y = 2;
                x--;
            }
        }
        if (dir == LEFT) {
            x--;
        }
        if (dir == DAWN) {
            if (d == 2) {
                y = height - 1;
                x--;
            }
            if (d == 1) {
                y = height - 1;
                x++;
            }
        }
        if (dir == RIGHT) {
            x++;
        }
    }
    if (true) {
        if (x >= weight) {
            x = 0;
        }
        if (x < 0) {
            x = weight - 1;
        }
        if (y > weight) {
            y = 0;
        }
        if (y < 0) {
            y = weight;
        }
    }
    if (x == fruitx && y == fruity) {
        score += 1;
        srand(time(NULL));
        fruitx = rand() % weight;
        fruity = 2;
        bombx1 = rand() % weight;
        bomby1 = height - 1;
        fruitx2 = rand() % weight;
        fruity2 = 2;
        bombx3 = rand() % weight;
        bomby3 = height - 1;
    }
    if (x == fruitx2 && y == fruity2) {
        score -= 1;
        srand(time(NULL));
        fruitx = rand() % weight;
        fruity = 2;
        bombx1 = rand() % weight;
        bomby1 = height - 1;
        fruitx2 = rand() % weight;
        fruity2 = 2;
        bombx3 = rand() % weight;
        bomby3 = height - 1; 

    }
    if (x == bombx1 && y == bomby1) {
        score -= 1;
        srand(time(NULL));
        fruitx = rand() % weight;
        fruity = 2;
        bombx1 = rand() % weight;
        bomby1 = height - 1;
        fruitx2 = rand() % weight;
        fruity2 = 2;
        bombx3 = rand() % weight;
        bomby3 = height - 1; 
    }
    if (x == bombx3 && y == bomby3) {
        score -= 1;
        srand(time(NULL));
        fruitx = rand() % weight;
        fruity = 2;
        bombx1 = rand() % weight;
        bomby1 = height - 1;
        fruitx2 = rand() % weight;
        fruity2 = 2;
        bombx3 = rand() % weight;
        bomby3 = height - 1;
    }
    if (score == 5) {
        gameOver = true;
    }
}

int main() {
    setlocale(LC_ALL, "RUS");
    while (true) {
        cout << "Включите английску раскладку(Shift + Alt)" << endl;
        link:
        cout << "Если включили английскую раскладку введите YES : ";
        string a;
        cin >> a;
        if (a == "YES") {

            Setup();
            while (!gameOver) {
                Draw();
                Input();
                Logic();
                cout << endl << "score = " << score << '\n';
                Sleep(100);//задержка вывода в милисекундах
            }
            setlocale(LC_ALL, "RUS");
            if (gameOver == true) {
                const char TAB1 = '\t';//просто чтобы знать что такое const char.
                //const = неизменяемая переменная , char  этосимволы типо ! и т.д.
                cout << TAB1 << TAB1 << "\"Вы прошли уровень!\"" << endl << endl << tab;
            }
            system("pause");//для того чтобы в конце ,после завершения программы , cmd сразу не закрывалось
        }
        else { goto link; };/*функция goto(и название слова без скобок  в данном случае link) телепортирует проведение 
                            программы на строку 212 т.к.там указано слово link :*/
    }
}