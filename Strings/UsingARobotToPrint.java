// https://leetcode.com/problems/using-a-robot-to-print-the-lexicographically-smallest-string/description/?envType=daily-question&envId=2025-06-06
import java.util.Stack;

class Solution {
    public String robotWithString(String s) {
        int[] freq = new int[26];
        for (int i = 0; i < s.length(); i++) {
            freq[s.charAt(i) - 97]++;
        }

        StringBuilder paper = new StringBuilder();
        int p = 0; // Pointer for string s
        Stack<Character> st = new Stack<>(); // String t

        // i pointer is for freq array
        for (int i = 0; i < 26; i++) {
            if (p == s.length()) break;
            if (freq[i] == 0) continue;

            while (!st.isEmpty() && st.peek() <= (i + 97)) {
                paper.append(st.pop());
            }

            while (freq[i] != 0) {
                while (s.charAt(p) != (i + 97)) {
                    st.push(s.charAt(p));
                    freq[s.charAt(p) - 97]--;
                    p++;
                }
                paper.append(s.charAt(p));
                p++;
                freq[i]--;
            }
        }
        while (!st.isEmpty()) {
            paper.append(st.pop());
        }
        return paper.toString();
    }
}
