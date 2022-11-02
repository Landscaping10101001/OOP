#include <iostream>
using namespace std;

class Circle { //Circle 클래스 선언
    int radius;
public:
    Circle() { //생성자
        radius = 1;
    }
    Circle(int r) { //생성자
        radius = r;
    }
    void setRaidus(int r) { //멤버함수
        radius = r;
    }
    int getRadius() { //멤버함수
        return radius;
    }
    double getArea() { //멤버 함수
        return 3.14 * radius * radius;
    }
};

class Sample {
    Circle *p; //객체 포인터
    int capacity;
    int size;
public:
    Sample(int n) { //생성자
        capacity = n;
        p = new Circle[n]; // 객체 배열
    }
    void read(); //멤버함수
    void write(); //멤버함수
    Circle big(); //멤버함수
    int getSize() { //멤버 함수
        return size;
    }
    ~Sample() { //소멸자
        delete[] p;
    }
};

void Sample::read() {
    int inputSize;
    int inputRadius;
    cout << "입력할려는 원의 갯수는? ";
    cin >> inputSize;
    size = inputSize;
    cout << size << "개의 원의 반지름을 입력하시오 ";
    for(int i = 0; i < size; i++) {
        cin >> inputRadius;
        p[i].setRaidus(inputRadius);
    }
}

void Sample::write() {
    for(int i = 0; i < size; i++) {
        cout << p[i].getRadius() << ' ';
    }
    cout << '\n';
}

Circle Sample::big() {
    int bigRadius = 0;
    bigRadius = p[0].getRadius();
    for(int i = 0; i < size; i++) {
        if(bigRadius < p[i].getRadius()) {
            bigRadius = p[i].getRadius();
        }
    }
    return bigRadius;
}

int main() {
    Sample s(10);
    s.read();
    cout << "각 원 객체의 반지름 " << s.getSize() << "개를 출력합니다. ";
    s.write();
    Circle big = s.big(); //가장 큰 원객체 리턴
    cout << "가장 큰 원의 넓이 : " << big.getArea() << "\t 가장 큰 원의 반지름 : " << big.getRadius() << endl;
}