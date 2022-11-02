#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

class Player { //Player class
    string name;
public:
    Player(string name = "") {
        this->name = name;
    }
    void setName(string name) {
        this->name = name;
    }
    string getName() {
        return name;
    }
    void getEnterKey() {
        char buf[100];
        cin.getline(buf, 99);
    }
};

class GamblingGame { //Gambling class
    Player p[2];
    int num[3];
    bool matchAll();
public:
    GamblingGame();
    void run();
};

bool GamblingGame::matchAll() { //matchAll 멤버함수 구현
    if (num[0] == num[1] && num[1] == num[2]) {
        return true;
    }
    else {
        return false;
    }
}

GamblingGame::GamblingGame() { //Gambling class 생성자 구현
    srand((unsigned int)time(NULL));
    for (int i = 0; i < 3; i++) {
        num[i] = 0;
    }
}

void GamblingGame::run() { // run member function 구현
    cout << "***** 겜블링 게임을 시작합니다 *****" << endl;
    string PlayerName;
    cout << "첫번째 선수 이름>>";
    cin >> PlayerName;
    p[0].setName(PlayerName);
    cout << "두번째 선수 이름>>";
    cin >> PlayerName;
    p[1].setName(PlayerName);
    p[0].getEnterKey();

    int i = 0;
    while (true) {
        for (int i = 0; i < 3; i++) { //랜덤한 수 3개를 뽑아 num에 저장
            num[i] = rand() % 3;
        }

        cout << p[i % 2].getName() << ":" << "<Enter>";
        p[i % 2].getEnterKey();
        if (matchAll()) {
            cout << '\t' << num[0] << '\t' << num[1] << '\t' << num[2];
            cout << '\t' << p[i % 2].getName() << "님 승리!!";
            break;
        }
        else {
            cout << '\t' << num[0] << '\t' << num[1] << '\t' << num[2];
            cout << '\t' << "아쉽군요!" << endl;;
        }
        i++;
    }
}


int main() {
    GamblingGame game;
    game.run();
}