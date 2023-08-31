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

int a[200005];
int n, k;

bool check(int m){
    ull r = 0;
    rep(i,0,n){
        r += m/a[i];
        if(r >= k) return 1;
    }
    return 0;
}
int solve(){
    see(n,k);
    rep(i,0,n) see(a[i]);
    int h = 1e18;
    int l = 1;
    int ans = h;
    while(l <= h){
        int m = (l+h)/2;
        if (check(m)){
            ans = m;
            h = m - 1;
        }
        else l = m+1;
    }
    cout << ans << endl;
    return 0;
}

signed main(){
    IOS;
    //cin >> t;
    int t = 1;
    while(t--){
        solve();
    }

    // #ifndef ONLINE_JUDGE
    //     clock_t tStart = clock();
    //     cerr<<fixed<<setprecision(10)<<"\nTime Taken: "<<(double)(clock()- tStart)/CLOCKS_PER_SEC<<endl;
    // #endif
    return 0;
}
