#include<iostream>
using namespace std;

struct Node 
{
    int digit;
    Node* next;
    
    Node(int d) 
    {
        digit = d;
        next = this;  // Points to itself initially
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
    if (l.head == nullptr) 
    {
        l.head = x;
        x->next = x;
    } else 
    {
        Node* last = l.head;
        while (last->next != l.head) 
        {
            last = last->next;
        }
        x->next = l.head;
        last->next = x;
        l.head = x;
    }
}

void listInsert(Node* x, Node* y) 
{  
    x->next = y->next;
    y->next = x;
}

void listDelete(List& l, Node* x) 
{
    if (x->next == x) 
    {  
        l.head = nullptr;
    } 
    else 
    {
        Node* current = l.head;
        while (current->next != x) 
        {
            current = current->next;
        }
        current->next = x->next;
        if (l.head == x) 
        {
            l.head = x->next;
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
    do 
    {
        cout << current->digit;
        current = current->next;
    } 
    while(current != l.head);
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