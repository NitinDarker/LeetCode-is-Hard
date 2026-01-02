// https://leetcode.com/problems/sort-colors/
class Solution {
public:
    void sortColors(vector<int>& arr) {
        int n = arr.size();
        int l = 0, r = n-1;
        
        int i = l;
        while (i <= r) {
            if (arr[i] == 0) {
                swap(arr[i], arr[l]);
                l++;
                i++;
            }
            else if (arr[i] == 2) {
                swap(arr[i], arr[r]);
                r--;
            } else {
                i++;
            }
        }
    }
};
