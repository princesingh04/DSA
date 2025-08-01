#include <bits/stdc++.h>
using namespace std;

void solve(){
int n,m;
cin>>n>>m;
std::vector<int> v(n);
for(int i=0; i<n; i++) cin>>v[i];
    sort(v.begin(),v.end());
    for(int i=0; i<m; i++){
        int x;
        cin>>x;
        auto idx = upper_bound(v.begin(),v.end(),x);
        cout<<idx-v.begin()<<" ";

    }
    return;
 
}
int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    
     solve();
    

    return 0;
}
