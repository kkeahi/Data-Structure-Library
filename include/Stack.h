#ifndef STACK
#define STACK

class Stack
{
private:
    int capacity;
    int top;
    int *arr;

    void resize();

public:
    Stack();
    ~Stack();

    bool is_empty() const;
    int peek() const;

    void push(int value);
    bool pop();
};

#endif