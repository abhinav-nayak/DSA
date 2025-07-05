// Problem: https://neetcode.io/problems/trapping-rain-water?list=neetcode150 

class Solution {
public:
    int trap(vector<int>& height) {
        int l=0, r=height.size()-1;
        int maxArea=0, area;
        int maxLeft=height[l];
        int maxRight=height[r];

        while(l<r){
            // Logic: Water held at each index = min(maxLeft, maxRight) - height[i]
            if(maxLeft<=maxRight){
                l++;
                area = maxLeft-height[l];
                if(area>=0){
                    maxArea += area;
                }
                if(height[l]>maxLeft)
                    maxLeft = height[l];
            }
            else
                r--;
                area = maxRight-height[r];
                if(area>=0){
                    maxArea += area;
                }
                if(height[r]>maxRight)
                    maxRight = height[r];
        }

        return maxArea;
    }
};

// Time complexity: O(n)
// Space complexity: O(1)

// Another solution is there with time complexity O(n) and space complexity also O(n). Logic is similar to 'Product of Array Except Self'.
// You can have maxLeft and maxRight arrays and solve it.