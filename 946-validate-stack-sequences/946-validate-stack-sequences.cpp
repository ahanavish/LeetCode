class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) 
    {
        int n = pushed.size();              // Extracting the size of pushed 
        
        stack<int> st;                      // initializing the stack for performing the operations
        int j = 0;                          // for take caring of popped elements
        int i = 0;                          // for take caring of pushed elements
        
        for(i=0;i<n;i++)
        {
            st.push(pushed[i]);                      // In each iteration push that element
            if(st.top() == popped[j])                // if our top of stack is eqaul to the current popped element 
            {
                while(st.top() == popped[j])         // pop the stack till we found matching popped element
                {
                    st.pop();
                    j++;
                    
                    if(st.size()==0)                 // if stack size is getting zero then break this inner loop
                        break;
                }
            }
        }
        
        return st.empty();
    }
};