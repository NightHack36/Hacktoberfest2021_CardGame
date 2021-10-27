/*Q) find the min and max element in the given array*/
/*Approach: I will be solving this question with 2 method.
            method-1: for finding min element, initializing 0th index element to small variable and i=1 compare small variable with A[i],
                      if small>A[i] assign small = A[i] repeat the process till i= n-1.
                      similarly for max element initialize large = A[0] and i=0 compare large variable to A[i],
                      if large<A[i] assign large = A[i] repeat the process till i= n-1;
            method-2: Sort the array A and A[0] is the min element and A[n-1] is the max element. */
#include<iostream>
using namespace std;
//Find Function declaration
void Find(int A[30],int n); //for approach 1
//Find1 function declaration
void Find1(int A[30],int n); //for approach 2
//definition of Bsort
void Bsort(int A[30],int n)
{
    int temp;
    for(int i =0;i<n;i++)
    {
        for(int j=0;j<n-i-1;j++)
        {
            if(A[j]>A[j+1])
             {
                 temp = A[j];
                 A[j] = A[j+1];
                 A[j+1]= temp;
             }

        }
    }
}
int main()
{
    int a[30], s;
    cout<<"\nEnter the size of array: ";
    cin>>s;
    cout<<endl<<"Enter "<<s<<" elements in array: ";
    for(int i=0;i<s;i++)
        cin>>a[i];
    cout<<endl<<"Printing Array ";
    cout<<endl;
    for(int i =0;i<s;i++)
        cout<<a[i]<<" ";
    Find(a,s);
    Find1(a,s);
    return 0;
}
void Find(int A[30],int n)
{
    int small = A[0], large = A[0];
    for(int i=1;i<n;i++)
    {
        if(small>A[i])
            small = A[i];
        if(large<A[i])
            large = A[i];
    }
    cout<<endl<<"Min element: "<<small;
    cout<<endl<<"Max element: "<<large;
}
void Find1(int A[30],int n)
{
    Bsort(A,n);
    cout<<endl<<"Min element: "<<A[0];
    cout<<endl<<"Max element: "<<A[n-1];
}
