#include <vector>

namespace algorithm {
    void SelectionSort(std::vector<int> &numbers) {
        int i=0,j=0,min=0;
        int size = numbers.size();
        int temp=0;

        for (int i=0; i < size; ++i) {
            min = i;
            for (int j=i+1; j < size; ++j) {
                if (numbers[j] < numbers[min]) {
                    min = j;
                }
            }
            temp = numbers[i];
            numbers[i] = numbers[min];
            numbers[min] = temp; 
        }
    }
}