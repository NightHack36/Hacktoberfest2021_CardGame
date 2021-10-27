#include<bits/stdc++.h>
#include<math.h>
#define ll long long 
#define MOD 1000000007ll
using namespace std;
void prime(ll n){
    
    vector<char> is_prime(n+1 , true);
    is_prime[0] = is_prime[1] = false;
    for(ll i = 2;i<=n;i++){
        if(is_prime[i] && (ll)i*i<=n){
            for(ll j = i*i;j<=n;j+=i)
            is_prime[j] = false;
        }
    }
     for(ll i = 0;i<n+1;i++){
        if(is_prime[i])
        cout<<i<<" ";
    }
    cout<<"\n";
   

}
int main()
{
    ll n;
    cin>>n;
    prime(n);
    return 0;
}