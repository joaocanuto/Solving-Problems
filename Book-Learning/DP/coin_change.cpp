// Recursive form:

int solve(int x){
    if(x < 0) return INF;
    if (x == 0) return 0;
    if (ready[x]) return value[x];
    int best = INF;

    for(auto c : coins) {
        best = min(best, solve(x - c) + 1);
    }
    ready[x] = true;
    value[x] = best;
    return best;
} 

// O(target*coins.size())

// Iterative form:
value[0] = 0;
for(int x = 1; x <= n; x++){
    value[x] = INF;
    for(auto c : coins){
        if(x - c >= 0){
            value[x] = min(value[x], value[x - c] + 1);
        }
    }
}

// Finding wich coin was used:

value[0] = 0
for(int x = 1; x <= n; x++){
    value[x] = INF;
    for(auto c : coins){
        if(x - c >= 0 && value[x - c] + 1 < value[x]){
            value[x] = value[x - c] + 1;
            first[x] = c;
        }
    }
}

while(n > 0){
    cout << first[n] << endl;
    n -= first[n];
}

// Finding the total number of ways to produce a sum x using the coins.
MOD = 1e9 + 7;

count[0] = 1;
for(int x = 1; x <= n; x++){
    for(auto c : coins){
        if(x - c >= 0){
            count[x] %= MOD; 
            count[x] += count[x - c];
        }
    }
}

