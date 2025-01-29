#include "Stack.h"
#include <iostream>
using namespace std;

Stack::Stack() : capacity(2), arr(new int[capacity]), top(-1) {}
Stack::~Stack()
{
    delete[] arr;
}

void Stack::resize()
{
}

void Stack::push(int value)
{
}

bool Stack::pop()
{
}

int Stack::peek() const
{
}