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

const int MAX = 1e5 + 10;

struct Point {
    int x,y, id;

    int cross(Point b){
        return x*b.y - y*b.x;
    }
    Point operator-(Point &rhs){
        Point result;
        result.x = x - rhs.x;
        result.y = y - rhs.y;
        return result;
    }

    bool operator<(Point &rhs){
        if(x == rhs.x) return y < rhs.y;
        return x < rhs.x;
    }
};

bool least_id(Point &a, Point &b){
    return a.id < b.id;
}

int n; 
Point pnts[MAX];
vector<Point> conv, upper, lower;

void findconvex(){
    int sz_upper = 0, sz_lower = 0;
    for(int i=0; i<n; i++){
        while(sz_upper >= 2 && (pnts[i] - upper[sz_upper-2]).cross(upper[sz_upper-1] - upper[sz_upper-2]) < 0){
            upper.pop_back();
            sz_upper--;
        }
        upper.push_back(pnts[i]);
        sz_upper++;

        while(sz_lower >= 2 && (pnts[i] - lower[sz_lower-2]).cross(lower[sz_lower-1] - lower[sz_lower-2]) > 0){
            lower.pop_back();
            sz_lower--;
        }
        lower.push_back(pnts[i]);
        sz_lower++;
    }

    for(int i=0; i<sz_upper-1; i++) conv.push_back(upper[i]);
    for(int i=sz_lower-1; i>0; i--) conv.push_back(lower[i]);
}

void solve(){
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> pnts[i].x >> pnts[i].y;
        pnts[i].id = i+1;
    }
    sort(pnts, pnts + n);
    findconvex();
    sort(conv.begin(), conv.end(), least_id);
    set<int> id;
    for(int i=0; i<conv.size(); i++) id.insert(conv[i].id);
    for(auto i : id) cout << i << " ";
    cout << endl;
}

signed main() {
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