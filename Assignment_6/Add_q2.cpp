#include<bits/stdc++.h>
using namespace std;

class Node{
public:
int data;
Node* next = NULL;
Node* prev = NULL;
};

bool parity(int data){
    int count = 0;
    while(data){
        if(data&1) count++;
        data>>=1;
    }
    return count%2==0;
}

Node* sol(Node* head){
    if(!head) return head;
    Node* temp = head;
    while(temp){
        Node* nextnode = temp->next;
        if(parity(temp->data)){
            if(temp==head){
                head= nextnode;
                if(head)
                head->prev = NULL;
            }
            else {
                temp->prev->next = nextnode;
                if(nextnode)
                nextnode->prev = temp->prev;
            }
            delete temp;
        }
        temp=nextnode;
    }
    return head;
}
