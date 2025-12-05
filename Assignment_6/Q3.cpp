#include <iostream>
using namespace std;

class node1
{
public:
    int data;
    node1 *next = NULL;
};
class node
{
public:
    int data;
    node *next = NULL;
    node *prev = NULL;
};

class dll
{
    node *head = NULL;

public:
    void at_head(int x)
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
    int size()
    {
        if (!head)
            return 0;
        node *temp = head;
        int count = 0;
        while (temp != NULL)
        {
            count++;
            temp = temp->next;
        }
        return count;
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
};
class cll
{
    node1 *head = NULL;

public:
    void at_head(int x)
    {
        if (!head)
        {
            node1 *newnode = new node1;
            head = newnode;
            head->next = head;
            head->data = x;
            return;
        }
        node1 *temp = head;
        while (temp->next != head)
        {
            temp = temp->next;
        }
        node1 *newnode = new node1;
        temp->next = newnode;
        newnode->next = head;
        head = newnode;
        newnode->data = x;
    }
    void display()
    {
        if (head)
        {
            node1 *temp = head;
            while (temp->next != head)
            {
                cout << temp->data << " ";
                temp = temp->next;
            }
            cout << temp->data << endl;
        }
    }
    int size()
    {
        if (!head)
        {
            return 0;
        }
        node1 *temp = head;
        int count = 0;
        while (temp->next != head)
        {
            count++;
            temp = temp->next;
        }
        return count + 1;
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
    cout << "size of circular list is " << c1.size() << endl;

    dll d1;
    d1.at_head(50);
    d1.at_head(40);
    d1.at_head(30);
    d1.at_head(20);
    d1.at_head(10);
    d1.display();
    cout << "size of doubly list is " << d1.size() << endl;
}