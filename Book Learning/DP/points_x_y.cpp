#include <bits/stdc++.h>
#include <tuple>

#define bug(x) cerr << #x << "  >>>>>>>  " << x << '\n'

using namespace std;

#define ll long long

const ll maxn = 1e7;

struct point {
    int x, y;
    bool operator<(const point &p) const {
        if (x == p.x) return y < p.y;
        else return x > p.x;
    }
};

int main(){
    vector<point> v;
    point p;
    p.x = 1, p.y = 2;
    point y;
    y.x = 2, y.y = 1;
    v.push_back(p);
    v.push_back(y);
    sort(v.begin(), v.end());
    for(auto k : v){
        cout << k.x << " " << k.y << endl;
    }
    return 0;
}
