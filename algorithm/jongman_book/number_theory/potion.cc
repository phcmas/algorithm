#include <iostream>

using namespace std;
const int MAX_NUMBER = 200;
int number_of_test_case;
int number_of_types;
int exact_recipe[MAX_NUMBER+1];
int inserted_amount[MAX_NUMBER+1];
int needed_amount[MAX_NUMBER+1];
int gcd;

int GetGCD(int num1, int num2) {
    if (num1 >= num2) {
        if (num2 == 0) return num1;
        else return GetGCD(num1%num2,num2);
    } else {
        if (num1 ==0) return num2;
        else return GetGCD (num1, num2%num1);
    }
}

void GetGCDOfRecipes(){
    int temp =1;
    
    if (number_of_types >1) {
        temp = GetGCD(exact_recipe[0], exact_recipe[1]);
        for (int i=2; i <number_of_types; ++i) {
            temp = GetGCD(temp,exact_recipe[i]);
        }
    }

    gcd = temp;
}


void GetNeededAmount() {
    for (int i=0; i<number_of_types; ++i) {
        exact_recipe[i] = exact_recipe[i]/gcd;
    }

    int num = 1;
    bool is_finished;
    while (true) {
        is_finished = true;
        for (int i=0; i< number_of_types; ++i) {
            int difference = exact_recipe[i]*num - inserted_amount[i];
            if (difference < 0) {
                is_finished = false;
                break;
            } else {
                needed_amount[i] = difference;
            }
        }

        if (is_finished) break;
        else num++;
    }
}


int main() {
    cin >> number_of_test_case;

    for (int i=0; i< number_of_test_case; ++i) {
        cin >> number_of_types;
        for (int j=0; j< number_of_types; ++j) {
            cin >> exact_recipe[j];           
        }
        for (int j=0; j< number_of_types; ++j) {
            cin >> inserted_amount[j];           
        }
        GetGCDOfRecipes();
        GetNeededAmount();
        for (int j=0; j< number_of_types-1; ++j) {
            cout << needed_amount[j] << " ";
        }
        cout << needed_amount[number_of_types-1] << endl;
    }

    return 0;
}









