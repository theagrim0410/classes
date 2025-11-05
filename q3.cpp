#include <iostream>
#include <vector>
using namespace std;

bool solve(const vector<int>& arr, int i = 0) {
    if (i == arr.size() - 1) return true;
    if (arr[i] >= arr[i + 1]) return false;
    return solve(arr, i + 1);
}

int main() {
    vector<int> arr = {1, 2, 3, 4, 5};
    if(solve(arr))
        cout << "sorted\n";
    else
        cout << "unsorted\n";
    return 0;
}
