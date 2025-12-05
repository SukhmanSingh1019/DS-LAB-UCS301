#include<bits/stdc++.h>
using namespace std;

class Node{
public:
int data;
Node* next = NULL;
Node* prev = NULL;
};

Node* sol(Node* head){
    if(!head) return head;
    Node* temp = head;
    while(temp->next){
        if(temp->next->prev!=temp) temp->next->prev = temp;
        temp=temp->next;
    }
    return head;
}
