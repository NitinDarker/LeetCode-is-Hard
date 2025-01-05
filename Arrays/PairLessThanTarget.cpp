/* Count Pairs whose sum is less than target - GFG Daily Problem
Given an array arr[] and an integer target. You have to find the number of pairs in the array whose sum is strictly less than the target.
*/
class Solution {
  public:
    int countPairs(vector<int> &arr, int target) {
        sort(arr.begin(), arr.end());
        int count = 0;
        int i = 0, j = arr.size() - 1;
        while (i < j) {
            if (arr[i] + arr[j] < target) {
                count += (j - i); // Good implementation - Think about it
                i++;
            } else {
                j--;
            }
        } 
        return count;
    }
};
