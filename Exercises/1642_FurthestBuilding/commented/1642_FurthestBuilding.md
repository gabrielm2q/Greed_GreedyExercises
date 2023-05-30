# Exercicio 1642 do LeetCode: Furthest Building You Can Reach

[**Link do Problema**](https://leetcode.com/problems/furthest-building-you-can-reach/)

## Código comentado

```
#include <bits/stdc++.h>
#define ll long long

using namespace std;
using ii = pair<int, int>;

class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        int heightDiff, totalBuildings = heights.size();
        priority_queue<int, vector<int>, greater<int>> gaps; // MIN_HEAP que sera utilizada para guardar os menores gaps
        
        for (int i = 1; i < totalBuildings; ++i) {
            heightDiff = heights[i] - heights[i-1];

            if (heightDiff > 0) { // Se o predio atual for menor que o proximo
                if (ladders > 0) { // Enquanto houver escadas, serao armazenados os gaps
                    gaps.push(heightDiff);
                    --ladders;
                } else {
                    if (gaps.empty()) { // Se nao houver nenhum gap no heap, serao usados os tijolos (se possivel)
                        if (heightDiff > bricks) return --i;
                        else {
                            gaps.push(heightDiff);
                            bricks -= heightDiff;
                        }
                    } else {
                        /*
                            Caso exista algum gap no heap, sera usado o menor gap 
                            entre o gap para o proximo predio e o menor gap do heap
                        */
                        if (heightDiff <= gaps.top()) {
                            if (heightDiff > bricks) return --i;
                            else bricks -= heightDiff;
                        } else {
                            if (gaps.top() > bricks) return --i;
                            else { 
                                /* 
                                    Se o gap do heap for a melhor opcao, o usaremos
                                    e armazenaremos o gap atual no heap
                                */
                                bricks -= gaps.top();
                                gaps.pop();
                                gaps.push(heightDiff);
                            }
                        }
                    }
                }
            }   
        }

        /* 
            Caso todos os predios sejam acessiveis, basta retornar 
            o valor maximo de predios
        */
        return --totalBuildings;
    }
};
```
