#include <bits/stdc++.h>
using namespace std;

template<typename... T>
void see(T&... args) { ((cin >> args), ...);}
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
#define all(x) x.begin(),x.end()
#define rep(i,a,b) for (int i=a; i<b; ++i)


const ll inf = INT_MAX;
const ld pi = acos(-1.0);
const ll md = 1000000007;

//Removendo digitos para ter o numero proximo a zero.
const int N = 1e6+5;
int dp[N];

int solve(){
    int n; cin >> n;
    dp[0] = 0;
    for(int i=1; i <= n; i++){
        int temp = i;
        int minSteps = 1e6+2;
        while(temp != 0){
            int di = temp%10;
            temp = temp/10;
            if(di == 0) continue;
            minSteps = min(minSteps, 1 + dp[i - di]);
        }
        dp[i] = minSteps;
    }
    cout << dp[n] << endl;
    return 0;
}

signed main() {
    IOS
    solve();
    return 0;
}
