#include<iostream>
using namespace std;

struct Node 
{
    int digit;
    Node* next;
    
    Node(int d) 
    {
        digit = d;
        next = nullptr;
    }
};

struct List 
{
    Node* head;
    int sign;
};

void init(List& l) 
{
    l.head = nullptr;
    l.sign = 0;
}

void listPrepend(List& l, Node* x) 
{
    x->next = l.head;
    l.head = x;
}

void listInsert(Node* x, Node* y) 
{
    x->next = y->next;
    y->next = x;
}

void listDelete(List& l, Node* x) // Since single link list can only travel forward , to delete node => hard
{
    if (l.head == x) 
    {
        l.head = x->next;
    } 
    else 
    {
        Node* current = l.head;
        while (current != nullptr && current->next != x) // Require loop to tracking from the head
        {
            current = current->next;
        }
        if (current != nullptr) 
        {
            current->next = x->next;
        }
    }
    delete x;
}

void display(List& l) 
{
    if(l.head == nullptr) 
    {
        cout << "The list is empty" << endl;
        return;
    }
    if(l.sign == -1) 
    {
        cout << "-";
    }
    Node* current = l.head;
    while(current != nullptr) 
    {
        cout << current->digit;
        current = current->next;
    }
    cout << endl;
}

int main() 
{
    List l;
    init(l);

    Node* n1 = new Node(1);
    Node* n2 = new Node(2);
    Node* n3 = new Node(3);
    
    // Prepend
    listPrepend(l, n1);
    listPrepend(l, n2);

    // Change to negative
    l.sign = -1;

    // Insert
    listInsert(n3, n2);
    
    cout << "After insertions: ";
    display(l);

    // Delete
    listDelete(l, n2);
    cout << "After deletion: ";
    display(l);

    return 0;
}