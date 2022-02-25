class Solution {
public:
    int compareVersion(string v1, string v2) {
        int size1 = v1.length(), size2 = v2.length();
        
        int i=0, j=0, num1=0, num2=0;
        while(i<size1 || j<size2){
            while(i<size1 && v1[i]!='.')
                num1 = num1*10 + (v1[i++]-'0');
            
            while(j<size2 && v2[j]!='.')
                num2 = num2*10 + (v2[j++]-'0');
            
            if(num1>num2)
                return 1;
            else if(num1<num2)
                return -1;
            
            i++;
            j++;
            num1=0;
            num2=0;
        }
        
        return 0;
    }
};