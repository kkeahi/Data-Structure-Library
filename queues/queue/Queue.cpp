#include "Queue.h"
#include <iostream>
using namespace std;

Queue::Queue() : size(0), capacity(4), frontIndex(-1), rearIndex(-1), arr(new int[capacity]) {}
Queue::~Queue()
{
    delete[] arr;
}

void Queue::resize()
{
    int *temp = new int[capacity * 2];

    int n = 0;
    for (int i = frontIndex; n < size; i = (i + 1) % capacity, n++)
    {
        temp[n] = arr[i];
    }

    delete[] arr;
    arr = temp;

    frontIndex = 0;
    rearIndex = size - 1;
    capacity *= 2;
}

bool Queue::is_empty() const
{
    return (size == 0);
}

int Queue::get_size() const
{
    return size;
}

int Queue::front() const
{
    if (is_empty())
    {
        throw underflow_error("Queue is empty!");
    }

    return arr[frontIndex];
}

int Queue::rear() const
{
    if (is_empty())
    {
        throw underflow_error("Queue is empty!");
    }

    return arr[rearIndex];
}

void Queue::enqueue(int value)
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

int Queue::dequeue()
{
    if (is_empty())
    {
        throw underflow_error("Queue is empty!");
    }

    int dequeuedValue = arr[frontIndex];

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
    return dequeuedValue;
}
