#include <bits/stdc++.h>
#include <tuple>

#define bug(x) cerr << #x << "  >>>>>>>  " << x << '\n'

using namespace std;

#define ll long long

const ll maxn = 1e7;

bool comp(pair<int,int> a, pair<int,int> b){
    //if(a.first == b.first) return true;
    return a.second < b.second;
}

int main(){
    int n; cin >> n;
    vector<pair<int,int> > events;
    for(int i=0; i < n; i++){
        int ini, end; cin >> ini >> end;
        events.push_back(make_pair(ini,end));
    }
    stable_sort(events.begin(),events.end(),comp);
    int ans = 1;
    pair<int,int> last_event = events[0];
    for(int i=1; i < n; i++){
        pair<int,int> event = events[i];
        if(event.first >= last_event.second)
        {
            ans++;
            last_event = events[i];
        }
    }
    cout << ans << endl;

    return 0;
}
