class Solution {
public:
    bool isHappy(int n) {
        unordered_set <int> set;
        
        while(n != 1){
            if(set.find(n) != set.end())
                return false;
            else
                set.insert(n);
            
            int sum=0;
            while(n != 0){
                int dig = n%10;
                sum += (dig*dig);
                n = n/ 10;
            }
            
            n = sum;
        }
        
        return true;
    }
};