#include <iostream>
using namespace std;
// name : AGRIM SAXENA
void solve(int n) {
    if (n == 0) return;
    solve(n / 2);
    cout << n % 2;
}
int main() {
    int n = 10;
    solve(n);
    return 0;
}
