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
 
 
const ll inf = INT_MAX;
const ld pi = acos(-1.0);
const ll md = 1e9 + 7;
 
const int maxn = 1e4; 
 
 
int solve(){
    int n,x; cin >> n >> x;
    vector<int> coins(n, 0);
    vector<int> count(x+5, 0);
    
    rep(i,0,n) cin >> coins[i];
    count[0] = 1;
    for(int i = 1; i <= x; i++){
        for(int j = 0; j < (int)coins.size(); j++){
            int c = coins[j];
            if(i - c >= 0){
                count[i] += count[i-c];
                count[i] = count[i]%md;
            }
        }
    }
    cout << count[x] << endl;
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