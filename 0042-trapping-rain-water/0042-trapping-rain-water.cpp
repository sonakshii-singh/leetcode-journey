class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int l = 0, r = n - 1, sum = 0;
        int leftMax = height[l], rightMax = height[r];
        while (l < r) {
            if (height[l] <= height[r]) {
                if (height[l] < leftMax)
                    sum += leftMax - height[l];
                else
                    leftMax = height[l];
                l++;

            } else {
                if (height[r] < rightMax)
                    sum += rightMax - height[r];

                else
                    rightMax = height[r];
                r--;
            }
        }
        return sum;
    }
};