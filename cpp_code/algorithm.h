#include <vector>

namespace algorithm {
    void Swap(std::vector<int> &numbers, int idx0, int idx1){
        int temp =numbers[idx0];
        numbers[idx0] = numbers[idx1];
        numbers[idx1] = temp;
    }

    void BubbleSort(std::vector<int> &numbers) {
        int i=0, j=0;
        int size = numbers.size();

        for (int i=0; i<size; ++i) {
            for (int j=0; j<size-i-1; ++j){
                if (numbers[j] > numbers[j+1]) {
                    Swap(numbers,j,j+1);
                }
            }
        }
    }

    void SelectionSort(std::vector<int> &numbers) {
        int i=0,j=0,min=0;
        int size = numbers.size();

        for (int i=0; i < size; ++i) {
            min = i;
            for (int j=i+1; j < size; ++j) {
                if (numbers[j] < numbers[min]) {
                    min = j;
                }
            }
            Swap(numbers,i,min);
        }
    }

    void InsertionSort(std::vector<int> &numbers) {
        int i=0,j=0, key=0;
        int size = numbers.size();
        for (int i=1; i < size; ++i) {
            key = numbers[i];
            j = i-1;
            while (j>=0 && numbers[j] >key) {
                numbers[j+1] = numbers[j];
                j--;
            }
            numbers[j+1] = key;
        }
    }

}