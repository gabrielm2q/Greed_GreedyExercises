#include <bits/stdc++.h>
#define ll long long

using namespace std;
using ii = pair<int, int>;

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        struct compareByMinEndTime {
            auto operator ()(vector<int>& x, vector<int>& y) {
                return (x[1] == y[1] ? x[0] > y[0] : x[1] > y[1]);
            };
        };

        priority_queue<vector<int>, vector<vector<int>>, compareByMinEndTime> A;

        for (auto i : intervals) A.push(i);

        int maxEndHour = INT_MIN, counter = 0;
        while (!A.empty()) {
            if (maxEndHour <= A.top()[0]) maxEndHour = A.top()[1];
            else ++counter;

            A.pop();
        }

        return counter;
    }
};