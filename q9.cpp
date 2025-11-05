#include <iostream>
#include <vector>
using namespace std;
// name : AGRIM SAXENA
void solve(vector<int>& arr, int start, int end) {
    if (start >= end) return;
    swap(arr[start], arr[end]);
    solve(arr, start + 1, end - 1);
}

int main() {
    vector<int> arr = {1, 2, 3, 4, 5};
    solve(arr, 0, arr.size() - 1);
    for (int i = 0; i < arr.size(); i++) cout << arr[i] << " ";
    return 0;
}
