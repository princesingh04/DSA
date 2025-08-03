#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include<bits/stdc++.h>
using namespace std;

int main() {
    // Fast I/O for performance
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
/*
logic:
array ke saare number of xor kro ya sum kro ya xor aur sum dono
kro final answer teeno ka same ya to even ya to odd aiga
* Iske hi according question me dia gya hai 1 answer aur 2 option ya to even ya odd 
to hmara task hai ki check krna final answer kya aa rha hai odd ya even
*/int t;
    cin>>t;
    while(t--){
 long long n,y,z;
 cin>>n>>y>>z;
 std::vector<long long> v(n);
 for(long long i=0; i<n; i++) cin>>v[i];
 long long sum  = accumulate(v.begin(),v.end(),1LL*0);
 long long first = y;
 long long second = y+3;
 if((sum+first) %2 == z%2){
    cout<<"Alice"<<endl;
    // return;
 }
 else{
    cout<<"Bob"<<endl;
 }

}
   

    return 0;
}