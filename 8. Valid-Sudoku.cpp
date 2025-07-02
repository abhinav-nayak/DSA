#include <bits/stdc++.h>

// Problem: https://neetcode.io/problems/valid-sudoku?list=neetcode150 

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int i, j;
        // Check for unique elements in all rows
        for(i=0; i<9; i++) {
            unordered_set<char> seen;
            for(j=0; j<9; j++) {
                if(board[i][j] == '.')
                    continue;
                if(seen.count(board[i][j]))
                    return false;
                else
                    seen.insert(board[i][j]);
            }
        }

        // Check for unique elements in all columns
        for(j=0; j<9; j++) {
            unordered_set<char> seen;
            for(i=0; i<9; i++) {
                if(board[i][j] == '.')
                    continue;
                if(seen.count(board[i][j]))
                    return false;
                else
                    seen.insert(board[i][j]);
            }
        }

        // Check for unique elements in sub-boxes
        map<pair<int, int>, unordered_set<char>> squares;
        unordered_set<char> subSquare;
        for(i=0; i<9; i++) {
            for(j=0; j<9; j++) {
                if(board[i][j] == '.')
                    continue;
                subSquare = squares[{i/3, j/3}];
                if(subSquare.count(board[i][j]))
                    return false;
                else
                    subSquare.insert(board[i][j]);
                squares[{i/3, j/3}] = subSquare;
            }

        }    
    }
};

// Time complexity - O(n^2)
// Space complexity - O(n^2)
