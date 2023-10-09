/* Online C++ Compiler and Editor */
#include <bits/stdc++.h>

#define long long int

using namespace std;

signed main()
{
    int n, k; cin >> n >> k;
    vector<string> v;
    map<string,int> m;
    for(int i=0; i < n; i++){
        string aux; cin >> aux; 
        v.push_back(aux);
    }
    pair<string,int> ans = make_pair("", -1);
    for(int i = 0; i < n; i++){
        string aux; aux = v[i];
        for(int i=0; i < aux.size(); i++){
            if(aux[i] == '*'){
            for(char j = 'a'; j <= 'z'; j++){
                string gerada = "";
                gerada = aux;
                gerada[i] = j;
                if( m.find(gerada) == m.end() ){
                    m[gerada] = 1;
                }
                else{
                    m[gerada]++; // = cont;
                    if (m[gerada] > ans.second){
                        ans = make_pair(gerada,m[gerada]);
                    }
                    if(m[gerada] == ans.second){
                        vector<string> s; s.push_back(gerada); s.push_back(ans.first);
                        sort(s.begin(), s.end());
                        ans = make_pair(s[0], ans.second);
                    }
                } 
            }   
        }
        }
    }
    cout << ans.first << " " << ans.second << endl;
    return 0;
}