# 2023-2024 ICPC Brazil Subregional Programming Contest

# Nexts:

- [x]  A
- [x]  F
- [x]  L
- [x]  M
- [ ]  I
- [ ]  E
- [x]  G
- [ ]  C
- [ ]  H

## G: Convex Hull Trick

Codigo base para ideia:  [G - Maximizing Flight Efficiency.cpp](https://pastebin.com/a00BymHy)
Algoritmo usado : [Convex Hull](https://cp-algorithms.com/geometry/convex-hull.html#grahams-scan-algorithm)
## M: Floyd Warshall

- dist -> atualiza seguindo a logica do Floyd Warshall
- dist2 -> atualiza somente quando eu puder fazer um voo da seguinte forma
se eu vou de i-> j (a minha escala tem que ser: um voo i -> k e k -> j de modo que 
k != j e k != i. 
se é uma escala possivel, eu vejo o menor custo no meu vetor de dist nessas posicoes.

Ou seja, o meu dist -> atualiza pegando os menores custos.
O meu dist2 -> atualiza somente quando seguir a ideia das escalas

E no final eu comparo com os meus custos iniciais salvos no meu vetor.

<aside>
💡 Aparentemente estava tomando WA no caso teste 92, por tentar atualizar direto o meu dist sem validar a ideia das escalas.

</aside>

Links:
Codigo base para ideia : [M - Maximizing Flight Efficiency.cpp](https://github.com/Rotzen823/Problemas-de-Programacion-Competitiva/blob/069a013fff7ee4c273d2d688aac47357e3a9599e/ICPC/2023%20ICPC/2023-2024%20ICPC%20Brazil%20Subregional%20Programming%20Contest/M%20-%20Maximizing%20Flight%20Efficiency.cpp)

Algoritmo usado : [floyd-warshall-algorithm geeks-for-geeks](https://www.geeksforgeeks.org/floyd-warshall-algorithm-dp-16/)
