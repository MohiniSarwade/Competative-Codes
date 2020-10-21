string Solution::minWindow(string A, string B) {
    int l1=A.length();
    int l2=B.length();
    
    if(l2>l1)
        return "";
    int countA[256]={0},countB[256]={0};
    int start=0,s_i=-1,minl=INT_MAX;
    for(int i=0;i<B.length();i++)
        countB[B[i]]++;
    int count=0;
    for(int i=0;i<A.length();i++)
    {
        countA[A[i]]++;
        if(countB[A[i]]!=0 && countA[A[i]]<=countB[A[i]])
            count++;
        if(count==l2)
        {
            while(countA[A[start]]>countB[A[start]]||countB[A[start]]==0)
            {
                if(countA[A[start]]>countB[A[start]])
                    countA[A[start]]--;
                start++;
            }
            int wl=i-start+1;
            if(minl>wl)
            {
                minl=wl;
                s_i=start;
            }
        }
    }
    if(s_i==-1)
        return "";
    return A.substr(s_i,minl);
}
