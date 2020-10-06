#include <vector>
#include <iostream>

using namespace std;

void Func2 (vector <int> &num) {
    cout << num[0] <<endl;;
}

void Func (vector<int> &num) {
    Func2(num);
}

int main() {
    vector<int> num {0};
    Func(num);
}