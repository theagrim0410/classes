#include <iostream>
using namespace std;
// name : AGRIM SAXENA
int helper(int n) {
    if (n == 0) return 0;
    int ans = 0;
    if(n%10 == 0){
        ans += 1;
    }   
    return ans + helper(n / 10);
}

int main() {
    int n = 102030;
    cout <<  helper(n);
    return 0;
}
