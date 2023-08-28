#include <bits/stdc++.h>
#include <tuple>

#define bug(x) cerr << #x << "  >>>>>>>  " << x << '\n'

using namespace std;

#define fi first
#define se second

#define ll long long

const ll maxn = 1e7;

bool comp(pair<ll,ll> a, pair<ll,ll> b){
    return a.fi < b.fi;
}

int main(){
    ll n; cin >> n;
    vector<pair<ll,ll> > tasks;
    for(int i=0; i < n; i++){
        ll a, d; cin >> a >> d; 
        tasks.push_back(make_pair(a,d));
    }
    stable_sort(tasks.begin(), tasks.end(), comp);
    ll ans = 0;
    ll time = 0;
    for(int i=0; i < n; i++){
        //bug(time);
        //cout << tasks[i].fi << " " << tasks[i].se << " " << tasks[i].se - time << endl;
        time += tasks[i].fi;
        ans += tasks[i].se - time;
    }
    cout << ans << endl;
    return 0;
}
