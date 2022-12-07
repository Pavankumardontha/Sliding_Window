class Solution {
public:
    int minimumCardPickup(vector<int>& a) 
    {
        /* find 2 closest pairs having the same value. Difference in their indices is the answer. */
        unordered_map<int,int> mp;
        int n = a.size();
        int ans = INT_MAX;
        for(int i=0;i<n;i++)
        {
            if(mp.find(a[i])!=mp.end())
            ans = min(ans,i-mp[a[i]]+1);
            mp[a[i]]=i;
        }
        if(ans==INT_MAX)
        return -1;
        else
        return ans;
    }
};
