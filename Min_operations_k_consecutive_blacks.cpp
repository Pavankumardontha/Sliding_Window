class Solution {
public:
    int minimumRecolors(string a, int k) 
    {
        /* 
        In each window of size k , calculate the number of whites.
        ans = minimum ( no. of whites present in window size of k) 
        */
        int n = a.length();
        int ans = INT_MAX;
        int start = 0;
        int end = 0;
        int white_count = 0;
        while(start<n and end<n)
        {
            if(a[end]=='W')
            white_count++;
            if(end-start+1 == k)
            {
                ans = min(ans,white_count);
                if(a[start]=='W')
                white_count--;
                start++;
            }
            end++;
        }
        return ans;
    }
};
