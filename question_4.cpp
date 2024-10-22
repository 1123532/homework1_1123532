#include <iostream>
#include <queue>
using namespace std;

void interleaveQueue(queue<int>& q) {
    int n = q.size();
    queue<int> tempQueue;

    // Transfer first half to a temporary queue
    for (int i = 0; i < n / 2; i++) {
        tempQueue.push(q.front());
        q.pop();
    }

    // Interleave the elements
    while (!tempQueue.empty()) {
        q.push(tempQueue.front());
        tempQueue.pop();
        q.push(q.front());
        q.pop();
    }
}

int main() {
    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);

    interleaveQueue(q);

    cout << "Interleaved queue elements: ";
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;

    return 0;
}
