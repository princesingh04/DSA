#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin>>n;
    std::vector<int> v(n);
    for(int i=0; i<n; i++) cin>>v[i];

        sort(v.begin(),v.end());
    int maxi = v[n-1];
    maxi  =maxi+(maxi%10);
    
    //case 1 : check for 5 and 0
    int unit = maxi%10;
    if(unit==5 || unit==0){
        // cout<<n<<endl;
        for(int i=0; i<n; i++){
            // cout<<v[i]<<endl;
            v[i] = v[i]+(v[i]%10);
            
            if(i>0) {
                if(v[i]!=v[i-1]) {
                    cout<<"No"<<endl;
                    return;
                }
            }
        }
    }
    // return;

    //case 2
    else if(unit!=0 || unit!=5){
   for(int i=0; i<n; i++){
    if(v[i]%10==5 || v[i]%10==0) {
        cout<<"No"<<endl;
        return;
    }
    while((v[i]%10)!=unit){
        v[i] = v[i]+(v[i]%10);
    }
    if(i>0){
        if(v[i]%20!= v[i-1]%20) {
            cout<<"No"<<endl;
            return;                    }
    }
}
  }
   cout<<"Yes"<<endl;
   return;
 
}
int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--) {
     solve();
    }

    return 0;
}
