#include <iostream>
#include <vector>
#include <string>
using namespace std;
const int mod = 1e9+7;

int main() {
    // Use fast I/O in C++
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    long long n,x;
    cin>>n>>x;
    
    std::vector<long long> v(n);
    for(long long i=0; i<n; i++) cin>>v[i];
        vector<long long>dp(x+1,0);
    dp[0]= 1;
    for(long long i=1;i<=x; i++){
        for(long long j=0; j<n; j++){
            if(v[j]<=i){
                dp[i] = (dp[i]+dp[i-v[j]])%mod;
            }
        }
    }
        cout<<dp[x]<<endl;

    
    return 0;
}
