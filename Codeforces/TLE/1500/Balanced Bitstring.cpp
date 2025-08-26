#include <bits/stdc++.h>
using namespace std;
typedef long long int LL;
bool check(string bluePrint){
    int k = bluePrint.size();
int oneCnt = 0;
int zeroCnt = 0;
int quesCnt = 0;
for(int i=0; i<bluePrint.size(); i++){
    if(bluePrint[i]=='1') oneCnt++;
    else if(bluePrint[i]=='0') zeroCnt++;
    else quesCnt++;
}
if(oneCnt>k/2 || zeroCnt>k/2){
    return false;
}
if(oneCnt+zeroCnt==bluePrint.size()){
    return oneCnt==zeroCnt;
}
else{
    int req = abs(zeroCnt-oneCnt);
    quesCnt-=req;
    if(quesCnt&1) {
        return false;
    }
    else return true;
}
return true;
}
void solve(){
    int n,k;
    cin>>n>>k;
    if(k&1){
        cout<<"No"<<endl;
        return;
    }
    string s;
    cin>>s;
    string bluePrint;
    for(int i=0; i<k; i++) bluePrint+=s[i];
    for(int i=k; i<n; i++){
        if(s[i]==bluePrint[i%k]) continue;
        else if(s[i]=='?') {
          continue;
        }
        else if(bluePrint[i%k]=='?'){
            bluePrint[i%k] = s[i];
        }
        else {
            cout<<"No"<<endl;
            return;
        }
    }
    // cout<<bluePrint<<endl;
    if(check(bluePrint)){
        cout<<"Yes"<<endl;
        return;
    }
    cout<<"No"<<endl;
    return;
}
int main() {
    solve();
    return 0;
} 