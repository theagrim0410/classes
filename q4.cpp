#include <iostream>
#include <string>
using namespace std;

bool solve(const string& s, int i = 0) {
    if (i == s.length()) return true;
    if (!isdigit(s[i])) return false;
    return solve(s, i + 1);
}

int main() {
    if(solve("12345")){
        cout << "All characters are digits\n";
    }
    else{
        cout << "Not all characters are digits\n";
    }
    return 0;
}
