#include <bits/stdc++.h>
using namespace std;
bool isPossible(int n, vector<int>& v, int hours) {
    //yes fucntion ye calculate kr rha hai ki total x hours me
    //kitna kaam kr paunga
    //agr maan lo kisi worker k paas koi kaam nhi hai to 
    //dusro k kaam ko wo 2 hours me krr rha hai then total work 
    //wo hours/2 karega
    //case 2 , agr uske paas kaam hai to wo phle wo kaam kr lega 
    //total kaam me kie hue kaam add karega aur jitne hours bache hai utne 
    //wo dusre ke kaam ko rem/2 me kr dega
    vector<int> cnt(n+1, 0);
    for (int x : v) cnt[x]++;

    long long total = 0;
    for (int i = 1; i <= n; i++) {
        //yaa to no of task jyada honge ya time jyada hoga
        //yha agr jyda kaam hai to jitne gnte hai utna kaam kro aur apne total me 
        //utna kaam add krdo jitna kie ho
        int prof = min(cnt[i], hours); // proficient tasks done in 1 hour
        int rem_hours = hours - prof;  // remaining capacity for 2-hour tasks
        total += prof + rem_hours / 2;
    }
    //last me check kro jitna tum ne kaam kra wo jitne kaam the usse jyada hai ya km hai
    return total >= v.size();
}

void solve(){
    int n,m;
    cin>>n>>m;
    std::vector<int> v(m);
    // map<int,int>mp;
    for (int i = 0; i < m; i++)
    {
        cin>>v[i];
       
    }
    int l =1;
    int r = 2*m;
    int ans = r;
    while(l<=r){
        int mid = l+(r-l)/2;
         // int mid =3;
        if(isPossible(n,v,mid)){
            ans = min(ans,mid);
            r = mid-1;
        }
        else l = mid+1;
        // return;

    }
    cout<<ans<<endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
   int t;
   cin>>t;
   while(t--) solve();
    return 0;
}
