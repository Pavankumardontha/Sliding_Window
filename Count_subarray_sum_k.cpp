class Solution {
public:
    int subarraySum(vector<int>& a, int k) 
    {
        int n = a.size();
        unordered_map<int,int> mp;
        int current_sum = 0;
        int ans = 0;
        mp[0]=1;
        /*
        current_sum - prefix_sum = k
        prefix_sum = current_sum - k
        so if there exists a prefix sum with value (current_sum - k) then we can make a subarray with sum k
        */
        for(int i=0;i<n;i++)
        {
            current_sum = current_sum + a[i];
            if(mp.find(current_sum-k)!=mp.end())
            ans = ans + mp[current_sum-k];
            mp[current_sum]++;
        }
        return ans;
        
    }
};
