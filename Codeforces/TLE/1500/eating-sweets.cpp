#include <bits/stdc++.h>
using namespace std;



int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

  long long n,m;
  cin>>n>>m;
  vector<long long> v(n);
  for(long long i=0; i<n; i++) cin>>v[i];
    sort(v.begin(),v.end());
vector<long long> pre(n,0);
for(long long i=0; i<n; i++){
    if(i>0){ pre[i] = v[i]+pre[i-1];}
    else 
    {
        pre[i] = v[i];
    }
    }
   vector<long long> ans(n,0);
   
   for(long long i=0; i<n; i++){
   if(i>=m) ans[i] = pre[i]+ans[i-m];
   else ans[i] = pre[i];
   }
   for(auto it:ans) cout<<it<<" ";
    cout<<endl;

    return 0;

}
//2 5 11 18 30 43 62 83 121
