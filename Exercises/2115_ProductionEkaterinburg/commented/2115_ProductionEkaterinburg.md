# Exercício 2115 do BeeCrowd: Production in Ekaterinburg

[**Link do Problema**](https://www.beecrowd.com.br/judge/en/problems/view/2115)

## Código comentado

```
#include <bits/stdc++.h>
#define ll long long

using namespace std;
using ii = pair<int, int>;

int main(void) {
    int N, entry1, entry2, time;
    
    // MIN Heap para armazenar tarefas em ordem crescente de horario inicial de disponibilidade
    priority_queue<ii, vector<ii>, greater<ii>> dp;

    while (cin >> N) {
        dp = priority_queue<ii, vector<ii>, greater<ii>>();
        time = 1; // O tempo inicial sempre sera igual a 1

        for (int i = 0; i < N; ++i) { 
            // Inserindo horario inicial de disponibilidade e tempo de processamento da tarefa
            cin >> entry1 >> entry2;
            dp.push(make_pair(entry1, entry2));
        }

        while (!dp.empty()) { // Enquanto houver tarefas...
            /*
                Se o horario em que a tarefa estara disponivel for maior que o tempo atual,
                deve-se esperar ela comecar para somar seu tempo de processamento.
                Caso contrario, basta somar seu tempo de processamento.
            */
            time += (dp.top().first > time ? (dp.top().first - time) + dp.top().second : dp.top().second);
            dp.pop();
        }

        cout << time << endl;
    }

    return 0;
}
```
