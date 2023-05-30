#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<pair<int, int>> v(n);

    for (int i = 0; i < n; i++) 
    {
        cin >> v[i].second >> v[i].first; 
    } // lê o horário de início, horário de término

    sort(begin(v), end(v)); // ordena por horário de término

    int maxMovies = 0;
    multiset<int> end_times; // horários em que os membros terminarão de assistir aos filmes

    for (int i = 0; i < k; ++i) 
    {
        end_times.insert(0);
    }

    for (int i = 0; i < n; i++) {
        auto it = end_times.upper_bound(v[i].second);

        if (it == begin(end_times)) 
        {
            continue;
        }

        // atribui o filme para ser assistido pelo membro do multiset que termina no horário *prev(it)
        end_times.erase(--it);
        // membro agora termina de assistir no horário v[i].first
        end_times.insert(v[i].first);

        ++maxMovies;
    }

    cout << maxMovies << endl;

    return 0;
}
