#include <bits/stdc++.h>
using namespace std;

int main() {
    long long x, n, a, b, sum;
    cin >> x >> n;

    // Criar uma fila de prioridade (heap) que armazena os tamanhos dos cubos em ordem crescente
    priority_queue<int, vector<int>, greater<int>> heap;

    // Ler os tamanhos dos cubos e adicioná-los à fila de prioridade
    for (int i = 0; i < n; i++) {
        a;
        cin >> a;
        heap.push(a);
    }

    long long ans = 0; // Variável para armazenar o resultado final (total do tamanho dos cubos combinados)

    // Combinação dos cubos
    while (heap.size() > 1) {
        a = heap.top(); // Obter o menor cubo atual
        heap.pop();
        b = heap.top(); // Obter o próximo menor cubo
        heap.pop();
        sum = a + b; // Calcular a soma dos dois cubos
        ans += sum; // Adicionar a soma ao resultado final
        heap.push(sum); // Adicionar a soma à fila de prioridade para ser considerada nas próximas combinações
    }

    cout << ans << endl; // Imprimir o resultado final
    return 0;
}
