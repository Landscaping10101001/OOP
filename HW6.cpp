#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

class Random {
public:
    static void seed();
    static int nextInt(int minNumber, int maxNumber);
    static char nextAlphabet();
    static double nextDouble();
};

void Random::seed() {
    srand((unsigned int)time(NULL));
}

int Random::nextInt(int minNumber, int maxNumber) {
    int number;
    number = rand() % (maxNumber - minNumber + 1) + minNumber;
    return number;
}

char Random::nextAlphabet() {
    char alphabet;
    int capitalOrSmall;
    capitalOrSmall = rand() % 2;
    if (capitalOrSmall == 0) {
        alphabet = rand() % (90 - 65 + 1) + 65; //대분자 알파벳 출력
        return alphabet;
    }
    else {
        alphabet = rand() % (122 - 97 + 1) + 97; //소문자 알파벳 출력
        return alphabet;
    }
}

double Random::nextDouble() {
    double num;
    num = (double)rand() / RAND_MAX;
    return num;
}

int main() {
    Random::seed();

    cout << "1에서 100까지 랜덤한 정수 10개를 출력합니다" << endl;
    for (int i = 0; i < 10; i++) {
        cout << Random::nextInt(1, 100) << ' ';
    }
    cout << endl;

    cout << "알파벳을 랜덤하게 10개를 출력합니다" << endl;
    for (int i = 0; i < 10; i++) {
        cout << Random::nextAlphabet() << ' ';
    }
    cout << endl;

    cout << "랜덤한 실수를 10개를 출력합니다" << endl;
    for (int i = 0; i < 5; i++) {
        cout << Random::nextDouble() << ' ';
    }
    cout << endl;
    for (int i = 0; i < 5; i++) {
        cout << Random::nextDouble() << ' ';
    }
    cout << endl;
}