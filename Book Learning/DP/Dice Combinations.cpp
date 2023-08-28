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

const int mod = 1e9+7;

int v[MAXN];

int solve() { 
    int n; cin >> n; 
    v[0] = 1;
    for(int i=1; i <= n; i++){
        for(int j = 1; j <= 6; j++){
            if(i - j >= 0)
                v[i] = (v[i] + v[i-j])%mod;
        }
    }
    cout << v[n] << endl;
    return 0;
}

signed main() {
	//ios_base::sync_with_stdio(false);cin.tie(NULL);
    int t;
    t = 1; //*/
    while (t--) solve();
    return 0;
}
