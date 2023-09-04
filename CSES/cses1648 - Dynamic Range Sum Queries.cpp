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

const int N = 3e5;
int a[N], seg[4*N];
int n,q; 

void update(int id, int val, int i = 0, int l = 0, int r = n - 1) {
	if(id>r or id<l) return;
	if(l == r){
		if(l == id) seg[i] = val;
		return;
	}
	int mid = (l+r)/2;
	update(id, val, i*2+1, l, mid); // leftchild = 2*i + 1 
	update(id, val, i*2+2, mid + 1, r); // rightchild = 2*i +2
	seg[i] = seg[i*2+1] + seg[i*2+2];
}
int getsum(int L, int R, int i = 0, int l = 0, int r = n - 1) {
	if (l> R or  r< L) return 0;
	if (l>=L and r<=R) return seg[i];
	int mid = (l+r)/2;
	return getsum(L, R, i*2+1, l, mid) + getsum(L, R, i*2+2, mid+1, r);
}



int solve(){
    cin >> n >> q;
    rep(i,0,n) cin >> a[i];
    rep(i,0,n) update(i,a[i]);
    while(q--){
        int type; cin >> type;
        if(type == 1){
            int id, val; cin >> id >> val; id--;
            update(id, val);
        } else {
            int left, right; cin>> left >> right; left--; right--;
            cout << getsum(left,right) << endl;
        }
    }
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
