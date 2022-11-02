#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Book {
    string title; //책 이름
    string author; //저자
    int year;
public:
    Book() {}; //생성자
    Book(string title, string author, int year) { //생성자
        this->title = title;
        this->author = author;
        this->year = year;
    }
    void set(string title, string author, int year) {
        this->title = title;
        this->author = author;
        this->year = year;
    }
    string getAuthor() {
        return author;
    }
    int getYear() {
        return year;
    }
    void show();
};

void Book::show() {
    cout << year << "년도, " << title << ", " << author << endl;
}

class BookManager {
    vector<Book> v;
    void searchByAuthor();
    void searchByYear();
    void bookIn();
public:
    void run();
};

void BookManager::bookIn() { //완성
    int year;
    string title;
    string author;
    cout << "입고할 책을 입력하세요. 년도에 -1을 입력하면 입고를 종료합니다." << endl;
    while (1) {
        cout << "년도>>";
        cin >> year;
        if (year == -1) {
            break;
        }

        cout << "책이름>>";
        cin >> title;

        cout << "저자>>";
        cin >> author;

        Book book(title, author, year);
        v.push_back(book);
    }
    cout << "총 입고된 책은 " << v.size() << "권 입니다" << endl;
}

void BookManager::searchByYear() { //완성
    int year;
    cout << "검색하고자 하는 년도를 입력하세요>>";
    cin >> year;
    for(int i = 0; i < v.size(); i++) { //탐색
        if(v[i].getYear() == year) {
            v[i].show(); //책 관련 정보 출력
            break;
        }
    }
}

void BookManager::searchByAuthor() { //완성
    string author;
    cout << "검색하고자 하는 저자 이름을 입력하세요>>";
    cin >> author;
    for(int i = 0; i < v.size(); i++) { //탐색
        if(v[i].getAuthor() == author) {
            v[i].show(); //책 관련 정보 출력
            break;
        }
    }
}

void BookManager::run() { //완성
    bookIn(); //입고
    searchByAuthor(); //저자로 검색
    searchByYear(); //년도로 검색
}

int main() { //완성
    BookManager man;
    man.run();
}