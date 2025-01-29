#ifndef STACK
#define STACK

class Stack
{
private:
    int capacity;
    int *arr;
    int top;

    void resize();

public:
    Stack();
    ~Stack();

    void push(int value);
    bool pop();
    int peek() const;
};

#endif