#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

bool check(int row, int col, vector<string> &board, int n) {
        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--)
            if (board[i][j] == 'Q') return false;
  
        for (int j = col - 1; j >= 0; j--)
            if (board[row][j] == 'Q') return false;

        for (int i = row + 1, j = col - 1; i < n && j >= 0; i++, j--)
            if (board[i][j] == 'Q') return false;

        return true;
}

int solve(int j , vector<string>& arr,int n){
    if(j == n){
         return 1;
    }

    int cnt = 0;
    for(int i = 0; i< n ; i++){
        if(check(i,j,arr,n)){
            arr[i][j] = 'Q';
            cnt += solve(j+1,arr,n);
            arr[i][j] = '.';

        }
    }
    return cnt;
}
    
int totalNQueens(int n) {
    vector<string> arr(n,string(n,'.'));
    return solve(0,arr,n);
}

int main(){
    int n = 7;
    cout << totalNQueens(n) << endl;
    return 0;
}