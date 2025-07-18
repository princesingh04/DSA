Question Link : https://codeforces.com/problemset/problem/1366/B
Problem Code : Shuffle



#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <bits/stdc++.h>
using namespace std;
void solve(){
    int n,m,x;
    cin>>n>>x>>m;
    std::vector<pair<int,int>> v(m);
    for(int i=0; i<m; i++) {
        int x,y;
        cin>>x>>y;
        v[i] = {x,y};
    }
    int l = x;
    int r =x;
    for(int i=0; i<m; i++){
     int L = v[i].first;
     int R = v[i].second;
     if(! (R<l || L>r)){
        l = min(l,L);
        r= max(R,r);
     }
    }
    cout<<r-l+1<<endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}