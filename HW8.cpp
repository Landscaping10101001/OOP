#include <iostream>
using namespace std;

class BaseArray {
    int capacity; //스택 용량 1 -> 2 -> 4 -> 8 -> 4 -> 2
    int* mem; //스택 크기 0 -> 1 -> 2 -> 3 -> 4 -> 5 -> 4 -> 3 -> 2 -> 1 -> 0
protected:
    BaseArray(int capacity = 100) { //생성자
        this->capacity = capacity;
        mem = new int[capacity]; //동적 배열
    }
    ~BaseArray() { //소멸자
        delete[] mem;
    }
    void put(int index, int val) { //값 삽입
        mem[index] = val;
    }
    int get(int index) { //값 출력
        return mem[index];
    }
    int getCapacity() { //용량 출력
        return capacity;
    }
    void putCapacity(int newCap) { //용량 증가???
        this->capacity += newCap;
    }
    int* getMem(void) { //mem 출력???
        return mem;
    }
	void putMem(int* start) {
		int* temp = new int[capacity];

		for(int i = 0; i < this -> capacity; i++) {
			temp[i] = start[i];
		}

		putCapacity(capacity); //capacity 2배

		for(int i = 0; i < capacity / 2; i++) {
			start[i] = temp[i];
		}

		delete[] temp;
	}
	void deleteMem() {
        this -> capacity /= 2;
		int* temp = new int[capacity];

        for(int i = 0; i < capacity; i++) {
            temp[i] = mem[i];
        }

        mem = new int[capacity];

        for(int i = 0; i < capacity; i++) {
            mem[i] = temp[i];
        }
        delete[] temp;
        return;
	}
};

class MyStack : public BaseArray {
    int tos; //-1 -> 0 -> 1 -> 2 -> 3 -> 4 -> 3 -> 2 -> 1 -> 0 -> 1
public:
    MyStack(int capacity);
    void push(int n);
    int pop();
    int capacity();
    int length();
};

MyStack::MyStack(int capacity) : BaseArray::BaseArray(capacity) { //생성자
    this->tos = -1;
}

void MyStack::push(int n) { //값 삽입
	if(length() == getCapacity()){
		putMem(getMem());
	}
    put(++tos, n);
}

int MyStack::pop() { //값 출력
    if(getCapacity() / 4 == length()) {
        deleteMem();
    }
    return get(tos--);
}

int MyStack::capacity() { //스택 용량 출력
    return getCapacity();
}

int MyStack::length() { //스택 크기 출력
    return tos + 1;
}

int main() {
    MyStack mStack(1);
    int n;
    cout << "스택에 삽입할 5개의 정수를 입력하라>> ";
    for (int i = 0; i < 5; i++) {
        cin >> n;
        mStack.push(n);
    }
    cout << "스택 용량:" << mStack.capacity() << ", 스택 크기:" << mStack.length() << endl;
    cout << "스택의 모든 원소를 팝하여 출력한다>> ";
    while (mStack.length() > 0) {
        int k = mStack.pop();
        cout << k << ' ';
    }
    cout << "\n스택 용량:" << mStack.capacity() << ", 스택 크기:" << mStack.length() << endl;
}