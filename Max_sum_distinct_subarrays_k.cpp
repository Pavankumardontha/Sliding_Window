class Solution {
public:
    long long maximumSubarraySum(vector<int>& a, int k) 
    {
        int n = a.size();
        int start = 0;
        int end = 0;
        unordered_map<int,int> mp;
        long long current_sum = 0;
        long long ans = 0;
        /*
        insert delete search all operations on average take O(1) time. 
        */
        while(start<n and end<n)
        {
            current_sum = current_sum + a[end];
            mp[a[end]]++;
            if(end-start+1==k)
            {
                if(mp.size()==k)
                ans = max(ans,current_sum);
                current_sum = current_sum - a[start];
                if(mp[a[start]]==1)
                mp.erase(a[start]);
                else
                mp[a[start]]--;
                start++;
            }
            end++;
        }
        return ans;
    }
};
