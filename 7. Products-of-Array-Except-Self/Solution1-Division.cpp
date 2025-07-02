// Problem: https://neetcode.io/problems/products-of-array-discluding-self?list=neetcode150 

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        // Calculate product of all elements
        int product=1;
        bool zeroPresent=false, multipleZeroPresent=false;
        for(int n:nums) {
            if (n != 0)
                product = product * n;
            else{
                if (zeroPresent)
                    multipleZeroPresent=true;
                zeroPresent=true;
            }
        }

        // Form the output array
        vector<int> result(nums.size()); // Initializing size is needed to avoid segfault error
        for(int i=0; i<nums.size(); i++) {
            if (multipleZeroPresent)
                result[i]=0;
            else if (!zeroPresent)
                result[i]=product/nums[i];
            else if (zeroPresent && nums[i] == 0)
                result[i]=product;
        }

        return result;
    }
};

// Time complexity - O(n)
// Space complexity - O(n)
