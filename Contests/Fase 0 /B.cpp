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
    int N; cin>> N;
    vector<int> palpites;
    vector<int> respostas;

    for(int i = 0; i < N; i++){
        int x; cin >> x;
        palpites.pb(x);
    }

    for(int i = 0; i < N; i++){
        int x; cin >> x;
        respostas.pb(x);
    }

    int ans = 0;
    map<int,int> possivel;
    int maiorFreq= -1000;
    int pos = 0;
    for(int i = 0; i < N; i++){
        possivel[palpites[i] + respostas[i]]++;
        possivel[palpites[i] - respostas[i]]++;
        if (possivel[palpites[i] + respostas[i]] > maiorFreq){
            maiorFreq = possivel[palpites[i] + respostas[i]];
        }
        if (possivel[palpites[i] - respostas[i]] > maiorFreq){
            maiorFreq = possivel[palpites[i] - respostas[i]];
        }
    }
    int soma = 0;
    int div = 0;
    for(auto it = possivel.begin() ; it != possivel.end(); it++){
        //cout << it->first << " " << it->second << endl;
        int a = it->first;
        int b = it->second;
        if(it->second == maiorFreq){
            //cout << it->first << endl;
        }
    }
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
