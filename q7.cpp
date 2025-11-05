#include <iostream>
using namespace std;

int Helper(int n, int rev) {
    if (n == 0) return rev;
    int n2 = n/10;
    int w2 = rev * 10 + n % 10; 
    return Helper(n2, w2);
}

int func(int n) {
    return Helper(n, 0);
}

int main() {
    cout << func(1234);
    return 0;
}
