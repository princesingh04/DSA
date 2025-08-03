#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include<bits/stdc++.h>
using namespace std;

void solve(){
  int n,m;
  cin>>n>>m;
  std::vector<int> v(n);
  int mini = INT_MAX;
  for (int i = 0; i < n; ++i)
  {
      cin>>v[i];
    
  }
  vector<pair<int,int>> edg(m);
  vector<int> deg(n+1 ,0);
  for(int i=0; i<m; i++){
    cin>>edg[i].first>>edg[i].second;
    deg[edg[i].first]++;
    deg[edg[i].second]++;
  }
  if(m%2==0){
   cout<<0<<endl;
   return;
  }
  int ans =INT_MAX;

   for(int i=0; i<m; i++){
    if(deg[edg[i].first]%2 == deg[edg[i].second]%2){
        ans = min(ans,v[edg[i].first-1]+v[edg[i].second-1]);
    }
  }
  // sort(v.begin(),v.end());
  for(int i=0; i<=n; i++){
    if(deg[i]%2==1) {
      ans = min(ans,v[i-1]);
    } 
  }
 
  cout<<ans<<endl;
  return;

}
int main() {
    // Fast I/O for performance
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
   int t;
   cin>>t;
   while(t--) solve();
    return 0;
}