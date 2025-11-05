#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
// name : AGRIM SAXENA
int solve(vector<int> &arr, int n) {
    if (n == 1)
        return arr[0];
    return max(arr[n - 1], solve(arr, n - 1));
}

int main() {
    vector<int> arr = {3, 5, 2, 9, 6};
    int n = arr.size();
    cout << solve(arr, n);
    return 0;
}
