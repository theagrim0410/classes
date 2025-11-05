#include <iostream>
#include <string>
#include <cctype>
using namespace std;
// name : AGRIM SAXENA
bool solve(string s, int i = 0) {
    if (i == s.size()) return true;
    if (!isdigit(s[i])) return false;
    return solve(s, i + 1);
}

int main() {
    string s = "12345";
    string s2 = "12a45";
    cout << (solve(s) ? "digit" : "not digit") << endl;
    cout << (solve(s2) ? "digit" : "not digit") << endl;
    return 0;
}
