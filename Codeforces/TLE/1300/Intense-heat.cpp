#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include<bits/stdc++.h>
using namespace std;

void solve(){
  int n,k;
  cin>>n>>k;
  std::vector<int> v(n);
  for (int i = 0; i < n; ++i)
  {
      cin>>v[i];
  }
  vector<int> pre(n,0);
  for(int i=0; i<n; i++){
    pre[i] = pre[i+((i>0)?-1:0)]+v[i];
  }
  // for(auto it:pre) cout<<it<<" ";
  double ans = 0.0;
  for(int i=0; i<n; i++){
    long long sum=0;
    for(int j=i+k-1; j<n; j++){
       if(i>0)sum  = pre[j]-pre[i-1];
       else sum = pre[j];
       // cout<<j-i+1<<endl;
       ans = max(ans,(double)sum/(double)(j-i+1));

    }
   
  }
  std::cout << std::fixed << std::setprecision(15) << ans << std::endl;
  return;

}
int main() {
    // Fast I/O for performance
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
  
      solve();
    return 0;
}