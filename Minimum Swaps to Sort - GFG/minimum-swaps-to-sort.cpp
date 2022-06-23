// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution 
{
    public:
    //Function to find the minimum number of swaps required to sort the array. 
	vector <int> copy;
	void swap(vector<int>&nums, int i, int j){
	    int temp = nums[i];
	    nums[i] = nums[j];
	    nums[j] = temp;
	}
	int minSwaps(vector<int>&nums)
	{
	    int ans=0;
	    copy = nums;
	    sort(copy.begin(), copy.end());
	    
	    map<int, int> index;
	    for(int i=0; i<nums.size(); i++)
	        index[nums[i]] = i;
	        
	    for(int i=0; i<nums.size(); i++){
	       if(nums[i] == copy[i])
	            continue;
	       
	       ans++;
	       int temp = nums[i];
	       swap(nums, i, index[copy[i]]);
	       index[temp] = index[copy[i]];
	       index[copy[i]] = i;
	    }
	    
	    return ans;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)
			cin >> nums[i];
		Solution obj;
		int ans = obj.minSwaps(nums);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends