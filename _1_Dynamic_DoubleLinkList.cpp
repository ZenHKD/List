#include<iostream>
using namespace std;

struct Node 
{
    int digit;
    Node* next;
    Node* prev;
    
    Node(int d) 
    {
        digit = d;
        next = nullptr;
        prev = nullptr;
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
    l.sign = 1;
}

void listPrepend(List& l, Node* x) // Add to the head of the list
{
    x->next = l.head;
    x->prev = nullptr;
    if (l.head != nullptr) 
    {
        l.head->prev = x;
    }
    l.head = x;
}

void listInsert(Node* x, Node* y) // Insert x after y
{
    x->next = y->next;
    x->prev = y;
    if (y->next != nullptr) 
    {
        y->next->prev = x;
    }
    y->next = x;
}

void listDelete(List& l, Node* x) 
{
    if (x->prev != nullptr) 
    {
        x->prev->next = x->next;
    } 
    else 
    {
        l.head = x->next;
    }
    if (x->next != nullptr) 
    {
        x->next->prev = x->prev;
    }
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