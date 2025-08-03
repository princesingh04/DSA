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
    int n ;
    cin>>n;
    string s;
    cin>>s;
    /*
    Logic
    The best answer you will get is by try moving all the sheeps towards the center sheep
    */
    int k = findCnter(s);
    std::vector<int> pre(n,0);
    for(int i=0; i<n; i++){
        pre[i] = pre[i-(i>0?1:0)]+(s[i]=='*');
    }
    // for(auto it:pre) cout<<it<<" ";
    //     cout<<endl;
    // return;
    long long ans =0;
    for(int i=0; i<n; i++){
        int tot=0;
        if(s[i]=='*' && i!=k){
         tot = abs(abs(k-i)-1);
    }
        
        if(i<k && s[i]=='*'){
         int sheeps = pre[k]-pre[i]-1;
         // cout<<sheeps<<" ";
         tot-=sheeps;
        }
        else if(i>k && s[i]=='*'){
            int sheeps = pre[i]-pre[k]-1;
            tot-=sheeps;
        }
        ans+=tot;
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