#include <bits/stdc++.h>
using namespace std;

#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pii>
#define pb push_back
#define F first
#define S second
#define ll long long
#define ull unsigned long long
#define int long long
#define ld long double
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define bug(x) cerr << #x << "  >>>>>>>  " << x << '\n'
#define bugmat(x,y,z) cerr << ">> [" << #x << "]" << "[" << #y << "] = " << #z << " << " << ">> [" << x << "]" << "[" << y << "] = " << z << " << " << '\n'
#define all(x) x.begin(),x.end()
#define rep(i,a,b) for (int i=a; i<b; ++i)

/*
Ideia:

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
*/

const ll inf = INT_MAX;
const ld pi = acos(-1.0);
const ll md = 1000000007;
const int maxn = 1e4; 

int adj[110][110];
int dist[110][110];
int dist2[110][110];

int solve(){
    int n; cin >> n; 
    for(int i=0; i < n; i++){
        for(int j=0; j < n; j++){
            cin >> adj[i][j];

            if(adj[i][j] == 0){
                dist[i][j] = 0;
                dist2[i][j] = 0;
            } else if(adj[i][j]){
                dist[i][j] = adj[i][j];
                dist2[i][j] = inf;
            } else {
                dist[i][j] = inf;
                dist2[i][j] = inf;
            }
        }
    }
    int ans = 0;
    for(int k=0; k < n; k++){
        for(int i=0; i < n; i++){
            for(int j=0; j < n; j++){
                dist[i][j] = min(dist[i][j],dist[i][k] + dist[k][j]);
                if(k != i && k != j){
                    dist2[i][j] = min(dist2[i][j], dist[i][k] + dist[k][j]);
                }    
            }
        }
    }

    for(int i=0; i < n; i++){
        for(int j=i+1; j < n; j++){
            if(adj[i][j] > dist2[i][j]){
                return cout << -1 << endl,0;
            }
            if(adj[i][j] == dist2[i][j]){
                ans++;
            }
        }
    }
    cout << ans << endl;
    return 0;
}

signed main(){
    IOS;
    int t = 1;
    //cin >> t;
    while(t--){
        solve();
    }

    // #ifndef ONLINE_JUDGE
    //     clock_t tStart = clock();
    //     cerr<<fixed<<setprecision(10)<<"\nTime Taken: "<<(double)(clock()- tStart)/CLOCKS_PER_SEC<<endl;
    // #endif
    return 0;
}
