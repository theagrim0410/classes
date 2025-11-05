#include <iostream>
using namespace std;

int count(int n) {
    if (n == 0) return 0;
    int last = n % 10;
    int countn = (last == 0 ? 1 : 0);
    return countn + count(n / 10);
}

int main() {
    cout << count(102030); 
    return 0;
}
