// https://leetcode.com/problems/minimize-the-maximum-difference-of-pairs/description/?envType=daily-question&envId=2025-06-13
import java.util.Arrays;

class Solution {
    int countPairs(int[] arr, int maxDiff) {
        int pairs = 0;
        int i = 0;
        while (i < arr.length - 1) {
            int diff = arr[i+1] - arr[i];
            if (diff <= maxDiff) {
                pairs++;
                i += 2;
            } else {
                i++;
            }
        }
        return pairs;
    }

    public int minimizeMax(int[] nums, int p) {
        Arrays.sort(nums);
        int low = 0, high = nums[nums.length - 1] - nums[0];
        while (low <= high) {
            int mid = low + ((high - low)/2);
            int pairs = countPairs(nums, mid);
            if (pairs < p) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return low;
    }
}
