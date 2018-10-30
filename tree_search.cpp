//
// Created by Nick on 2018/10/30.
//
#include "tree.cpp"
#include <iostream>

using namespace std;

TreeNode *tree_search(TreeNode *root, int key) {
    if (root == nullptr || root->val == key) {
        return root;
    } else if (key < root->val) {
        return tree_search(root->left, key);
    } else {
        return tree_search(root->right, key);
    }
}

TreeNode *tree_minimum(TreeNode *root) {
    while (root && root->left) {
        root = root->left;
    }
    return root;
}

TreeNode *tree_parent(TreeNode *root, TreeNode *node) {
    if (root == nullptr || (root && (root->left == node || root->right == node)))
        return root;
    else if (node->val < root->val) {
        return tree_parent(root->left, node);
    } else {
        return tree_parent(root->right, node);
    }
}

TreeNode *tree_successor(TreeNode *root, TreeNode *node) {
    if (node && node->right) {
        return tree_minimum(node->right);
    } else {
        TreeNode *parent = tree_parent(root, node);
        while (parent && parent->right == node) {
            node = parent;
            parent = tree_parent(root, node);
        }
        return parent;
    }
}

TreeNode *tree_insert(TreeNode *root, int key) {
    if (root == nullptr) {
        return new TreeNode(key);
    }
    if (key < root->val) {
        root->left = tree_insert(root->left, key);
    } else {
        root->right = tree_insert(root->right, key);
    }
    return root;
}

int main() {
    TreeNode *root = new TreeNode(8);
    root->left = new TreeNode(4);
    root->right = new TreeNode(9);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(8);
    root->right->right = new TreeNode(12);
    tree_insert(root, 3);
    cout << root->left->left->right->val << endl;
}