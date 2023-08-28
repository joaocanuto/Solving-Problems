#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define int long long
#define vi vector<int>
#define pii pair<int,int>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define endl '\n'
#define ld long double
#define mset(A,X) memset(A,X,sizeof A)
#define bug(x) cerr << #x << "  >>>>>>>  " << x << '\n'
#define sz size()

int solve(){
  int x; cin>>x;
  int ant = x;
  while(x > 7)
  {
    cout << x << endl;
    x = 3*(x/10) + x%10;
    if (x == ant) return 0;
    ant = x;
  }
  cout << x << endl;
  return 0;
}

signed main(){
	//ios_base::sync_with_stdio(false);cin.tie(NULL);

	int t;

	//cin>>t; //*/
	t = 1; //*/
	while(t--) solve();

	return 0;
}
