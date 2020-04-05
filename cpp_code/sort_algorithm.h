#include <vector>

namespace algorithm {
    void Swap(std::vector<int> &numbers, int idx0, int idx1) {
        int temp =numbers[idx0];
        numbers[idx0] = numbers[idx1];
        numbers[idx1] = temp;
    }

    /* 버블 정렬 */
    void BubbleSort(std::vector<int> &numbers) {
        int i=0, j=0;
        int size = numbers.size();

        for (int i=0; i<size; ++i) {
            for (int j=0; j<size-i-1; ++j) {
                if (numbers[j] > numbers[j+1]) {
                    Swap(numbers, j, j+1);
                }
            }
        }
    }

    /* 선택 정렬 */
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
            Swap(numbers, i, min);
        }
    }

    /* 삽입 정렬 */
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

    /* 퀵 소트 */
    void QuickSortInternal(std::vector<int> &numbers, int start, int end) {
        int pivot_index = (start+end)/2;
        int pivot = numbers[pivot_index];
        int org_start = start;
        int org_end = end;

        if (start >= end) return ;

        while (start < end) {
            if (numbers[start] >= pivot && numbers[end] <= pivot) {
                Swap(numbers, start, end);
                if (start == pivot_index) { 
                    pivot_index = end;
                    continue;
                }
                if (end == pivot_index) {
                    pivot_index = start;
                    continue;
                }
            }            
            if (numbers[start] < pivot) start++;
            if (numbers[end] > pivot) end--;
        }
        QuickSortInternal(numbers, org_start, pivot_index-1);
        QuickSortInternal(numbers,pivot_index+1, org_end);
    }

    void QuickSort (std::vector<int> &numbers) {
        QuickSortInternal(numbers, 0, numbers.size()-1);
    }

    /* 머지 소트(합병 정렬) */
    void Merge (std::vector<int> &numbers, int left, int middle, int right) {
        std::vector<int> lefts (numbers[left], numbers[middle]);
        std::vector<int> rights (numbers[middle+1], numbers[right]);
        int i = 0, j=0;
        int index =left;
        while (true) {
            if (i == lefts.size()) {
                for ( ; j<rights.size(); ++j) {
                    numbers[index++] = rights[j];
                }
                break;
            } else if (j == rights.size()) {
                for ( ; i<lefts.size(); ++i) {
                    numbers[index++] = lefts[i];
                }
                break;
            }

            if (lefts[i] < rights[j]) {
                numbers[index++] = lefts[i++];
            } else {
                numbers[index++] = rights[j++];
            }
        }
    }

    void MergeSortInternal (std::vector<int> &numbers, int left, int right) {
        if (left >= right) return;
        int middle = (left + right) /2;
        MergeSortInternal(numbers, left, middle);
        MergeSortInternal(numbers, middle+1, right);
        Merge(numbers, left, middle, right);
    }

    void MergeSort (std::vector<int> & numbers) {
        MergeSortInternal (numbers, 0, numbers.size()-1);
    }
}


















