#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void PrintVector(vector<int>& intV, string name) {
    vector<int>::iterator iter;
    cout << ">>" << name << " : ";
    for(iter = intV.begin(); iter != intV.end(); iter++) {
        cout << *iter << " ";
    }
    cout << endl;
}

bool IntCompare(int a, int b) {
    return a > b;
}

int main(void) {
    vector<int> intV = {22, 55, 31, 77, 65, 99};
    PrintVector(intV, "정렬전");
    sort(intV.begin(), intV.end());
    PrintVector(intV, "정렬 후 오름차순");
    sort(intV.begin(), intV.end(), IntCompare);
    PrintVector(intV, "정렬 후 내림차순");
}