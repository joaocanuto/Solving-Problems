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
#define all(x) x.begin(),x.end()
#define rep(i,a,b) for (int i=a; i<b; ++i)


const ll inf = INT_MAX;
const ld pi = acos(-1.0);
const ll md = 1000000007;
const int maxn = 1e6; 

int solve(){
    int d, c, r; cin >> d >> c >> r;
    vector<int> cc;
    for(int i=0; i < c; i++){
        int x; cin >> x;
        cc.pb(x);
    }
    for(int j=0; j < r; j++){
        int x; cin >> x; 
        d += x;
    }
    int ans = 0;
    for(int i=0; i < cc.size(); i++){
        d -= cc[i];
        if( d < 0 )break; 
        ans++;
    }
    cout << ans + r << endl;
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
