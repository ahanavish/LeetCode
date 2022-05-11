class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int i=0, j=n-1, vol=0;
        
        while(i<j){
            int shorth;
            if(height[i]<height[j]){
                shorth = height[i];
                vol = max(vol, (j-i)*shorth);
                i++;
            }
            else{
                shorth = height[j];
                vol = max(vol, (j-i)*shorth);
                j--;
            }
            
        }
        
        return vol;
    }
};