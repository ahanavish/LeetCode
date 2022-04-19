class Solution {
public:
    int d, n;                        
    vector <int> job;               
    vector <vector<int>> track;
    vector <int> uptil;
    int minDifficulty(vector<int>& job, int d) {
        n = job.size();           
        this->d = d;                

        if(n<d)
            return -1;
        
        uptil = vector <int> (job);
        uptil[n-1]=job[n-1];
        for(int i=n-2; i>=0; i--)
            uptil[i]=max(uptil[i+1], job[i]);
        
        this->job = job;          
        track = vector<vector<int>> (d+1, vector <int> (n, -1));  
        return dp(0, 1);
    }
    
    int dp(int jobno, int day){
        if(day==d)
            return uptil[jobno];
        
        if(track[day][jobno]==-1){
            int best=INT_MAX, hardest=0;
            for(int i=jobno; i<n-(d-day); i++){
                hardest = max(hardest, job[i]);
                best = min(best, hardest + dp(i+1, day+1));
            }
            track[day][jobno]=best;
        }
        
        return track[day][jobno];
    }
};
