class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int i=0, j=n-1, vol=0;
        
        while(i<j){
            int shorth=min(height[i], height[j]);
            vol = max(vol, (j-i)*shorth);
            if(height[i]<height[j]) i++;
            else j--;
        }
        return vol;
    }
};