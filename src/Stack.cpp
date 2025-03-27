#include "../include/ds/Stack.h"
#include <iostream>
using namespace std;

Stack::Stack() : capacity(100), top(-1), arr(new int[capacity]) {}

Stack::~Stack()
{
    delete[] arr;
}

void Stack::resize()
{
    int *temp = arr;
    arr = new int[capacity * 2];

    for (int i = 0; i < capacity; i++)
    {
        arr[i] = temp[i];
    }

    capacity *= 2;
    delete[] temp;
}

bool Stack::is_empty() const
{
    if (top == -1)
    {
        return true;
    }

    return false;
}

int Stack::peek() const
{
    if (is_empty())
    {
        throw out_of_range("Stack is empty!");
    }

    return arr[top];
}

void Stack::push(int value)
{
    if (top == capacity - 1)
    {
        resize();
    }

    top++;
    arr[top] = value;
}

bool Stack::pop()
{
    if (top == -1)
    {
        return false;
    }

    top--;
    return true;
}