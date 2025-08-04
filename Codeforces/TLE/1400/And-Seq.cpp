#include <iostream>
#include <vector>
#include <queue> // Required for priority_queue
int mod = 1e9+7;
using namespace std;
long long fact(int n){
    long long ans = 1;
    for(int i=n; i>=1; i--){
      ans = (1LL*(ans*i)%mod)%mod;
    }
    return ans;
}
void solve() {
    int n;
    cin>>n;
    std::vector<int> v(n);
    for(int i=0; i<n; i++) cin>>v[i];
        // for(int i=0; i<n; i++) cout<< v[i]<<" ";

        int a=  v[0];
    for(int i=1; i<n; i++){
          a = a&v[i];
    }
    // cout<<a<<endl;
    long long cnt =0;
    for(int i=0; i<n; i++){
        if(v[i]==a) cnt++;
    }
    if(cnt<2){
        cout<<0<<endl;
        return;
    }
    long long f = fact(n-2);
    long long ans = (cnt*(cnt-1))%mod;
    ans = (ans*f)%mod;


    cout<<ans<<endl;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int t;
    cin>>t;
    while(t--) solve();
   
    return 0;
}