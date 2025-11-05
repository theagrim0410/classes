#include <iostream>
#include <vector>
using namespace std;
// name : AGRIM SAXENA
bool helper(vector<int> &arr, int n) {
    if (n == 1) return true;
    if (arr[n - 1] <= arr[n - 2]) return false;
    return helper(arr, n - 1);
}

int main() {
    vector<int> arr = {1, 2, 3, 4, 5};
    vector<int> arr2 = {1, 3, 2, 4, 5};
    int n = arr.size();
    cout << (helper(arr, n) ? "Sorted" : "Not Sorted") << endl;
    cout << (helper(arr2, arr2.size()) ? "Sorted" : "Not Sorted") << endl;
    return 0;
}
