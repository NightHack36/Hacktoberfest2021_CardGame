#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
#define ll long long
#define l '\n'
const int M = 1e9 + 7;
int countDigit(long long n)
{
    return floor(log10(n) + 1);
}
int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}
bool isPowerOfTwo(ll a)
{
    if (a == 0)
        return false;
    return (ceil(log2(a)) == floor(log2(a)));
}
void PrintVector(vector<int> &v)
{
    for (int i = 0; i < v.size(); i++)
        cout << v[i] << ' ';
    cout << l;
}
ll fastPower(ll a, ll b)
{
    ll res = 1;
    while (b > 0)
    {
        if (b % 2 != 0) // b%2 == b&1
            res = (res * a % M) % M;
        a = (a % M * a % M) % M;
        b = b >> 1; // b/2 == b>>1
    }
    return res;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int test;
    cin >> test;
    int v[10][10] = {0};
    for (int i = 1; i <= 9; i++)
    {
        if(i %2 == 0){
            for (int j = 1; j <= 5; j++)
            {
                int sum = i*j;
                int lastDigit =sum%10;
                v[i][lastDigit] = sum;
            }
        }
        else if(i == 5) {
            v[5][0] = 10;
            v[5][5] = 5;
        }
        else{
            for (int j = 1; j <= 10; j++)
            {
                int sum = i*j;
                int lastDigit =sum%10;
                v[i][lastDigit] = sum;
            }
        }
    }
    // for (int i = 1; i <= 9; i++)
    // {
    //     cout<<"value of i : "<<i<<l;
    //     for (int j = 0; j <= 9; j++)
    //     {
    //         cout<<v[i][j]<<' ';
    //     }
    //     cout<<l;
    // }
    
    while (test--)
    {
        int n, k;
        cin >> n >> k;
        for (int i = 0; i < n; i++)
        {
            int a;
            cin>>a;
            int last = a%10;
            if(a >= k*10) cout<<"YES"<<l;
            else{
                if((v[k][last] != 0) && (v[k][last] <= a) ) cout<<"YES"<<l;
                else cout<<"NO"<<l;
            }
        }
        
    }
}