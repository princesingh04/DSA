#include <iostream>
#include <vector>
#include <string>
using namespace std;
#define MOD 1000000007

int main() {
    // Use fast I/O in C++
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    long long n,x;
    cin>>n>>x;
    
    std::vector<long long> v(n);
    for(long long i=0; i<n; i++) cin>>v[i];

        // vector<vector<long long>>dp(n+1,vector<long long>(x+1,0));
    // for(int i =0; i<n; i++) dp[i][0] = 1;
      vector<int> nextState(x+1,0);
      // nextState[n] = 0;
      nextState[0] = 1;
    for(long long i=n-1;i>=0; i--){
        vector<int> currState(x+1,0);
        currState[0] =1;
        for(long long sum=1; sum<=x; sum++){
            long long notP = nextState[sum];
            long long pick =0;
            if(v[i]<=sum){
              pick = currState[sum-v[i]];
            }
            currState[sum] = (pick+notP)%MOD;
        }
        nextState = currState;
    }
        cout<<nextState[x]<<endl;

    
    return 0;
}
