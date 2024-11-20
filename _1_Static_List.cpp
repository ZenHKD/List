#include<iostream>
using namespace std;

struct List 
{
    int sign; // 1 for (+)  and -1 for (-)
    int digits[100];
    int size; // Current number of digits
}; 

void init(List &l) // Pass by reference
{
    l.size = 0;
    l.sign = 1;
}

void addDigit(List &l, int digit, int index)
{
    if(l.size == 100)
    {
        cout << "The list is full. Cannot add more" << endl;
        return;
    }
    if((index < 0) || (index > l.size))
    {
        cout << "Invalid index" << endl;
        return;
    }
    else
    {
        for(int i = l.size; i > index; i--) // Shift the elements to the right 
        {
            l.digits[i] = l.digits[i - 1];
        }
        l.digits[index] = digit;
        l.size++;
    }
}

void removeDigit(List &l, int index)
{
    if(l.size == 0)
    {
        cout << "The list is empty" << endl;
        return;
    }
    if((index < 0) || (index > l.size))
    {
        cout << "Invalid index" << endl;
        return;
    }
    else
    {
        for (int i = index; i < l.size - 1; i++) 
        {
            l.digits[i] = l.digits[i + 1];
        }
        l.size--;
    }
}

int sumDigit(List &l)
{
    int sum = 0;
    for(int i = 0; i < l.size; i++)
    {
        sum += l.digits[i];
    }
    return sum;
}

void display(List &l)
{
    if(l.size == 0)
    {
        cout << "The list is empty" << endl;
        return;
    }
    if(l.sign == -1)
    {
        cout << "-";
    }
    for (int i = 0; i < l.size; i++) 
    {
        cout << l.digits[i];
    }
    cout << endl;
}

int main() 
{
    List number;
    init(number);

    // Add some digits
    addDigit(number, 1, 0);
    addDigit(number, 2, 1);
    addDigit(number, 3, 2);

    // Set negative number
    number.sign = -1;

    cout << "Original number: ";
    display(number);

    // Try removing a digit that exists
    removeDigit(number, 2);
    cout << "After removing index 2: ";
    display(number);

    // Try removing a digit that does not exist
    removeDigit(number, 5);
    cout << "After attempting to remove 5: ";
    display(number);

    return 0;
}
