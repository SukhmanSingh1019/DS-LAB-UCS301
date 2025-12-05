#include <iostream>
using namespace std;

class node
{
public:
    char data;
    node *next = NULL;
    node *prev = NULL;
};

class dll
{
    node *head = NULL;

public:
    void at_head(char x)
    {
        node *newn = new node;
        if (!head)
        {
            head = newn;
            head->data = x;
            return;
        }
        newn->next = head;
        head->prev = newn;
        head = newn;
        newn->data = x;
    }
    void display()
    {
        node *temp = head;
        while (temp)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
    bool isplaindrome(){
        if(!head) return false;
        if(head->next==NULL) return true;
        node* end=head;
        while(end->next!=NULL){
            end=end->next;
        }
        node* front =head;
        while(front!=end){
            if(tolower(front->data)!=tolower(end->data)) return false;
            front=front->next;
            end=end->prev;
        }
        return true;
    }
};
int main() {

    dll d1;
    d1.at_head('L');
    d1.at_head('E');
    d1.at_head('V');
    d1.at_head('E');
    d1.at_head('l');
    d1.display();
    cout<<d1.isplaindrome();
}
