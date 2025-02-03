#include <iostream>
#include "queue/Queue.h"
#include "deque/Deque.h"
using namespace std;

int main()
{
    Deque q;

    q.push_rear(50);
    q.push_rear(60);
    q.push_rear(70);
    q.pop_front();
    q.pop_front();
    q.pop_front();
    q.push_front(20);

    q.print();

    return 0;
}