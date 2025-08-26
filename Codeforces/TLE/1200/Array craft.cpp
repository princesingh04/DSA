#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, x, y;
    cin >> n >> x >> y;
    vector<int> v(n + 1); 

  
    for (int i = y; i <= x; i++) {
        v[i] = 1;
    }

    for (int i = y - 1; i >= 1; i--) {
      
        if ((y - 1 - i) % 2 == 0) {
            v[i] = -1; 
        } else {
            v[i] = 1; 
        }
    }
    
   
    for (int i = x + 1; i <= n; i++) {
       
        if ((i - (x + 1)) % 2 == 0) {
            v[i] = -1; 
        } else {
            v[i] = 1; 
        }
    }

    // Print the result
    for (int i = 1; i <= n; i++) {
        cout << v[i] << " ";
    }
    cout << endl;
}


int main() {
    int t;
    cin >>t;
    while(t--) solve(); 
   return 0;

} 

