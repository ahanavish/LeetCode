class Solution {
public:
    int c1 = 0, c2 = 0;
    int c=0;
    
    // count the most frequent element in both the arrays
    int maxFreq(vector<int> &arr, int n) {
    
        int res = 0;
        int count = 1;
        for(int i = 1; i < n; i++) {
            if(arr[i] == arr[res]) {
                count++;
            } else {
                count--;
            }

            if(count == 0) {
                res = i;
                count = 1;
            }

        }
        // maintain a count for both the arrays to find which one has the maximum occurence.
        for(int i = 0; i < n; i++) {
            if(arr[i] == arr[res]) {
                c++;
            }
        }
     
        return arr[res];
    }
    
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int n = tops.size();
        int top_max = maxFreq(tops,n);
        c1 = c;
        c = 0;
        int bottom_max = maxFreq(bottoms,n);
        c2 = c;
        int count = 0;
        if(c1<c2)
        {
            for(int i=0; i<n; i++)
            {
                if(bottoms[i]!=bottom_max)
                {
                    swap(bottoms[i],tops[i]);
                    count++;
                }
            }
            
        }
        else
        {
            for(int i=0; i<n; i++)
            {
                if(tops[i]!=top_max)
                {
                    swap(tops[i],bottoms[i]);
                    count++;
                }
            }
        }
        if(c1<c2)
        {
            for(int i=1; i<n; i++)
            {
                if(bottoms[i]!=bottoms[i-1])
                {
                    return -1;
                }
            }
        }
        else
        {
            for(int i=1; i<n; i++)
            {
                if(tops[i]!=tops[i-1])
                {
                    return -1;
                }
            }
        }
        return count;
    }
};