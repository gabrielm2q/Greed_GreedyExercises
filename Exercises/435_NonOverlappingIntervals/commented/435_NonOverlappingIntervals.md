# Exercício 435 do LeetCode: Non-overlapping Intervals

[**Link do Problema**](https://leetcode.com/problems/non-overlapping-intervals/description/)

## Código comentado

```
#include <bits/stdc++.h>
#define ll long long

using namespace std;
using ii = pair<int, int>;

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        /*
            Comparador que será usado no MIN HEAP.
            Ele visa ordenar os intervalos por ordem crescente
            de horários de término.
            Caso sejam iguais, ele ordena por horário de início.
        */
        struct compareByMinEndTime {
            auto operator ()(vector<int>& x, vector<int>& y) {
                return (x[1] == y[1] ? x[0] > y[0] : x[1] > y[1]);
            };
        };

        // Fila de prioridade (MIN HEAP) que será usada para armazenar os intervalos
        priority_queue<vector<int>, vector<vector<int>>, compareByMinEndTime> A;

        // Inserindo todos os intervalos recebidos na fila de prioridade
        for (auto i : intervals) A.push(i);

        int maxEndHour = INT_MIN, counter = 0;
        while (!A.empty()) {
            /*
                Se o intervalo tiver hora de início maior ou igual ao 
                maior horário de término já considerado, seu horário de
                término será armazenado em maxEndHour.

                Caso contrário, o intervalo será descartado e o contador
                de intervalos descartados será incrementado.
            */
            if (maxEndHour <= A.top()[0]) maxEndHour = A.top()[1];
            else ++counter;

            A.pop();
        }

        /*
            Conforme requerido pelo exercício, será retornado a 
            quantidade de intervalos descartados no total.
        */
        return counter;
    }
};
```
