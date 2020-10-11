class Solution {
public:
    int maxDepth(string s) {
      
        int count=0;
        int ans=0;
        for(int i=0;i<s.length();i++)
        {
            if(s[i]=='(')
                count++;
            if(s[i]==')')
                count--;
            if(count>ans)
                ans=count;
                
        }
        
        return ans;
        
    }
};
