#include <iostream>
using namespace std;

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
    void at_tail(int x)
    {
        node *n = new node;
        if (!head)
        {
            at_head(x);
            return;
        }
        node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = n;
        n->prev = temp;
        n->data = x;
    }
    void at_any(int x, int pos)
    {
        if (pos == 1)
        {
            at_head(x);
            return;
        }
        node *temp = head;
        int i = 1;
        while (i < pos - 1 && temp->next != NULL)
        {
            temp = temp->next;
            i++;
        }
        node *newnode = new node;
        newnode->next = temp->next;
        newnode->prev = temp;
        temp->next = newnode;
        newnode->data = x;
        if (newnode->next)
        {
            newnode->next->prev = newnode;
        }
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
    void del_from_head()
    {
        if (head)
        {
            node *temp = head;
            head = head->next;
            head->prev = NULL;
            delete temp;
        }
    }
    void del_from_tail()
    {
        if (head)
        {
            node *temp = head;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->prev->next = NULL;
            delete temp;
        }
    }
    void del_from_any(int pos)
    {
        node *temp = head;
        if (pos == 1)
        {
            del_from_head();
            return;
        }
        int i = 0;
        while (i < pos - 1)
        {
            temp = temp->next;
            i++;
        }
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        delete temp;
    }
};

int main()
{

    dll d1;
    d1.at_head(10);
    d1.at_head(5);
    d1.at_tail(15);
    d1.at_tail(25);
    d1.at_any(20, 4);
    d1.display();
    d1.del_from_tail();
    d1.display();
}