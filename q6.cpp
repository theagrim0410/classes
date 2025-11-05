#include <iostream>
using namespace std;

int convert(int n) {
    if (n == 0) return 0;
    int n2 = n % 2;
    int w2 = 10 * convert(n / 2);
    return n2 + w2;
}

int main() {
    int n = 10;
    cout << convert(n); 
    return 0;
}
