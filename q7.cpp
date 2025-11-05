#include <iostream>
using namespace std;
// name : AGRIM SAXENA
int helper(int n, int rev = 0) {
    if (n == 0) return rev;
    int n2 = n % 10;
    int newn = n / 10;
    int rev2 = rev * 10 + n2;
    return helper(newn, rev2);
}
int main() {
    int n = 1234;
    cout <<  helper(n);
    return 0;
}
