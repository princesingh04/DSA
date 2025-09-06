#include <iostream>
#include <vector>
#include <string>
#include<bits/stdc++.h>
using namespace std;
#define int long long

// Function to solve a single test case
void solve() {
    int n,q;
    cin >>n>>q;
    vector<int> v(n);
    vector<int> diff(n+1,0);
    for(int i=0; i<n; i++) cin>>v[i];
        vector<pair<int,int>> queries;
    for(int i=0; i<q; i++){
        int x,y;
        cin>>x>>y;
        queries.push_back({x-1,y-1});
        diff[x-1]++;
        diff[y]--;
    }
    vector<pair<int,int>> freqQueries;
    int cumSum =0;
    for(int i=0; i<=n; i++){
        cumSum+=diff[i];
     freqQueries.push_back({cumSum,i});
    }
    sort(freqQueries.rbegin(),freqQueries.rend());
    vector<int> temp(n);
    int i=0;
    sort(v.rbegin(),v.rend());
    for(auto it:freqQueries) {
         int idx = it.second;
         if(idx!=n){
            temp[idx] = v[i];
            i++;
         }
    }
   vector<int> preSum(n,0);
   preSum[0] = temp[0];
   for(int i=1; i<n; i++){
    preSum[i] = preSum[i-1]+temp[i];
   }
   long long sum =0;
   for(auto it:queries){
    int left = it.first;
    int right = it.second;
    sum+= left==0?preSum[right]:preSum[right]-preSum[left-1];
   }
   cout<<sum<<endl;
    



}

int32_t main() {
    // Fast I/O for competitive programming
   ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // Handle multiple test cases
     solve();
    // int t;
    // std::cin >> t;
    // while (t--) {
       
    // }

    return 0;
}
