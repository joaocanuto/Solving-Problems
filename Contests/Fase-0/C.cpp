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
  int N, B; cin>>N>>B;
  int n2 = 4*N*N;
  int ocurrences = 0;
  int m = -10000000;
  // vou iterar sobre os numeros indo de Nˆ2 - 2N ate Nˆ2
  for(int i = 1; i*i <= n2; i++){
    if (abs(i*i - B) == 0) continue;
    if(abs(i*i - B) % (2*N+1) == 0){
      //bug(abs(i*i - B));
      m = max(m, i*i);
    }
  }
  cout << m << endl; 
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
