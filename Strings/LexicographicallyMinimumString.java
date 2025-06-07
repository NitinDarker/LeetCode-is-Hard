// https://leetcode.com/problems/lexicographically-minimum-string-after-removing-stars/description/?envType=daily-question&envId=2025-06-07
import java.util.ArrayList;
import java.util.HashMap;
import java.util.PriorityQueue;

class Solution {
    public String clearStars(String s) {
        PriorityQueue<Character> heap = new PriorityQueue<>();
        HashMap<Character, ArrayList<Integer>> mpp = new HashMap<>();
        boolean[] present = new boolean[s.length()];

        int idx = 0;
        while (idx < s.length()) {
            char ch = s.charAt(idx);
            if (ch == '*') {
                present[idx] = false;
                char smallest = heap.poll();
                present[mpp.get(smallest).getLast()] = false;
                mpp.get(smallest).removeLast();
            } else {
                present[idx] = true;
                heap.add(ch);
                if (!mpp.containsKey(ch)) {
                    ArrayList<Integer> arr = new ArrayList<>();
                    arr.add(idx);
                    mpp.put(ch, arr);
                } else {
                    ArrayList<Integer> arr = mpp.get(ch);
                    arr.add(idx);
                    mpp.put(ch, arr);
                }
            }
            idx++;
        }

        StringBuilder res = new StringBuilder();
        for (int i = 0; i < s.length(); i++) {
            if (present[i]) {
                res.append(s.charAt(i));
            }
        }
        return res.toString();
    }
}
