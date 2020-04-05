#include "queue.h"
#include "sort_algorithm.h"

int main(void) {
    std::vector<int> numbers;
    numbers.push_back(3);
    numbers.push_back(4);
    numbers.push_back(2);
    numbers.push_back(7);
    numbers.push_back(5);
    numbers.push_back(6);
    numbers.push_back(1);
    algorithm::MergeSort(numbers);

    for (int i=0; i<numbers.size(); ++i) {
        std::cout<< numbers[i] << " ";
    }

}