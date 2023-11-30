#include <bits/stdc++.h>
#define bug(x) cerr << #x << "  >>>>>>>  " << x << '\n'

using namespace std;


const long long maxn = 1e3+5;

/**
Elemento ->
    Visitado :
        Mov : U,D,R,L, #
    Nao visitado:
        A,B,.
 
 **/

char graph[maxn][maxn];
pair<int,int> s,t;
int n, m;


map<char, bool> checkIsVisited = {
    {'U',true},
    {'D',true},
    {'R',true},
    {'#',true},
    {'L',true},
    {'A', false},
    {'B', false},
    {'.',false}
};


map<char, pair<int,int>> increments = {
    {'U',{-1,0}},
    {'D',{1,0}},
    {'R',{0,1}},
    {'L',{0,-1}}
};

void bfs(){
    queue<pair<int,int>> q;
    q.push(s);
    while(!q.empty()){
        auto pos_atual = q.front();
        q.pop();
        for(auto increment: increments){
            char mov_letter = increment.first;
            auto [mov_fi,mov_se] = increment.second;
            auto pos_test = make_pair(pos_atual.first + mov_fi, pos_atual.second + mov_se);
            auto [i,j] = pos_test;
            if(i > n - 1 || j > m - 1 || i < 0 || j < 0) continue;
            if(checkIsVisited.at(graph[i][j])) continue;
            graph[i][j] = mov_letter;
            q.push(pos_test);
        }
    }
}

int main() {
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> graph[i][j];
            if(graph[i][j] == 'A') s = make_pair(i, j);
            if(graph[i][j] == 'B') t = make_pair(i, j);
        }
    }
    bfs();
    auto [i,j] = t;
    if(graph[i][j] == 'B'){
        cout << "NO" << endl;
        return 0;
    }
    string ans;
    while( !(i == s.first && j == s.second) ){
        ans += graph[i][j];
        auto mov = increments.at(graph[i][j]);
        i = i - mov.first;
        j = j - mov.second;
    }
    reverse(ans.begin(), ans.end());
    cout << "YES" << endl;
    cout << ans.size() << endl;
    cout << ans << endl;
    return 0;
}
