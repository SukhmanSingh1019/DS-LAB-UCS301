#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int searchInorder(vector<int>& inorder, int start, int end, int value) {
    for(int i = start; i <= end; i++) {
        if(inorder[i] == value) return i;
    }
    return -1;
}

TreeNode* buildTreeHelper(vector<int>& inorder, vector<int>& postorder,
                          int inStart, int inEnd, int &postIndex) {
    if(inStart > inEnd) return NULL;

    int rootVal = postorder[postIndex--]; 
    TreeNode* root = new TreeNode(rootVal);

    int inRoot = searchInorder(inorder, inStart, inEnd, rootVal);

    root->right = buildTreeHelper(inorder, postorder, inRoot + 1, inEnd, postIndex);
    root->left  = buildTreeHelper(inorder, postorder, inStart, inRoot - 1, postIndex);

    return root;
}
TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
    int n = inorder.size();
    int postIndex = n - 1; 
    return buildTreeHelper(inorder, postorder, 0, n - 1, postIndex);
}

