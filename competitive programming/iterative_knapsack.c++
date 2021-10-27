#include<bits/stdc++.h>
using namespace std;

int knapsack(int w[] ,int v[], int n , int W)
{
    int t[n+1][W+1];
    for(int i = 0;i<n+1;i++)
    {
        for(int j = 0;j<W+1;j++)
        {
            if(i==0||j==0)
            {
                t[i][j] = 0;
            }
        }
    }

    for(int i = 1;i<n+1;i++)
    {
        for(int j = 1;j<W+1;j++)
        {
            if(w[i-1]<j)
            t[i][j] = max(v[i-1]+t[i-1][j-w[i-1]] , t[i-1][j]);
            else 
            t[i][j] = t[i-1][j];
    
        }
    }
        return t[n][W];
}

int main()
{
    int n , W;
    cin>>n>>W;
    int w[n];
    int v[n];
    for(int i = 0;i<n;i++)
    {
       cin>>w[i];
    }

    for(int i = 0;i<n;i++)
    {
       cin>>v[i];
    }
    cout<<knapsack(w,v,n,W);
}