// Print the longest common subsequence
string lcs(string text1, string text2) {
    int n = text1.length(), m = text2.length();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (text1[i - 1] == text2[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    string res = "";
    int i = n, j = m;
    while (i > 0 && j > 0) {
        if (text1[i - 1] == text2[j - 1]) {
            res = text1[i-1] + res;
            i--;
            j--;
        }
        else if (text1[i - 1] > text2[j - 1]) i--;
        else j--;
    }
    return res;
}

int main() {
    string text1 = "abcdefgh";
    string text2 = "bdgekffhg";
    cout << "The Longest Common Subsequence is: " << lcs(text1, text2);
}
