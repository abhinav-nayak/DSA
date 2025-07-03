// Problem: https://neetcode.io/problems/is-palindrome?list=neetcode150 

class Solution {
public:
    bool isPalindrome(string s) {
        // Using converging 2 pointers
        int i=0, j=s.length()-1;
        bool isAlpha, isNum, satisfy;
        while(i<j){
            // Skip non-alphanumeric values for 1st pointer
            isAlpha = ((s[i]>='A' && s[i]<='Z') || (s[i]>='a' && s[i]<='z')) ? true : false;
            isNum =(s[i]>='0' && s[i]<='9') ? true : false;
            if (!isAlpha && !isNum){
                i++;
                continue;
            }

            // Skip non-alphanumeric values for 2nd pointer
            isAlpha = ((s[j]>='A' && s[j]<='Z') || (s[j]>='a' && s[j]<='z')) ? true : false;
            isNum =(s[j]>='0' && s[j]<='9') ? true : false;
            if (!isAlpha && !isNum){
                j--;
                continue;
            }

            // since values pointed by both pointers are alpha-numeric compare them
            satisfy = (tolower(s[i])==tolower(s[j])) ? true : false;
            if(!satisfy)
                return false;
            i++; j--;
        }

        return true;
    }
};

// Time complexity: O(n)
// Space complexity: O(1)
