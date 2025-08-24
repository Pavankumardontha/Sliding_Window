class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) 
    {
        int max_len=0;
        int start=0;
        int end=0;
        unordered_map<int,int> mp;
        int current_window_size = 0;
        int n = nums.size();
        while(end<n)
        {
            mp[nums[end]]++;
            current_window_size = end-start+1;
            if(mp[nums[end]]<=k)
            max_len = max(max_len,current_window_size);
            else
            {
                // we need to move start till it crosses the index i such that nums[i]=nums[end] since we want to decrement its frequency by 1
                while(mp[nums[end]]>k)
                {
                    mp[nums[start]]--;
                    start++;
                }
            }
            end++;
        }
        return max_len;
    }
};
