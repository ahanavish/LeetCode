class Solution {
public:
    int compareVersion(string version1, string version2) {
        int i=0,j=0,n=version1.length(),m=version2.length();
        int num1=0,num2=0;
        while(i<n || j<m){
            while(i<n && version1[i]!='.' ){
                num1=num1*10+(version1[i]-'0');
                i++;
            }//end while
            while(j<m && version2[j]!='.'){
                num2=num2*10+(version2[j]-'0');
                j++;
            }//end while
            if(num1 > num2)
                return 1;
            else if(num1 < num2)
                return -1;
          num1=0;
          num2=0;
          i++;
          j++;
        }//end while
        return 0;
    }
};
