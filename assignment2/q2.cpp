#include <bits/stdc++.h>
#include <stack>

using namespace std;

void func(stack<int> &s, int size, int current = 0) {
    if (current == size / 2) {
        s.pop();
        return;
    }
    int top = s.top();
    s.pop();
    func(s, size, current + 1);
    s.push(top);
}

int main() {
    stack<int> s;
    int n, x;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x;
        s.push(x);
    }
    stack<int> temp = s;
    while (!temp.empty()) {
        cout << temp.top() << " ";
        temp.pop();
    }

    cout << endl;

    func(s, s.size());
    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;

    return 0;
}
