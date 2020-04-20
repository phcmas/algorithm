#ifndef _ALV_TREE_
#define _ALV_TREE_

#include <vector>
#include "binary_tree.h"

namespace avltree {
    int getDifference(BinaryTree *node) {
        int left_height = 0;
        int right_height = 0;
        if (node->left() != nullptr) left_height =  node->left()->height();
        if (node->right() != nullptr) right_height = node->right()->height();
        return left_height - right_height;
    }

    void setHeight (BinaryTree *node) {
        int left_height = 0;
        int right_height =0;
        if (node == nullptr) return;
        if (node->left() != nullptr) left_height = node->left()->height();
        if (node->right() != nullptr) right_height = node->right()->height();
        if (left_height >= right_height) node->set_height(left_height+1);
        else node->set_height(right_height+1);
    }

    BinaryTree *rotateLL(BinaryTree *node) {
        BinaryTree *left = node->left();
        node->set_left(left->right());
        left->set_right(node);
        setHeight(node);
        setHeight(left);
        return left;
    }

    BinaryTree *rotateRR(BinaryTree *node) {
        BinaryTree *right = node->right();
        node->set_right(right->left());
        right->set_left(node);
        setHeight(node);
        setHeight(right);
        return right;
    }

    BinaryTree *rotateLR(BinaryTree *node) {
        BinaryTree *left = rotateRR(node->left());
        node->set_left(left);
        return rotateLL(node);
    }

    BinaryTree *rotateRL(BinaryTree *node) {
        BinaryTree *right = rotateLL(node->right());
        node->set_right(right);
        return rotateRR(node);
    }

    BinaryTree *balance(BinaryTree *node) {
        int difference = getDifference(node);
        if (difference >=2) {
            if (getDifference(node->left()) >=1) {

            } else {

            }
        } else if (difference <=-2) {
            
        }
    
    }


}

#endif



















