#include <iostream>
#include <vector>

int min (int first, int second) {
    int result =0;
    if (first <= second) result = first;
    else result = second;

    return result;
}

int max (int first, int second, int third = -1) {
    int result = 0;
    if (first >= second) result = first;
    else result = second;

    if (third >= result) result = third;
    return result;
}

int maxMiddleBorderArea(std::vector<int> &fences, int middle) {
    int area = 0 ;
    int i = middle-1;
    int j = middle;
    int fences_size = fences.size();
    int width = 2;
    int height = min (fences[i], fences[j]);
    bool move = false;
    int temp_height = 0;
    
    while (true) {
        move = false;
        if ( i > 0 && fences[i-1] >= height) {
            i--, width++;
            move = true;
        }
        
        if (j < fences_size-1 && fences[j+1] >=height ) {
            j++, width++;
            move = true;
        }

        if (!move) {
            if (height * width > area) area = height * width;

            if (j< fences_size-1 && i>0) {
                height = max (fences[i-1], fences[j+1]);
            } else if (j == fences_size-1 && i > 0) {
                height = fences[i-1];
            } else if (i ==0 && j< fences_size-1) {
                height = fences[j+1];
            }
            
            if (i<=0 && j>=fences.size()-1) break;
        }
    }

    return area;
}

int maxRectangleArea(std::vector<int> &fences) {
    int left_max, right_max, middle_max;
    std::vector<int> left_fences, right_fences;
    int middle;
    int middle_area_1, middle_area_2;

    if (fences.size() == 1) return fences[0];

    if (fences.size() % 2 == 0) middle = fences.size()/2;
    else middle = (fences.size()+1)/2;

    for (int i=0; i < middle; ++i) left_fences.push_back(fences[i]);
    for (int i=middle; i < fences.size(); ++i) right_fences.push_back(fences[i]);

    left_max = maxRectangleArea(left_fences);
    right_max = maxRectangleArea(right_fences);
    middle_max = maxMiddleBorderArea(fences, middle);

    return max(left_max, right_max, middle_max);
}

int main() {
    int number_of_test_case = 1;
    std::vector<int> answers;
    std::cin >> number_of_test_case;

    for (int i=0; i< number_of_test_case; ++i) {
        int number_of_fences;
        std::vector<int> fences;
        std::cin >> number_of_fences;
        for (int j=0; j< number_of_fences; ++j) {
            int fence;
            std::cin >> fence;
            fences.push_back(fence);
        }
        answers.push_back(maxRectangleArea(fences));
    }

    for (int i=0; i< number_of_test_case; ++i) {
        std::cout << answers[i] <<std::endl;
    }


    return 0;
}