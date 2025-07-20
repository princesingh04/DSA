//Question link : https://codeforces.com/problemset/problem/1364/B
//Solution
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath> 
#include<bits/stdc++.h>
using namespace std;
void solve(){
int n;
cin>>n;
std::vector<int> v(n);
  for(int i=0; i<n; i++) cin>>v[i];
    vector<int> ans;
   ans.push_back(v[0]);
   for(int i=1; i<n-1; i++){
    if(((1LL*v[i]-v[i-1]) * (1LL*v[i+1]-v[i]))<0) ans.push_back(v[i]);
}

ans.push_back(v[n-1]);
cout<<ans.size()<<endl;
for(auto it:ans) cout<<it<<" ";
    cout<<endl;
return;
}

int main() {
   
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t;
    std::cin >> t; 

    while (t--) {
       solve();
    }

    return 0;
}