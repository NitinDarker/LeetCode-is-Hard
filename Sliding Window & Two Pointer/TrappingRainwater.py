# https://leetcode.com/problems/trapping-rain-water/
from typing import List

# O(2n) -> Space Complexity
class Solution1:
    def trap(self, height: List[int]) -> int:
        n = len(height)
        if n == 0: return 0
        
        prefixMax: List[int] = [height[0]] * n
        for i in range(1, n):
            prefixMax[i] = max(prefixMax[i-1], height[i])
            
        suffixMax: List[int] = [height[n-1]] * n
        for i in range(n-2, -1, -1):
            suffixMax[i] = max(suffixMax[i+1], height[i])
            
        res = 0
        for i in range(0, n):
            res += min(prefixMax[i], suffixMax[i]) - height[i]
        return res
    
# O(1) -> Space Complexity
class Solution:
    def trap(self, height: List[int]) -> int:
        n = len(height)
        l, r = 0, n-1
        leftMax, rightMax, res = 0, 0, 0
        while l < r:
            if height[l] <= height[r]:
                if leftMax > height[l]:
                    res += leftMax - height[l]
                else: 
                    leftMax = height[l]
                l += 1
            else:
                if rightMax > height[r]:
                    res += rightMax - height[r]
                else:
                    rightMax = height[r]
                r -= 1
        return res
