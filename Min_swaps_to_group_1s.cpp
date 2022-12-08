int minSwaps(int a[], int n) 
{
    /* find the no of 1's present in the array */
        int c1 = 0;
        for(int i=0;i<n;i++)
        if(a[i]==1)
        c1++;

        /*
        Now we have c1 ones with us which we need to group. We will calculate the no. of zeros present in 
        each subarray of size c1. The answer will be the minimum of this.
        ans = min(no. of zeros present in all the subarrays of size c1)
        */
        int start = 0;
        int end = 0;
        int ans = INT_MAX;
        int c0 = 0;
        while(start<n and end<n)
        {
            if(a[end]==0)
            c0++;
            if(end-start+1==c1)
            {
                ans = min(ans,c0);
                if(a[start]==0)
                c0--;
                start++;
            }
            end++;
        }
        if(ans==INT_MAX)
        return -1;
        else
        return ans;
}
