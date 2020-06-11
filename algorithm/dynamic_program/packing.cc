#include <iostream>
#include <cstring>
#include <string>
#include <vector>
using namespace std;

int number_of_test_cases = 0;
int number_of_items =0;
int volume_of_carrier =0;
int cache[1001][100];
int volume[100];
int need[100];
string item_names[100];

int NumberOfPacking (int remained_volume, int item) {
    if (item == number_of_items) return 0;
    int cand =0;
    int &ret = cache[remained_volume][item];

    if (ret != -1) return ret;

    ret = NumberOfPacking (remained_volume, item+1);
    if (remained_volume >= volume[item]) {
        ret = max(NumberOfPacking (remained_volume-volume[item], item+1) + need[item], ret);
    }

    if (cand > ret) ret = cand;

    return ret;
} 

void Reconstruct(int remained_volume, int item, vector<int> &picked) {
    if (item == number_of_items) return;
    if (NumberOfPacking(remained_volume,item) == NumberOfPacking(remained_volume, item+1)) {
        Reconstruct(remained_volume, item+1, picked);
    } else {
        picked.push_back(item);
        Reconstruct(remained_volume-volume[item],item+1,picked);
    }
}

int main() {
    cin >> number_of_test_cases;

    for (int i=0; i < number_of_test_cases; ++i) {
        vector<int> picked;
        cin >> number_of_items >> volume_of_carrier;
        for (int j=0; j< number_of_items; ++j) {
            cin >> item_names[j] >> volume[j] >> need[j];
        }
        memset (cache,-1, sizeof(cache));
        Reconstruct(volume_of_carrier, 0, picked);

        cout << NumberOfPacking(volume_of_carrier,0) << " " <<picked.size() <<endl;

        for (int j=0; j<picked.size(); ++j) {
            cout << item_names[picked[j]] << endl;
        }
    }

    return 0;
}










