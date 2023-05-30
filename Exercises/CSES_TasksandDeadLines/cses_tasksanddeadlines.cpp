#include <bits/stdc++.h>

using namespace std;

int compare(const void* a, const void* b) {
    pair<int, int> pa = *((pair<int, int>*)a);
    pair<int, int> pb = *((pair<int, int>*)b);
    return pa.first - pb.first;
}

int main() {
    int n;
    long long total = 0, result = 0;

    cin >> n;
    vector<pair<int, int>> tasks(n);

    for (int i = 0; i < n; i++){
        cin >> tasks[i].first >> tasks[i].second;
    }

    qsort(tasks.data(), n, sizeof(pair<int, int>), compare);

    total = 0;
    result = 0;

    for (int i = 0; i < n; i++) 
    {
        pair<int, int> task = tasks[i];
        total = total + task.first;
        result = result + task.second - total;
    }

    cout << result << endl;

    return 0;
}
