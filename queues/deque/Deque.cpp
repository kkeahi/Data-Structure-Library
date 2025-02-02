#include "Deque.h"
#include <iostream>
using namespace std;

Deque::Deque() : size(0), capacity(4), frontIndex(-1), rearIndex(-1), arr(new int[capacity]) {}

Deque::~Deque()
{
    delete[] arr;
}

bool Deque::is_empty() const
{
    return (size == 0);
}

int Deque::get_size() const
{
    return size;
}

int Deque::front() const
{
    if (is_empty())
    {
        throw underflow_error("Queue is empty!");
    }

    return arr[frontIndex];
}

int Deque::rear() const
{
    if (is_empty())
    {
        throw underflow_error("Queue is empty!");
    }

    return arr[rearIndex];
}