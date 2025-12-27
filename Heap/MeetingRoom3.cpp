// https://leetcode.com/problems/meeting-rooms-iii/
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        long long m = meetings.size();
        vector<long long> count(n, 0);
        priority_queue<long long, vector<long long>, greater<long long>> available; 
        priority_queue<pair<long long, long long>, vector<pair<long long,long long>>, greater<pair<long long,long long>>> busy;
        // (end_time, room_no)

        sort(meetings.begin(), meetings.end());
        for (long long i = 0; i < n; i++) available.push(i);

        for (vector<int> &meet : meetings) {
            long long start = meet[0], end = meet[1];

            while (!busy.empty() && start >= busy.top().first) {
                long long room = busy.top().second;
                busy.pop();
                available.push(room);
            }

            if (available.empty()) {
                pair<long long, long long> t = busy.top(); // (end_time, room_no)
                busy.pop();
                long long duration = end-start;
                start = t.first;
                end = (long long)t.first + duration;
                available.push(t.second);
            }

            long long room = available.top();
            available.pop();
            count[room]++;
            busy.push({end, room});
        }

        long long maxInd = 0;
        for (long long i = 1; i < n; i++) {
            if (count[i] > count[maxInd]) {
                maxInd = i;
            }
        }
        return maxInd;
    }
};
