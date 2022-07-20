class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
     int n = words.size();
     map< char , vector<int>  > mp ;
     for( int i = 0 ; i<s.length() ; i++ ) mp[s[i]].push_back(i) ;
        
    int count = 0 ;
    for( int i = 0 ; i<n ; i++)
    {
        int prev  = -1 ; 
        string sub = words[i] ;
        for( int j = 0 ; j<sub.length() ; j++)
       {  
           auto it = upper_bound( mp[sub[j]].begin() , mp[sub[j]].end() , prev  ) ;
           if(  it == mp[ sub[j]].end() ) break ;
           prev = *it ;
           if( j == sub.length() -1 )count++ ;
       }
    }
        return count ;
    }
};