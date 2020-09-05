#include <vector>
#include <string>
#include <iostream>
#include <limits.h>

using namespace std;
vector<bool> used (4, false);

int findMaxLessThan (vector<int> &A, int bound = INT_MAX) {
    int index = -1;
    int max = -1;

    for (int i=0; i < A.size(); ++i) {
        if (A[i] < bound && A[i] > max && used[i] == false) {
            max = A[i];
            index = i;
        }
    }
    
    if (index != -1) used[index] = true;
    return max;
}

string largestTimeFromDigits(vector<int>& A) {
    string answer;
    int first, second, third, fourth;

    // first number setting
    first = findMaxLessThan(A, 3);
    if (first == -1) return answer;

    // second number setting
    if (first == 2) {
        second = findMaxLessThan (A, 4);
    } else {
        second = findMaxLessThan(A, 10);
    }   
    if (second == -1) return answer;    

    // third number setting
    third = findMaxLessThan(A, 6);
    if (third == -1 && (first < 2 || (first == 2 && second >1))) return answer;
    else if (third == -1 && (first==2 && second <=1)) {
        used.clear(); 
        used.resize(4,false);
        first = findMaxLessThan (A, 2);
        second = findMaxLessThan (A, 10);
        third = findMaxLessThan (A, 6);
        if (third == -1) return answer;
    }

    // fourth number setting
    fourth = findMaxLessThan(A, 10);

    answer.append(to_string(first));
    answer.append(to_string(second));
    answer.append(":");
    answer.append(to_string(third));
    answer.append(to_string(fourth));

    return answer;
}

int main() {
    //vector<int> input {2,0,6,6};
    //vector<int> input {5,5,5,5};
    vector<int> input {0,4,0,0};
    string answer = largestTimeFromDigits(input);

    cout << answer << endl;

    return 0;
}




