#include <iostream>
#include <cstring>
using namespace std;

class Book {
    char* title;
    int price;
public:
    Book(const char* title, int price);
    Book(Book& b);
    ~Book();
    void set(const char* title, int price);
    void show() {
        cout << title << ' ' << price << "원" << endl;
    }
};

Book::Book(const char* title, int price) {
    int len = (int)strlen(title);
    this->title = new char[len + 1];
    strcpy(this->title, title); //VScode에서는 strcpy_s가 적용되지 않는다. 따라서 visual studio상에서의 코드와 다르게 되어있을 것이다.
    this->price = price;
}

Book::Book(Book& b) {
    int len = strlen(b.title);
    this->title = b.title;
    this->price = b.price;
}

void Book::set(const char* title, int price) {
    int len = (int)strlen(title);
    this->title = new char[len + 1];
    strcpy(this->title, title); //VScode에서는 strcpy_s가 적용되지 않는다. 따라서 visual studio상에서의 코드와 다르게 되어있을 것이다.
    this->price = price;
}

Book::~Book() {
    delete[] title;
}

int main() {
    Book cpp("명품C++",10000);
    Book java = cpp;
    java.set("명품자바", 12000);
    cpp.show();
    java.show();
}