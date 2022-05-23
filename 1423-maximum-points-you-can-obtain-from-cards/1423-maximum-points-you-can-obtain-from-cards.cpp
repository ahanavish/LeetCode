class Solution {
public:
    int maxScore(vector<int>& card, int k) {
        int score=0, total=0;
        if(k==0)
            return 0;
        for(int i=0; i<card.size(); i++)
            total += card[i]; 
        if(k == card.size())
            return total;
        
        int low=0, high=card.size()-k;
        for(int i=low; i<high; i++)
            score += card[i];
        score = total - score;

        int ans=score;
        while(high<card.size()){
            score = score - card[high++] + card[low++];
            ans = max(ans, score);
        }
        
        return ans;
    }
};