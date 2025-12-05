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
    int findMiddle(){
        Node* slow=head;
        Node* fast=head;
        while(fast&&fast->next){slow=slow->next;fast=fast->next->next;}
        return slow->data;
    }
};
int main(){
   
}

