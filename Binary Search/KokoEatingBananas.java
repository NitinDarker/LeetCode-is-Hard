// https://www.geeksforgeeks.org/problems/koko-eating-bananas/1
// https://leetcode.com/problems/koko-eating-bananas/
class Solution {
    private int maxElement(int[] arr) {
        int maxi = arr[0];
        for (int it : arr) {
            if (it > maxi) maxi = it;
        }
        return maxi;
    }

    private double eatingTime(int[] arr, int speed) {
        double time = 0;
        for (int it : arr) {
            time += Math.ceil((double) it / (double) speed);
        }
        return time;
    }

    public int minEatingSpeed(int[] arr, int k) {
        int low = 1, high = maxElement(arr);
        while (low <= high) {
            int mid = low + ((high - low) / 2);
            double time = eatingTime(arr, mid);
            if (time > (double) k) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return low;
    }
}
