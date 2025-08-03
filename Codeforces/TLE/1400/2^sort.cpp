#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include<bits/stdc++.h>
using namespace std;
int findCnter(string s){
    int cnt = 0;
    for(auto it:s){
        if(it=='*') cnt++;
    }
    int mid = (cnt+1)/2;
    for(int i=0; i<s.size(); i++){
        if(s[i]=='*') mid--;
        if(mid==0) return i;
    }
    return -1;
}
void solve(){
    int n,k ;
    cin>>n>>k;
     std::vector<int> v(n);
     for(int i=0; i<n; i++) cin>>v[i];
        vector<int> helper;
        for(int i=0; i<n-1; i++){
         if(v[i]<2*v[i+1]) helper.push_back(1);
         else helper.push_back(0);
        }
        //Find subarray count with sum k
        int i=0;
        int sum = 0;
        int ans =0;
        int j=0;
        while(i<helper.size()){
            sum+=helper[i];
              if(i-j+1>k) {
                sum-=helper[j];
                j++;
            }
            if(i-j+1==sum && sum==k) ans++;
           i++;
             
        }
        cout<<ans<<endl;


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