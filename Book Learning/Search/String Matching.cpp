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

// KMP ALGORITHM
// O(n*log(n))

void computedLPSArray(string pat, int M, int* lps);

int KMPSearch(string pat, string txt)
{
  int ocurrences = 0;
    int M = pat.size();
    int N = txt.size();

    int lps[M];

    computedLPSArray(pat, M, lps);

    int i = 0;
    int j = 0;
    while (i < N) {
        if (pat[j] == txt[i]) {
            j++;
            i++;
        }

        if (j == M) {
            ocurrences++;
            j = lps[j - 1];
        }

        else if (i < N && pat[j] != txt[i]) {
            if (j != 0)
                j = lps[j - 1];
            else
                i++;
        }
    }
    return ocurrences;
}

void computedLPSArray(string pat, int M, int* lps)
{
    int len = 0;

    lps[0] = 0;

    int i = 1;
    while (i < M) {
        if (pat[i] == pat[len]) {
            len++;
            lps[i] = len;
            i++;
        }

        else
        {
            if (len != 0) {
                len = lps[len - 1];
            }

            else
            {
                lps[i] = 0;
                i++;
            }
        }
    }
}


int solve(){
    string s; cin>>s;
    string pattern; cin>>pattern;
    cout << KMPSearch(pattern, s) << endl;
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
