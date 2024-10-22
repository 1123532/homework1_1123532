#include <iostream>
#include <stack>
using namespace std;

void insertAtBottom(stack<int>& s, int x) {
    if (s.empty()) {
        s.push(x);
    } else {
        int temp = s.top();
        s.pop();
        insertAtBottom(s, x);
        s.push(temp);
    }
}

void reverseStack(stack<int>& s) {
    if (!s.empty()) {
        int x = s.top();
        s.pop();
        reverseStack(s);
        insertAtBottom(s, x);
    }
}

int main() {
    stack<int> s;
    s.push(28);
    s.push(29);
    s.push(30);
    s.push(31);

    reverseStack(s);

    cout << "Reversed stack elements: ";
    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;

    return 0;
}
