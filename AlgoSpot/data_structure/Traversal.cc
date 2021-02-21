#include <iostream>
#include <cstring>

using namespace std;
int number_of_test_case =1;
int n =7;
int inorder_traverse[100];
int preorder_traverse[100];
int postorder_traverse[100];

// preorder 순서와 inorder 순서를 받아서, postorder 배열의 채우는 함수. 총 노드의 수가 count.
// preorder 및 inorder 배열포인터에는 각각 count 개의 숫자가 들어있다.
void ObtainPostorderTraverse(int *postorder, int *preorder, int *inorder, int count) {
    // 기저 사례
    if (count == 0) return;
    if (count == 1) {
        postorder[0] = preorder[0];
        return;
    }

    int index = 0;

    //inorder에서 root가 몇 번째 노드인지 찾는다
    for (int i=0; i < count; ++i) {
        if (inorder[i] == preorder[0]) {
            index =i;
            break;
        }
    }

    //root 기준으로 left tree의 postorder 순서 생성
    ObtainPostorderTraverse(&postorder[0], &preorder[1], &inorder[0], index);
    
    //root 기준으로 right tree의 postorder 순서 생성
    ObtainPostorderTraverse(&postorder[index], &preorder[index+1], &inorder[index+1], count-index-1);

    //마지막 root 추가
    postorder[count-1] = preorder[0];

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

        ObtainPostorderTraverse(&postorder_traverse[0], &preorder_traverse[0], &inorder_traverse[0], n);

        for (int j=0; j < n ; ++j) {
            cout << postorder_traverse[j] << " ";
        }
        cout << endl;
    }

    return 0;
}


