class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) 
    {
        /* find the distinct elements in the nums , let it be k 
        very very important point : In the current problem , the following equation holds true
        No. of subarrays with Exactly k different integers = No. of subarrays with
        atleast k different integers since k = total no. of distinct integers in the array
        */
        int n = nums.size();
        unordered_map<int,int> mp;
        for(int i=0;i<n;i++)
        mp[nums[i]]++;
        int k = mp.size(); // no. of distinct elements in nums
        mp.clear();
        int start = 0;
        int end = 0;
        int ans = 0;
        while(end<n)
        {
            mp[nums[end]]++;
            if(mp.size()==k)
            {
                while(mp.size()==k)
                {
                    ans = ans + (n-end);
                    mp[nums[start]]--;
                    if(mp[nums[start]]==0)
                    mp.erase(nums[start]);
                    start++;
                }
            }
            end++;
        }
        return ans;
    }
};
