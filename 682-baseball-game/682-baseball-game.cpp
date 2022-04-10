class Solution {
public:
    int calPoints(vector<string>& ops) {
        int len = ops.size(), scores = 0, x, y;
        deque<int> dq;
        for(int i = 0; i < len; ++i)
        {
            if(ops[i] == "+")
            {
                x = dq.back();
                dq.pop_back();
                y = dq.back();
                dq.pop_back();
                dq.push_back(y);
                dq.push_back(x);
                dq.push_back(x+y);
            }
            else if(ops[i] == "C")
            {
                dq.pop_back();
            }
            else if(ops[i] == "D")
            {
                x = dq.back();
                dq.push_back(2*x);
            }
            else dq.push_back(stoi(ops[i]));
        }
        while(!dq.empty())
        {
            scores += dq.front();
            dq.pop_front();
        }
        return scores;
    }
};