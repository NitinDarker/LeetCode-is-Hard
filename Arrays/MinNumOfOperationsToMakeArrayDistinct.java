// https://leetcode.com/problems/minimum-number-of-operations-to-make-elements-in-array-distinct/
import java.util.*;

class Solution {
    public int minimumOperations(int[] nums) {
        Map<Integer, Integer> freq = new HashMap<>();
        Set<Integer> targetNums = new HashSet<>();

        for (int num : nums) {
            if (freq.containsKey(num)) {
                targetNums.add(num);
            }
            freq.put(num, freq.getOrDefault(num, 0) + 1);
        }

        int opCount = 0;
        int start = 0;

        while (!targetNums.isEmpty()) {
            for (int i = start; i < start + 3 && i < nums.length; i++) {
                int count = freq.get(nums[i]);
                if (count == 1) {
                    freq.put(nums[i], 0);
                } else if (count == 2) {
                    freq.put(nums[i], 1);
                    targetNums.remove(nums[i]);
                } else {
                    freq.put(nums[i], count - 1);
                }
            }
            opCount++;
            start += 3;
        }

        return opCount;
    }
}
