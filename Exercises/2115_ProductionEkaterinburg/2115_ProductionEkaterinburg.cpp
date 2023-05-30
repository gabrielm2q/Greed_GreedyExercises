#include <bits/stdc++.h>
#define ll long long

using namespace std;
using ii = pair<int, int>;

int main(void) {
    int N, entry1, entry2, time;
    priority_queue<ii, vector<ii>, greater<ii>> dp;

    while (cin >> N) {
        dp = priority_queue<ii, vector<ii>, greater<ii>>();
        time = 1;

        for (int i = 0; i < N; ++i) { 
            cin >> entry1 >> entry2;
            dp.push(make_pair(entry1, entry2));
        }

        while (!dp.empty()) { 
            time += (dp.top().first > time ? (dp.top().first - time) + dp.top().second : dp.top().second);
            dp.pop();
        }

        cout << time << endl;
    }

    return 0;
}