#include <iostream>
#include <cstring>

using namespace std;
int number_of_test_case;
int n;
int inorder_traverse[100];
int preorder_traverse[100];
int postorder_traverse[100];

// preorder 순서와 inorder 순서를 받아서, postorder_traverse 배열의 begin_index부터 end_index 까지 숫자를 채우는 함수.
// preorder_traverse 및 inorder_traverse 배열포인터에는 각각 end_index-begin_index+1 개의 숫자가 들어있다.
void ObtainPostorderTraverse(int *preorder_traverse, int *inorder_traverse, int begin_index, int end_index) {
    // 기저 사례
    if (begin_index ==  end_index) {
        postorder_traverse[begin_index] = preorder_traverse[0];
        return;
    }

    int root = preorder_traverse[0];
    int index = 0;

    for (int i=0; i < end_index-begin_index+1; ++i) {
        if (inorder_traverse[i] == root) {
            index =i;
            break;
        }
    }




    //마지막 root 추가
    ObtainPostorderTraverse(&preorder_traverse[0], &inorder_traverse[index], end_index, end_index);
    
}

int main() {
    cin >> number_of_test_case;

    for (int i=0; i < number_of_test_case; ++i) {
        cin >> n;

        for (int j=0; j < n; ++j) {
            cin >> preorder_traverse[j];
        }

        for (int j=0; j < n; ++j) {
            cin >> inorder_traverse[j];
        }

        ObtainPostorderTraverse(&preorder_traverse[0], &inorder_traverse[0], 0, n);

        for (int j=0; j < n ; ++j) {
            cout << postorder_traverse[j] << " ";
        }
        cout << endl;
    }

    return 0;
}


