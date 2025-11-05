#include <iostream>
using namespace std;

int solve(int n) {
    if (n / 10 == 0) return 1;
    return 1 + solve(n / 10);
}

int main() {
    cout << solve(12345); // Output: 5
    return 0;
}
