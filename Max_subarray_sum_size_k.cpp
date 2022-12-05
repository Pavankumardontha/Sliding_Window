class Solution{   
public:
    long maximumSumSubarray(int k, vector<int> &a , int N)
    {
        int start=0;
        int end=0;
        int n = a.size();
        long ans=0;
        long sum=0;
        while(start<n and end<n)
        {
            sum = sum + a[end];
            while(end-start+1>k)
            {
                sum = sum - a[start];
                start++;
            }
            ans = max(ans,sum);
            end++;
        }
        return ans;
    }
};
