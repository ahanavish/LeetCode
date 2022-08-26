class Solution {
public:
    bool reorderedPowerOf2(int n) {
        string original=to_string(n);
        sort(original.begin(), original.end());
        for(int i=0; i<30; i++){
            string power=to_string(1<<i);
            sort(power.begin(), power.end());
            if(original==power)
                return true;
        }
        
        return false;
    }
};