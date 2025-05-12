// https://leetcode.com/problems/finding-3-digit-even-numbers/description/?envType=daily-question&envId=2025-05-12
import java.util.ArrayList;
import java.util.List;

class Solution {
    public int[] findEvenNumbers(int[] digits) {
        int[] freq = new int[10];
        for (int digit : digits) {
            freq[digit]++;
        }
        List<Integer> res = new ArrayList<>();
        for (int i = 1; i < 10; i++) {
            if (freq[i] == 0) continue;
            freq[i]--;
            for (int j = 0; j < 10; j++) {
                if (freq[j] == 0) continue;
                freq[j]--;
                for (int k = 0; k < 10; k++) {
                    if (((k & 1) == 1) || freq[k] == 0) continue;
                    int num = (i * 100) + (j * 10) + k;
                    res.add(num);
                }
                freq[j]++;
            }
            freq[i]++;
        }
        int[] ans = new int[res.size()];
        for (int i = 0; i < res.size(); i++) {
            ans[i] = res.get(i);
        }
        return ans;
    }
}
