# Exercício Tasks and Deadlines do CSES

[**Link do Problema**](https://cses.fi/problemset/task/1630)

## Código comentado

```
#include <bits/stdc++.h>

using namespace std;

// Função de comparação para o qsort
int compare(const void* a, const void* b) {
    pair<int, int> pa = *((pair<int, int>*)a);
    pair<int, int> pb = *((pair<int, int>*)b);
    return pa.first - pb.first;
}

int main() {
    // Obter as entradas
    int n;
    long long total = 0, result = 0;

    cin >> n;
    vector<pair<int, int>> tasks(n);

    for (int i = 0; i < n; i++){
        cin >> tasks[i].first >> tasks[i].second;
    }

    // Ordenar as tarefas usando o qsort
    qsort(tasks.data(), n, sizeof(pair<int, int>), compare);

    total = 0;
    result = 0;

    for (int i = 0; i < n; i++) 
    {
        pair<int, int> task = tasks[i];      // Obtém a tarefa atual
        total = total + task.first;          // Atualiza o valor total somando a duração da tarefa atual
        result = result + task.second - total; // Calcula o resultado somando a diferença entre o valor da tarefa e o valor total acumulado até o momento
    }


    // Imprimir a saída
    cout << result << endl;

    return 0;
}
```
