class Solution {
public:
    int numSubarraysWithSum(vector<int>& a, int k) 
    {
        /* count of subarrays with given sum */
        unordered_map<int,int> mp;
        mp[0]=1;
        int sum = 0;
        int cnt = 0;
        int n = a.size();
        for(int i=0;i<n;i++)
        {
            sum = sum + a[i];
            if(mp.find(sum-k)!=mp.end())
            cnt = cnt + mp[sum-k];
            mp[sum]++;
        }
        return cnt;
    }
};
