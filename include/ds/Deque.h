#ifndef DEQUE
#define DEQUE

class Deque
{
private:
    int size;
    int capacity;
    int frontIndex;
    int rearIndex;
    int *arr;

    void resize();

public:
    Deque();
    ~Deque();

    void print() const;

    bool is_empty() const;
    int get_size() const;
    int front() const;
    int rear() const;

    void push_front(int value);
    void push_rear(int value);
    int pop_front();
    int pop_rear();
};

#endif