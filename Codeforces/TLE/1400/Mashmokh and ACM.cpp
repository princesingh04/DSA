#include <bits/stdc++.h>
using namespace std;

int solve() {
  int mod = 1e9+7;
  int n,k;
  cin>>n>>k;
  std::vector<vector<int>> dp(k+1,vector<int>(n+1,0));
  //base case 
  for(int j=1; j<=n; j++) dp[1][j] = 1;

  for(int i=2; i<=k; i++){
    for(int p = 1; p<=n; p++){
        if(dp[i-1][p]>0){
           for(int j=p; j<=n; j+=p){
            dp[i][j] = (dp[i][j]+dp[i-1][p])%mod;
           }
        }
    }
  }
  long long ans =0;
  for(int i=1; i<=n; i++){
    ans = (ans+dp[k][i])%mod;
  }
  cout<<ans<<endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
