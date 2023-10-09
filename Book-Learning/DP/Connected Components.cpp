#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define int long long
#define vi vector<int>
#define pii pair<int,int>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define endl '\n'
#define ld long double
#define mset(A,X) memset(A,X,sizeof A)
#define bug(x) cerr << #x << "  >>>>>>>  " << x << '\n'
#define sz size()
#define MAXN 1000005
#define INF 10000000005
#define MAXG 1055

char graph[MAXG][MAXG]; 
int ans = 0;
int s_x[4] = {0, 1, 0, -1};
int s_y[4] = {1, 0, -1, 0};
int n, m; 

vector<vector<bool> > vis;

bool isValid(int x, int y) {
    if (x < 0 or x >= n or y < 0 or y >= m)
        return false;
    if (vis[x][y])
        return false;
    return true;
}

void dfs(int x, int y) {
    vis[x][y] = true;
    for (int i = 0; i < 4; i++) {
        int new_x = x + s_x[i];
        int new_y = y + s_y[i];
        if (isValid(new_x, new_y)) {
            dfs(new_x, new_y);
        }
    }
}

void connected_components() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!vis[i][j]) {
                dfs(i, j);
                ans++;
            }
        }
    }
}

int solve() { 
    cin >> n >> m;
    vis.resize(n, vector<bool>(m, false));
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            char c; cin >> c; 
            if (c == '#') {
                vis[i][j] = true;
            }
        }
    }

    connected_components();
    cout << ans << endl;
    return 0;
}

signed main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);
    int t;
    t = 1; //*/
    while (t--) solve();
    return 0;
}
