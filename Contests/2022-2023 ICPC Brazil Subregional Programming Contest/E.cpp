/* Online C++ Compiler and Editor */
#include <bits/stdc++.h>

#define long long int

using namespace std;

const int maxn = 1e7+10;

int vis[maxn];

signed main()
{
    int n; cin >> n;
    int ans = 0;
    for(int i = 0; i < n; i++){
        int aux; cin >> aux;
        if(vis[aux] == 0){
            ans++;
        }
        else {
            vis[aux]--;
        }
        vis[aux-1]++;
    }
    cout << ans << endl;
    return 0;
}