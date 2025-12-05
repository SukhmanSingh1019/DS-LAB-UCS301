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

TreeNode* buildTreeHelper(vector<int>& preorder, vector<int>& inorder,
                          int inStart, int inEnd, int &preIndex) {

    if(inStart > inEnd) return NULL;

    int rootVal = preorder[preIndex++];
    TreeNode* root = new TreeNode(rootVal);

    int inRoot = searchInorder(inorder, inStart, inEnd, rootVal);

    root->left = buildTreeHelper(preorder, inorder, inStart, inRoot - 1, preIndex);
    root->right = buildTreeHelper(preorder, inorder, inRoot + 1, inEnd, preIndex);

    return root;
}

TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    int preIndex = 0;
    return buildTreeHelper(preorder, inorder, 0, inorder.size() - 1, preIndex);
}

