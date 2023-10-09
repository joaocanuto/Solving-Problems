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

int solve(int x){
    int res = 0;
    while(x != 1 << (n-1)){
        if( x < 1 << (n-1)){
            res++;
            x = x*2;
        } else {
            x = (1 << n) - x;
        }
    }
    return res;
}

signed main() {
    int x;
    cin >> n >> x;
    cout << solve(x) << endl;
    return 0;
}
