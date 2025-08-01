#include <bits/stdc++.h>
using namespace std;
int rev(int x) {
    int res = 0;
    for(int i = 0; i < 8; i++) {
        res <<= 1;        // Shift result left
        res |= (x & 1);   // Take last bit of x
        x >>= 1;          // Shift x right
    }
    return res;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
      string s;
    getline(cin, s); // ✅ Reads entire line with spaces
int prev =0;
vector<int> ans;
    for(int i=0; i<s.size(); i++){
        int r = rev(prev);
        int asc = s[i];
        int curr = rev(asc);
        ans.push_back((prev-curr+256)%256);
        prev = curr;
    }
    for(auto it:ans) cout<<it<<endl;

    return 0;
}
