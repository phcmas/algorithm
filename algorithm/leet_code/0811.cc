#include <vector>

using namespace std;
void swap (int idx1, int idx2, vector<int> &nums) {
        int temp = nums[idx1];
        nums[idx1] = nums[idx2];
        nums[idx2] = temp;
    }

void insertionSort (vector<int> &nums) {
    for (int i=0; i< nums.size()-1; ++i) {
        int j=i;
        while (j>=0 && nums[j] > nums[j+1]) {
            swap(j,j+1,nums);
            j--;
        }
    }
}

int hIndex (vector<int> &citations) {
    int h_index = citations.size();
    if (h_index == 0) return 0;

    insertionSort(citations);

    for (int i=0; i< citations.size(); ++i) {
        if (h_index <= citations[i]) break;
        h_index--;
    }

    return h_index;
}

int main() {
    vector<int> citations {3,0,6,1,5};
    int answer = hIndex(citations);

    return 0;
}