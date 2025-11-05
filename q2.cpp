#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int func(vector<int> arr, int n) {
    if (n == 1) return arr[0];
    return max(arr[n - 1], func(arr, n - 1));
}

int main() {
    vector<int> arr = {2, 5, 1, 8, 3};
    cout << func(arr, 5); 
    return 0;
}
