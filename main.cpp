#include <iostream>
#include <ds/Stack.h>

using namespace std;

int main() {
    Stack s;
    s.push(10);
    s.push(9);
    s.push(8);
    cout << s.peek();

    return 0;
}