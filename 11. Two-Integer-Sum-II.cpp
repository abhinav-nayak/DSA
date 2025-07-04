// Problem: https://neetcode.io/problems/two-integer-sum-ii?list=neetcode150

// Hints that this is two-pointer problem and not hashing:
// 1. It is mentioned "Your solution must O(1) additional space.". Hashing uses O(n) space.
// 2. The input array is sorted.
//    A strong clue that the problem can be solved using two pointer technique:
//    (i)	If input data follows a predictable pattern like sorted array or palindromic string.
//    (ii)	A pair of values that satisfy a condition or generate a result.

#include<bits/stdc++.h>
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int i=0, j=numbers.size()-1;
        int sum;
        vector<int> result;
        while(i<j){
            sum=numbers[i]+numbers[j];
            if(sum>target)
                j--;
            else if (sum<target)
                i++;
            else{
                result.push_back(i+1);
                result.push_back(j+1);
                break;
            }
        }
        return result;
    }
};

// Time complexity: O(n)
// Space complexity: O(1)
