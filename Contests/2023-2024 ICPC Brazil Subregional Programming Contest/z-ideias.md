GYM: https://codeforces.com/gym/104555
### M: 
Link: https://codeforces.com/gym/104555/problem/M

Ideia: Floyd Warshall

dist -> atualiza seguindo a logica do Floyd Warshall
dist2 -> atualiza somente quando eu puder fazer um voo da seguinte forma
se eu vou de i-> j (a minha escala tem que ser: um voo i -> k e k -> j de modo que 
k != j e k != i. 
se é uma escala possivel, eu vejo o menor custo no meu vetor de dist nessas posicoes.

Ou seja, o meu dist -> atualiza pegando os menores custos.
O meu dist2 -> atualiza somente quando seguir a ideia das escalas

E no final eu comparao com os meus custos iniciais.

Links:
Codigo com a ideia : https://github.com/Rotzen823/Problemas-de-Programacion-Competitiva/blob/069a013fff7ee4c273d2d688aac47357e3a9599e/ICPC/2023%20ICPC/2023-2024%20ICPC%20Brazil%20Subregional%20Programming%20Contest/M%20-%20Maximizing%20Flight%20Efficiency.cpp
Algoritmo usado : https://www.geeksforgeeks.org/floyd-warshall-algorithm-dp-16/