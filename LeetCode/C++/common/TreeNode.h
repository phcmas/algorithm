#include <vector>
using namespace std;

class TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode();     
	TreeNode(int x); 
	TreeNode(int x, TreeNode *left, TreeNode *right);
};

namespace util {
	TreeNode *makeTree(vector<int> nums);
	void printTree(TreeNode *root);
}
