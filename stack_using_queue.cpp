#include <iostream>
#include <queue>

using namespace std;

class Stack {
private:
    queue<int> q1, q2;
    int top_element;

public:
    Stack() {
        top_element = -1;
    }

    void push(int x) {
        q1.push(x);
        top_element = x;
    }

    void pop() {
        if (q1.empty()) {
            cout << "Stack is empty." << endl;
            return;
        }

        while (q1.size() > 1) {
            top_element = q1.front();
            q2.push(top_element);
            q1.pop();
        }

        q1.pop();

        queue<int> temp = q1;
        q1 = q2;
        q2 = temp;
    }

    int top() {
        if (q1.empty()) {
            cout << "Stack is empty." << endl;
            return -1;
        }

        return top_element;
    }

    bool empty() {
        return q1.empty();
    }
};

int main() {
    Stack s;
    s.push(1);
    s.push(2);
    s.push(3);
    cout << s.top() << endl;
    s.pop();
    cout << s.top() << endl;
    s.pop();
    cout << s.top() << endl;
    s.pop();
    cout << s.top() << endl;
    return 0;
}


// In this implementation, we use two queues q1 and q2. The push operation simply enqueues the element into q1 and updates the top_element variable. The pop operation first checks if q1 is empty. If it is, it prints an error message and returns. Otherwise, it transfers all the elements except the top element from q1 to q2 by dequeuing elements from q1 and enqueuing them into q2. The top element is stored in top_element and removed from q1. Finally, we swap q1 and q2 to ensure that q1 always contains the elements in the stack order.

// The top operation simply returns the top_element variable, and the empty operation checks if q1 is empty.