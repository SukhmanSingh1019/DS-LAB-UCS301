#include <iostream>
using namespace std;
class node
{
public:
    int data;
    node *next = NULL;
};

class cll
{
    node *head = NULL;

public:
    void at_head(int x)
    {
        if (!head)
        {
            node *newnode = new node;
            head = newnode;
            head->next = head;
            head->data = x;
            return;
        }
        node *temp = head;
        while (temp->next != head)
        {
            temp = temp->next;
        }
        node *newnode = new node;
        temp->next = newnode;
        newnode->next = head;
        head = newnode;
        newnode->data = x;
    }
    void display()
    {
        if (head)
        {
            node *temp = head;
            while (temp->next != head)
            {
                cout << temp->data << " ";
                temp = temp->next;
            }
            cout << temp->data << " " << temp->next->data << endl;
        }
    }
    int size(){
        if(!head){
            return 0;
        }
        node*temp=head;
        int count = 0;
        while(temp->next!=head){
            count++;
            temp=temp->next;
        }
        return count+1;
    }
};
int main()
{
    cll c1;
    c1.at_head(80);
    c1.at_head(60);
    c1.at_head(40);
    c1.at_head(100);
    c1.at_head(20);
    c1.display();
    cout<<c1.size();
}