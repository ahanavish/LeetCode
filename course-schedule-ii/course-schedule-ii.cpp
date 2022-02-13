class Solution {
public:
    vector<int> findOrder(int num, vector<vector<int>>& prereq) {
        vector<int> result(num);
        if (num == 0)   //if there are no vertices, return empty array
            return result;

        if (prereq.empty()) {   //if none of the courses are dependent on another, any sequence is fine
            for (int i = 0; i < num; i++)
                result[i] = i;
            return result;
        }

        vector<int> in(num);    //to store indegree of vertices
        queue<int> zero;        //to push vertices with 0 indegree
        for (vector<int>& pre : prereq) 
            in[pre[0]]++;           //increment indegree of vertices as they are found
        
        for (int i = 0; i < in.size(); i++)     //pushing vertices with indegree 0 into queue 
            if (in[i] == 0) 
                zero.push(i);
            
        
        if (zero.empty())           //if there are no vertices with indegree=0/ cyclic ->return empty array
            return vector<int>();   
        

        int index = 0;
        while (!zero.empty()) {
            int course = zero.front();
            zero.pop();
            result[index] = course;
            index++;
            for (vector<int>& pre : prereq) {
                if (pre[1] == course) {
                    in[pre[0]]--;       //since its prerequisite is already done, so decrementing indegree of one who is dependent
                    if (in[pre[0]] == 0)      //if any new vertices got indegree=0, push it into queue
                        zero.push(pre[0]);
                }
            }
        }

        for (int i : in) // if indegree of some vertex is still not 0 after whole process, return empty array
            if (i != 0) 
                return vector<int>();

        return result;
    }
};