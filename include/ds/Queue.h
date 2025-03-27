#ifndef QUEUE
#define QUEUE

class Queue
{
private:
    int size;
    int capacity;
    int frontIndex;
    int rearIndex;
    int *arr;

    void resize();

public:
    Queue();
    ~Queue();

    bool is_empty() const;
    int get_size() const;
    int front() const;
    int rear() const;

    void enqueue(int value);
    int dequeue();
};

#endif