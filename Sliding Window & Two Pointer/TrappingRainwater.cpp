// 42. Trapping Rain Water

// Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it can trap after raining.

// Using extra space for prefixSum and suffixSum Arrays => O(2n) space complexity
class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> prefixMax(n), suffixMax(n);

        prefixMax[0] = height[0];
        for (int i = 1; i < n; i++) {
            prefixMax[i] = max(height[i], prefixMax[i - 1]);
        }

        suffixMax[n - 1] = height[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            suffixMax[i] = max(suffixMax[i + 1], height[i]);
        }

        int total = 0;
        for (int i = 0; i < n; i++) {
            total += min(prefixMax[i], suffixMax[i]) - height[i];
        }
        return total;
    }
};

// Without any extra space => O(1) space complexity
class Solution2 {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int leftMax = 0, rightMax = 0, total = 0;
        int low = 0, high = n - 1;
      
        while (low < high) {
            if (height[low] <= height[high]) {
                if (height[low] < leftMax) {
                    total += leftMax - height[low];
                } else {
                    leftMax = height[low];
                }
                low++;
            } else {
                if (height[high] < rightMax) {
                    total += rightMax - height[high];
                } else {
                    rightMax = height[high];
                }
                high--;
            }
        }
        return total;
    }
};
