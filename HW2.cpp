#include <iostream>
#include <cstdlib> //rand() 함수를 사용하기 위해 필요한 라이브러리다
#include <ctime> //위의 라이브러리만 이용시 rand() 함수 사용시 같은 숫자만 계속해서 나오는 것을 확인할 수 있다. 이와같은 문제점을 해결하기 위해 항상 변하는 값인 시간을 이용해 랜덤값을 추출하는 것이다.
using namespace std;

class Random {
public:
    Random(); //생성자. 랜덤 seed를 설정한다.
    int next(); //랜덤정수를 리턴한다.
    int nextInRange(int row, int high); //low와 high 사이의 랜덤 정수를 리턴한다.
};

Random::Random() {
    srand((unsigned int)time(NULL));
}

int Random::next() {
    int randomNumber = rand();
    return randomNumber;
}

int Random::nextInRange(int row, int high) {
    int randomNumber;
    randomNumber = rand() % (high - row + 1) + row;
    return randomNumber;
}

int main()
{
    Random r; //객체 생성
    cout << "-- 0에서 " << RAND_MAX << "까지의 랜덤 정수 10 개--" << endl;

    for (int i = 0; i < 10; i++) {
        int n = r.next(); // 0에서 RAND_MAX(32767) 사이의 랜덤한 정수
        cout << n << ' ';
    }

    cout << endl << endl << "-- 2에서 " << "4 까지의 랜덤 정수 10 개 --" << endl;

    for (int i = 0; i < 10; i++) {
        int n = r.nextInRange(2, 4); // 2에서 4 사이의 랜덤한 정수
        cout << n << ' ';
    }

    cout << endl;

    return 0;
}
/*
RAND_MAX의 값은 32767인데 이상하게도 VSCode에서는 RAND_MAX 값이 2147483647로 나온다.
이 코드를 Visual Studio에서 실행 시키면 아무런 문제없이 RAND_MAX 값이 32767로 정상적으로 나온다.
(이유는 아직 모르겠다..)
*/