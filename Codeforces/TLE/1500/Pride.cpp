#include <iostream>
#include <vector>
#include <algorithm>
#include<bits/stdc++.h>
using namespace std;
void solve(){
  int n;
  cin>>n;
  std::vector<int> v(n);
  for(int i=0; i<n; i++) cin>>v[i];
   
  int oneCnt = v[0]==1;
   int g = v[0];
   for(int i=1; i<n; i++){
    g = __gcd(g,v[i]);
    oneCnt+=v[i]==1;
   }
   if(g>1){
    cout<<-1<<endl;
    return;
   }
  // ... after the initial GCD and oneCnt calculation ...

if (oneCnt > 0) {
    cout << n - oneCnt << endl;
    return;
}

// Initialize 'ans' to a large value
int min_len = n; 

// Find the length of the shortest subarray with GCD 1
for (int i = 0; i < n; i++) {
    int current_gcd = v[i]; // Initialize gcd with the first element
    for (int j = i + 1; j < n; j++) {
        current_gcd = __gcd(current_gcd, v[j]);
        if (current_gcd == 1) {
            int current_len = (j - i + 1);
            min_len = min(min_len, current_len);
            break; // Optimization: Found the shortest for this 'i'
        }
    }
}

// The final answer is (cost to create '1') + (cost to spread '1')
int cost_to_create = min_len - 1;
int cost_to_spread = n - 1;

cout << cost_to_create + cost_to_spread << endl;





}
int main() {
    // Fast I/O for competitive programming
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);



    solve();

    return 0;
}