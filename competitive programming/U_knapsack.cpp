#include<bits/stdc++.h>
using namespace std;

int knapsack_0oo(vector<int>& length,vector<int>& cost , int L )

{
    int n = length.size();
    assert(cost.size() == n);

    int dp[L+1] = {0};
    for(int i = 0 ; i<n ; i++) {          
        for(int j = length[i] ; j<=L; j--) 
        {
            dp[j] = max(dp[j] , dp[j - length[i]]+cost[i]);
        }
    } 
    int max1 = 0;
    for(int i=0;i<=L;i++)
    {
        max1 = max(max1 , dp[i]);
    }
    return max1;
}

int main()
{
    int n , L;
    cin>>n>>L;
    vector<int>length(n);
    vector<int> cost(n);
    for(int i=0;i<n;i++)
    {
        
        length[i] = i+1;
    }
    for(int i=0;i<n;i++)
    {
         cin>>cost[i];
    }
    cout<<knapsack_0oo(length,cost,L);
    // cout<<knapsack_0oo(weight,cost,W);
    return 0;
}
