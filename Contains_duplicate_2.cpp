class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& a, int k) 
    {
        int n = a.size();
        int start = 0;
        int end = 0;
        unordered_map<int,int>mp;
        while(start<n and end<n)
        {
            if(mp.find(a[end])!=mp.end() and mp[a[end]]==1)
            return true;
            mp[a[end]]++;
            if(end-start == k)
            {
                mp[a[start]]--;
                start++;
            }
            end++;
        }
        return false;
    }
};
