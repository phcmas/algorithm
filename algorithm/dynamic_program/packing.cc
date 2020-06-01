#include <iostream>
#include <cstring>
#include <string>
#include <vector>
using namespace std;

int number_of_test_cases = 1;
int number_of_items =6;
int volume_of_carrier =10;
int cache[1001][100];
int volume[100];
int need[100];
int answers[50];
string item_names[100];
vector<int> choices[100];

int NumberOfPacking (int remained_volume, int item) {
    if (item == number_of_items) return 0;
    int cand =0;
    int &ret = cache[remained_volume][item];

    if (ret != -1) return ret;

    ret = NumberOfPacking (remained_volume, item+1);
    if (remained_volume >= volume[item]) {
        cand = NumberOfPacking (remained_volume-volume[item], item+1) + need[item];
    }

    if (cand > ret) ret = cand;

    return ret;
} 

void Reconstruct(int test_num, int remained_volume, int item, vector<int> &picked) {
    if (item == number_of_items) return;
    if (NumberOfPacking(remained_volume,item) == NumberOfPacking(remained_volume, item+1)) {
        Reconstruct(test_num, remained_volume, item+1, picked);
    } else {
        picked.push_back(item);
        Reconstruct(test_num, remained_volume-volume[item],item+1,picked);
    }
}

int main() {
    cin >> number_of_test_cases;

    for (int i=0; i < number_of_test_cases; ++i) {
        memset (cache,-1, sizeof(cache));
        cin >> number_of_items >> volume_of_carrier;
        for (int j=0; j< number_of_items; ++j) {
            cin >> item_names[j] >> volume[j] >> need[j];
        }
        Reconstruct(i, volume_of_carrier, 0, choices[i]);
    }

    for (int i=0; i < number_of_test_cases; ++i) {
        int size = choices[i].size();
        cout << answers[i] << " "  << size <<endl;
        for (int j=0; j < size; ++j) {
            cout << item_names[choices[i][j]] << endl;
        }
    }

    return 0;
}










