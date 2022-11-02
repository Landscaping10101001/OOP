#include <iostream>
using namespace std;

class Oval {
    int width, height;
    double getArea();
public:
    Oval() {
        width = height = 1;
    }
    Oval(int w, int h) {
        width = w;
        height = h;
    }
    ~Oval() {
        cout << "Oval 소멸 : ";
        show();
    }
    int getWidth() {
        return width;
    }
    int getHeight() {
        return height;
    }
    void set(int w, int h);
    void show();
};

double Oval::getArea() {
    return width * height * 3.14;
}

void Oval::set(int w, int h) {
    width = w;
    height = h;
}

void Oval::show() {
    cout << "width = " << getWidth() << ", height = " << getHeight() << " Area = " << getArea() << endl;
}

int main() {
    Oval a, b(3, 4);
    a.set(10, 20);
    a.show();
    b.show();
}
