#include "Deque.h"
#include <iostream>
using namespace std;

Deque::Deque() : size(0), capacity(4), frontIndex(-1), rearIndex(-1), arr(new int[capacity]) {}

Deque::~Deque()
{
    delete[] arr;
}

void Deque::resize()
{
    int *temp = new int[capacity * 2];

    int n = 0;
    for (int i = frontIndex; n < size; i = (i + 1) % capacity, n++)
    {
        temp[n] = arr[i];
    }

    arr = temp;
    delete[] arr;

    frontIndex = 0;
    rearIndex = size - 1;
    capacity *= 2;
}

void Deque::print() const
{
    if (is_empty())
    {
        return;
    }

    for (int i = frontIndex;; i = (i + 1) % capacity)
    {
        cout << arr[i] << endl;

        if (i == rearIndex)
        {
            break;
        }
    }

    cout << "Size: " << size << endl;
    cout << "Capacity: " << capacity;
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

void Deque::push_rear(int value) // same as queue(int value)
{
    if (is_empty())
    {
        frontIndex = 0;
        rearIndex = 0;
        arr[0] = value;

        size++;
        return;
    }

    if ((rearIndex + 1) % capacity == frontIndex)
    {
        resize();
    }

    rearIndex = (rearIndex + 1) % capacity;
    arr[rearIndex] = value;

    size++;
}

void Deque::push_front(int value)
{
    if (is_empty())
    {
        frontIndex = 0;
        rearIndex = 0;
        arr[0] = value;

        size++;
        return;
    }

    if ((frontIndex - 1 + capacity) % capacity == rearIndex)
    {
        resize();
    }

    frontIndex = (frontIndex - 1 + capacity) % capacity;
    arr[frontIndex] = value;

    size++;
}

int Deque::pop_rear()
{
    if (is_empty())
    {
        throw underflow_error("Queue is empty!");
    }

    int poppedValue = arr[rearIndex];

    if (frontIndex == rearIndex) // 1 element in queue
    {
        frontIndex = -1;
        rearIndex = -1;
    }
    else
    {
        rearIndex = (rearIndex - 1 + capacity) % capacity;
    }

    size--;
    return poppedValue;
}

int Deque::pop_front() // same as dequeue()
{
    if (is_empty())
    {
        throw underflow_error("Queue is empty!");
    }

    int poppedValue = arr[frontIndex];

    if (frontIndex == rearIndex) // 1 element in queue
    {
        frontIndex = -1;
        rearIndex = -1;
    }
    else
    {
        frontIndex = (frontIndex + 1) % capacity;
    }

    size--;
    return poppedValue;
}
