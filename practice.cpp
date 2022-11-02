#include<iostream>
#include<string>
using namespace std;

class Circle {
	int radius;
public: Circle() { radius = 1; }
	  Circle(int r) { radius = r; }
	  void setRadius(int r) { radius = r; }
	  int getRadius() { return radius; }
	  double getArea() { return 3.14 * radius * radius; }
};

class Sample {
	Circle* p; int capacity; int size;
public: // 생성자
	Sample(int n) { capacity = n; p = new Circle[n]; } // n개 원 객체을 배열로 동적으로 생성
	void read(); // 동적 할당받은 원 객체의 배열 p에 사용자가 반지름 입력
	void write(); // 동적 원 객체 배열의 반지름을 화면에 출력
	Circle big(); // 원 객체에서 가장 큰 원 객체를 리턴
	int getSize() { return size; }
	~Sample() { delete[] p; } // 소멸자
};

void Sample::read() {
	cout << "입력하려는 원의 갯수는 ? ";
	cin >> size;
	cout<<size << "개의 정수를 입력하시오 ";
	for (int i=0;i<size;i++){
		int n=0;
		cin>>n;
		p[i].setRadius(n);
	}

}

void Sample::write() {
	for (int i = 0; i < size; i++) {
		cout << p[i].getRadius() << ' ';
	}
	cout << "\n\n";
}

Circle Sample::big() {
	int max = 0;
	for (int i = 0; i < size; i++) {
		if (p[max].getRadius() <= p[i].getRadius()) max = i;
	}
	return p[max];
}

int main() {
	Sample s(10); // 10개 동적 원 객체 배열을 가진 Sample 객체 생성
	s.read(); // 키보드로 각 원 객체에 반지름을 저장
	cout << "각 원 객체의 반지름 " << s.getSize() << "개를 출력합니다.";
	s.write(); // 각 동적 원객체의 반지름 출력
	Circle big = s.big(); // 가장 큰 원객체 리턴
	cout << "가장 큰 원의 넓이 : " << big.getArea() << "\t 가장 큰 원의 반지름 : "
		<< big.getRadius() << endl; // 가장 큰 원 출력
}
