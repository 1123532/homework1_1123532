#include <iostream>
#include <vector>
#include <stack>
using namespace std;

void printNextGreaterElement(const vector<int>& arr) {
    stack<int> s;
    int n = arr.size();
    vector<int> nge(n, -1);

    for (int i = 0; i < n; i++) {
        while (!s.empty() && arr[s.top()] < arr[i]) {
            nge[s.top()] = arr[i];
            s.pop();
        }
        s.push(i);
    }

    for (int i = 0; i < n; i++) {
        cout << arr[i] << " -> " << nge[i] << endl;
    }
}

int main() {
    vector<int> arr = {4, 5, 2, 25};
    printNextGreaterElement(arr);
    return 0;
}
