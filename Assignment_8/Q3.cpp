struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(NULL), right(NULL) {}
};

int findMin(Node* root) {
    if (!root) return -1;
    while (root->left) root = root->left;
    return root->data;
}

node* deltetion(node* root,int x){
    if(!root) return root;
    if(root->data == x){
        if(!root->left && !root->right){
            delete root;
            return NULL;
        }
            if(root->left && !root->right){
                node* temp = root->left;
                delete root;
                return temp;
            }
            if(root->right && !root->left){
                node* temp = root->right;
                delete root;
                return root->right;
            }
        if(root->left && root->right){
            int min = findMin(root->right);
            root->data=min;
            root->right = deltetion(root->right,min);
            return root;
        }
    }
    else if (root->data < x) root->left = deltetion(root->right,x);
    else root->right = deltetion(root->right,x);
}

int maxDepth(Node* root) {
    if (!root) return 0;
    return 1 + max(maxDepth(root->left), maxDepth(root->right));

int minDepth(Node* root) {
    if (!root) return 0;
    if (!root->left && !root->right)
        return 1;
    if (!root->left)
        return 1 + minDepth(root->right);
    if (!root->right)
        return 1 + minDepth(root->left);

    return 1 + min(minDepth(root->left), minDepth(root->right));
}

