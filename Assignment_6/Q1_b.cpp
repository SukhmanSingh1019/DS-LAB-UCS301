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
    void at_any(int x, int pos)
    {
        if (pos == 1)
        {
            at_head(x);
            return;
        }
        int i = 1;
        node *temp = head;
        while (i < pos - 1 && temp->next != head)
        {
            temp = temp->next;
            i++;
        }
        node *newnode = new node;
        newnode->next = temp->next;
        temp->next = newnode;
        newnode->data = x;
    }
    void del_from_head()
    {
        if (!head)
            return;
        if (head->next == head)
        {
            delete head;
            return;
        }
        node *temp = head;
        while (temp->next != head)
        {
            temp = temp->next;
        }
        node *temp2 = head;
        head = head->next;
        temp->next = head;
        delete temp2;
    }
    void del_from_any(int pos)
    {
        if (pos == 1)
        {
            del_from_head();
            return;
        }
        int i = 1;
        node *temp = head;
        while (i < pos - 1 && temp->next != head)
        {
            temp = temp->next;
            i++;
        }
        if (temp->next = head)
            return;
        node *t2 = temp->next;
        temp->next = temp->next->next;
        delete t2;
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
            cout << temp->data << endl;
        }
    }
};

int main()
{
}