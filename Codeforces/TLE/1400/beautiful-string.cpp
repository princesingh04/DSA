#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include<bits/stdc++.h>
using namespace std;

void solve(){
string s;
cin>>s;
map<char,int> mp;

for(auto it:s) mp[it]++;
    if(mp.size()>=5){
    cout<<"No"<<endl;
    return;
}
if(mp.size()==1) {
    cout<<"No"<<endl;
    return;
}
bool found = false;
if(mp.size()==2){
for(auto it:mp){
    if(it.second==1) {
        cout<<"No"<<endl;
        return;
    }
}
}
if(mp.size()==3){
    for(auto it:mp)
    if(it.second>1) found = true;
if(!found) {
    cout<<"No"<<endl;

    return;
}
}
cout<<"Yes"<<endl;
return;


}
int main() {
    // Fast I/O for performance
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
  
      solve();
    return 0;
}