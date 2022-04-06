class Solution {
public:
    int threeSumMulti(vector<int>& arr, int target) {
        int mod = 1e9+7;
        long result=0;
        vector<long> count(101,0);
        for(int x:arr)
        {
            count[x]++;
        }
        for(int i=0;i<=100;i++)
        {
            for(int j=0;j<=100;j++)
            {
                int k=target-i-j;
                if(k<0 or k>100) continue;
                if(i==j and j==k)
                {
                    result += (count[i]*(count[i]-1)*(count[i]-2)/6);
                }
                else if(i==j and j!=k)
                {
                    result += (count[i]*(count[i]-1)/2)*count[k];
                }
                else if(i<j and j<k)
                {
                    result += count[i]*count[j]*count[k];
                }
            }
        }
        return (int)(result%mod);
    }
};