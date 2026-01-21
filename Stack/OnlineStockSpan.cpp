// https://leetcode.com/problems/online-stock-span/
class StockSpanner {
    vector<int> arr;
    stack<int> st;
    int days;

  public:
    StockSpanner() {
        days = 0;
    }

    int next(int price) {
        arr.push_back(price);
        while (!st.empty() && arr[st.top()] <= price) {
            st.pop();
        }
        int pge = -1;
        if (!st.empty()) pge = st.top();
        st.push(days);
        return days++ - pge;
    }
};
