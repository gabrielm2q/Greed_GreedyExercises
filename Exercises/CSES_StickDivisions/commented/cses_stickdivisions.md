#include <bits/stdc++.h>

using namespace std;

int main() {
    long long x, n, a, b, sum;

    cin >> x >> n;

    // Criar um vetor que armazena os tamanhos dos cubos
    vector<int> heap;

    for (int i = 0; i < n; i++) {
        cin >> a;
        heap.push_back(a);
    }

    long long result = 0; // Variável para armazenar o resultado final (total do tamanho dos cubos combinados)

    // Construir a heap a partir do vetor
    make_heap(heap.begin(), heap.end(), greater<int>());

    // Combinação dos cubos
    while (heap.size() > 1) {
        a = heap.front();
        pop_heap(heap.begin(), heap.end(), greater<int>());
        heap.pop_back(); 

        b = heap.front();
        pop_heap(heap.begin(), heap.end(), greater<int>());
        heap.pop_back(); 

        sum = a + b; 
        result = result + sum; 

        heap.push_back(sum); 
        push_heap(heap.begin(), heap.end(), greater<int>());
    }

    cout << result << endl; 

    return 0;

}
