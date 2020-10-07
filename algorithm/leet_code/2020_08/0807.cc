#include <vector>
#include <set>
#include <algorithm>
#include <stdlib.h>

using namespace std;

vector<int> findDuplicate (vector<int> &nums) {
    set<int> search_tree;
    vector<int> answer;
    
    for (int &iter : nums) {
        if (search_tree.count(iter)) answer.push_back(iter);
        else search_tree.insert(iter);
    }

    std::sort(answer.begin(), answer.end());
    return answer;
}

vector<int> findDuplicate2 (vector<int> &nums) {
    vector<int> answer;

    for (int i=0; i < nums.size(); ++i) {
        if (nums[abs(nums[i])-1] > 0 ) nums[abs(nums[i])-1] *= -1;
        else answer.push_back(abs(nums[i]));
    }
    
    return answer;
}


int main() {
    vector<int> nums {4,3,2,7,8,2,3,1};
    findDuplicate2(nums);
    return 0;
}