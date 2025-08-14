#include <iostream>
#include <vector>
#include<bits/stdc++.h>
using namespace std;

void solve() {
   int n;
   cin>>n;
   std::vector<int> v(n);
   for (int i = 0; i < n; ++i)
   {
        cin>>v[i];
   }
   vector<int> dp(n+1,0);
   dp[n]=0;
   for(int i=n-1; i>=0; i--){
      int notPick = 1+dp[i+1];
      int pick = INT_MAX;
      if(i+v[i]+1<n){
        pick = dp[i+v[i]+1];
      }
      dp[i] = min(pick,notPick);

   }
   cout<< dp[0]<<endl;
    
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
