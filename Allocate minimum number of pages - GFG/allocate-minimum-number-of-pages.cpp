// { Driver Code Starts
// Initial template for C++

#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template in C++

class Solution 
{
    public:
    //Function to find minimum number of pages.
    int findPages(int A[], int N, int M) 
    {
        if(N<M)
            return -1;
            
        int sum=0;
        for(int i=0; i<N; i++)
            sum += A[i];
            
        int low=0, high=sum, target=INT_MAX;
        while(low<=high){
            int mid=(low+high)/2;
            
            if(possible(A, N, M, mid)){
                target = mid;
                high = mid-1;
            }
            else
                low = mid+1;
        }
        return target;
    }
    
    bool possible(int arr[], int N, int M, int curr){
        int stu=1, pages=0;
        for(int i=0; i<N; i++){
            if(arr[i]>curr)
                return false;
            if(pages + arr[i] > curr){
                stu++;
                pages = arr[i];
                if(stu > M)
                    return false;
            }
            else
                pages += arr[i];
        }
        return true;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int A[n];
        for(int i=0;i<n;i++){
            cin>>A[i];
        }
        int m;
        cin>>m;
        Solution ob;
        cout << ob.findPages(A, n, m) << endl;
    }
    return 0;
}
  // } Driver Code Ends