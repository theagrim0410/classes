#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;
bool check(vector<vector<char>>& board,int i ,int j ,char ch){
    vector<int> row(9, 0);
    vector<int> col(9, 0);
    vector<int> square(9, 0);

    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            char ch = board[i][j];
            if (ch == '.') continue;
            int no = ch - '0';       
            int pos = 1 << (no - 1); 

            if (row[i] & pos) return false;
            row[i] |= pos;

            if (col[j] & pos) return false;
            col[j] |= pos;

            int ind = (i / 3) * 3 + (j / 3);
            if (square[ind] & pos) return false;
            square[ind] |= pos;
        }
    }
    return true;
}

bool solve(vector<vector<char>>& board,int i ,int j){
    int n = board.size();
    if(i == n-1 && j == n) return true;
    if(j == n) {
        i++;
        j = 0;
    }

    if(board[i][j] != '.') return solve(board,i,j+1);
    for(int no = 1 ; no <=9 ; no++){
        char ch = no + '0';
        if(check(board,i,j,ch)){
            board[i][j] = ch;
            if(solve(board,i,j+1)) return true;
            board[i][j] = '.';
        }
    }
    return false;
}

void solveSudoku(vector<vector<char>>& board) {
    if(solve(board,0,0)) return ;
}

int main(){
    vector<vector<char>> board = {
        {'5','3','.','.','7','.','.','.','.'},
        {'6','.','.','1','9','5','.','.','.'},
        {'.','9','8','.','.','.','.','6','.'},
        {'8','.','.','.','6','.','.','.','3'},
        {'4','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','2','.','.','.','6'},
        {'.','6','.','.','.','.','2','8','.'},
        {'.','.','.','4','1','9','.','.','5'},
        {'.','.','.','.','8','.','.','7','9'}
    };

    solveSudoku(board);

    for(const auto& row : board){
        for(const auto& ch : row){
            cout << ch << " ";
        }
        cout << endl;
    }

    return 0;
}