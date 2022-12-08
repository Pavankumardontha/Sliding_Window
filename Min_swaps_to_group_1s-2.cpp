class Solution {
public:
    int minSwaps(vector<int>& a) 
    {
        /* think about how to slide a window of size k on a circle !!! */
        int start = 0;
        int end = 0;
        int n = a.size();
        /* calculate the no. of 1's in the array */
        int k= 0;
        for(int i=0;i<n;i++)
        {
            if(a[i]==1)
            k++;
        }
        if(k==0)
        return 0;
        int c0=0;//current no. of 0's count in our sliding window
        int ans = INT_MAX;
        while(start<n)
        {
            /*this is how we slide a window of size k on a circle. Draw a circle and think*/
            if(a[end%n]==0) 
            c0++;
            if(end-start+1==k)
            {
                ans = min(ans,c0);
                if(a[start]==0)
                c0--;
                start++;
            }
            end++;
        }
        return ans;
    }

};
