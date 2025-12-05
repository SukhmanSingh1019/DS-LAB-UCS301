#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    node *next = NULL;
    node *prev = NULL;
    node *up = NULL;
    node *down = NULL;
    node(int d)
    {
        data = d;
    }
};

node *sol(vector<vector<int>> mat)
{

    if (mat.empty() || mat[0].empty())
    {
        return NULL;
    }
    int R = mat.size();
    int C = mat[0].size();
    vector<vector<node *>> nodemat(R, vector<node *>(C));
    for (int r = 0; r < R; r++)
    {
        for (int c = 0; c < C; c++)
        {
            nodemat[r][c] = new node(mat[r][c]);
            if (c > 0)
            {
                nodemat[r][c]->prev = nodemat[r][c - 1];
                nodemat[r][c - 1]->next = nodemat[r][c];
            }
        }
    }
    for (int r = 1; r < R; r++)
    {
        for (int c = 0; c < C; c++)
        {
            nodemat[r - 1][c]->down = nodemat[r][c];
            nodemat[r][c]->up = nodemat[r - 1][c];
        }
    }
    return nodemat[0][0];
}

void print(node* head){
    node* temp = head;
    while(head){
        temp = head;
        while(temp){
            cout<<temp->data<<" ";
            temp=temp->next;
        }
        cout<<endl;
        head = head->down;
    }
}
