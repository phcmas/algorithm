#include <iostream>
#include "TreeNode.h"

TreeNode::TreeNode() : val(0), left(nullptr), right(nullptr) {}
TreeNode::TreeNode(int x)  : val(x), left(nullptr), right(nullptr) {}
TreeNode::TreeNode(int x, TreeNode *left, TreeNode *right)  : val(x), left(left), right(right) {}

namespace util {
	TreeNode *makeTree(vector<int> nums) {
		
	}

	void printTree(TreeNode *root) {
		
	}
}


