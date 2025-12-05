#include <iostream>
using namespace std;
class Node{
public:
    int data;
    Node* next;
    Node(int val){data=val;next=NULL;}
};
class LinkedList{
    Node* head;
public:
    LinkedList(){head=NULL;}
    void reverse(){
        Node* prev=NULL;
        Node* curr=head;
        while(curr){
            Node* nxt=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nxt;
        }
        head=prev;
    }
};
int main(){

}

