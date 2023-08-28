#include <bits/stdc++.h>
#include <tuple>

#define bug(x) cerr << #x << "  >>>>>>>  " << x << '\n'

using namespace std;

#define ll long long

const ll maxn = 1e7;

bool comp(pair<int,char> a, pair<int,char> b){
    //if(a.first == b.first) return true;
    return a.first < b.first;
}

int main(){
    int n; cin >> n;
    vector<pair<int,char> > cust;
    for(int i=0; i < n; i++){
        int a, b; cin >> a >> b;
        cust.push_back(make_pair(a,'i'));
        cust.push_back(make_pair(b,'o'));
    }
    stable_sort(cust.begin(),cust.end(), comp);

    int i = 0, j = 0; 
    int cont = 0, ans = -1;
    for(int i = 0; i < cust.size(); i++){
        pair<int,char> x = cust[i];
        if(cust[i].second == 'i') cont++;
        else cont--;

        //cout << x.first << " " << x.second << " " << cont << endl;
        ans = max(cont,ans);
    }
    cout << ans << endl; 
    return 0;
}
