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

int n;
int k = 0;
const int maxn = 1e5 + 10;

const int N = 1e6;

vector<int> pr;
int lp[N+1];


void crivo(){
    for(int i = 2; i <= N; i++){
        //bug()
        if(lp[i] == 0){
            lp[i] = i;
            pr.emplace_back(i);
        }

        for(int j=0; j < (int)pr.size() && pr[j] <= lp[i] && i*pr[j] <= N; j++){
            lp[i*pr[j]] = pr[j];
        }
    }
}


int solve(){
    //pegamos os primos, convertemos pra strings
    int num; cin >> num;
    crivo();
    string s = to_string(num);
    vector<string> prims_dif;
    rep(i,0,pr.size()){
        string x = to_string(pr[i]);
        if(isDif(x)){

            prims_dif.push_back(x);
        }
    }
    rep(i,0,prims_dif.size()){
        string vs = to_string(pr[i]);
        bug(vs);
        bug(KMPSearch(vs, s));
        bug(vs.size());
        if(vs.size() >= 2 && KMPSearch(vs, s) > 0 ) return cout << vs << endl,0;
    }
    return cout << -1 << endl,0; 
}

signed main() {
    IOS
    int n; cin >> n;
    rep(i,0,n){
        solve();
    }
    return 0;
}
