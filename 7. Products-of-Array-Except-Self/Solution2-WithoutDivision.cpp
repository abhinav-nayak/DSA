// Problem: https://neetcode.io/problems/products-of-array-discluding-self?list=neetcode150 

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> preProduct(nums.size());
        vector<int> postProduct(nums.size());

        // Calculate product of all elements before the element (including self)
        for(int i=0; i<nums.size(); i++) {
            if (i>0)
                preProduct[i] = preProduct[i-1] * nums[i];
            else
                preProduct[i] = nums[i];
        }

        // Calculate product of all elmenets after the element (including self)
        for(int i=nums.size()-1; i>=0; i--) {
            if (i<=nums.size()-2)
                postProduct[i]=postProduct[i+1] * nums[i];
            else
                postProduct[i]=nums[i];
            
        }

        // Calculate result by multiplying preProduct and postProduct
        vector<int> result(nums.size());
        for(int i=0; i<nums.size(); i++) {
            if (i<1)
                result[i]=postProduct[i+1];
            else if (i>=nums.size()-1)
                result[i]=preProduct[i-1];
            else
                result[i]=preProduct[i-1] * postProduct[i+1];
        }

        return result;
                
    }
};

// Time complexity - O(n)
// Space complexity - O(n)
