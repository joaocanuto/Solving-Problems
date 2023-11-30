//
//  main.cpp
//  CodePlayground
//
//  Created by Joao Guilherme Araujo Canuto on 30/11/23.
//

#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5+5;
const int inf = 1e9;

vector<int> graph[maxn];
int vis[maxn];
int dist[maxn];

int main() {
    int n, m; cin >> n >> m;
    for(int i = 0; i < m; i++){
        int a, b; cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);

    }
    
    for(int i=1; i <= n; i++) dist[i] = inf;
    dist[1] = 0;
    queue<int> q;
    q.push(1);
    while(!q.empty()){
        int node = q.front();
        q.pop();
        for(auto neigh: graph[node]){
            if(dist[neigh] != inf) continue;
            vis[neigh] = node;
            dist[neigh] = dist[node] + 1;
            q.push(neigh);
        }
    }
    if(dist[n] == inf) return cout << "IMPOSSIBLE" << endl,0;
    cout << dist[n] + 1 << endl;
    vector<int> ans; ans.push_back(n);
    while(n != 1){
        n = vis[n];
        ans.push_back(n);
    }
    for(int i = (int)ans.size() - 1; i > -1; i--){
        cout << ans[i] << " ";
    }
    return 0;
}
