// Problem: https://neetcode.io/problems/search-2d-matrix?list=neetcode150 

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // Find m, n for given m*n matrix
        int n=matrix[0].size();
        int m=matrix.size();
    
        // We can visualize 2D matrix as 1D matrix
        // row number in 2D array = (index in 1D array)/n
        // column number in 2D array = (index in 1D array)%n
        // So, we will run bianry search of this imagianry 1D array.
        // Ierative binary search has less space complexity.
        int l=0, r=m*n-1;
        int mid, i, j;
        while(l<=r){
            mid=(l+r)/2;
            // Find row and column number of corresponding element in 2D matrix.
            i=mid/n;
            j=mid%n;
            if(target < matrix[i][j])
                r=mid-1;
            else if(target > matrix[i][j])
                l=mid+1;
            else
                return true;
        }

        return false;
    }
};

// Time complexity: O(log(m*n))
// Space complexity: O(1)
