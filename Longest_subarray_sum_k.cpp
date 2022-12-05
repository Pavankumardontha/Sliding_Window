class Solution{
    public:
    int lenOfLongSubarr(int a[],  int n, int k) 
    { 
        int sum = 0;
        int ans = 0;
        unordered_map<int,int> mp;
        for(int i=0;i<n;i++)
        {
            sum = sum + a[i];
            if(sum==k)
            ans = i+1;
            else 
            {
                if(mp.find(sum-k)!=mp.end())
                ans = max(ans,i-mp[sum-k]);
            }
            if(mp.find(sum)==mp.end())
            mp[sum]=i;
        }
        return ans;
    } 

};
