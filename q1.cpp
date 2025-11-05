#include <iostream>
using namespace std;
// name : AGRIM SAXENA
int helper(int n) {
    if (n == 0) return 0;
    return 1 + helper(n / 10);
}

int main() {
    int n = 12345;
    cout << helper(n);
    return 0;
}
