/*
Here we need to find the subarrays with exactly k different integers.
Lets say we are finding the subarrays count of atleast k different integers. 
Let No. of subarrays with atleast k different integers = Atleast(k)
Let No. of subarrays with exactly k different integers = Exactly(k), then
Atleast(k) = Exactly(k) + Exactly(k+1) . . . Exactly(n1) -> 1, where n1 = no. of distinct integers in the entire array 
Similarly, 
Atleast(k+1) = Exactly(k+1) + Exactly(k+2) . . . Exactly(n1) -> 2

from 1 and 2 , we get 
Atleast(k) = Exactly(k) + Atleast(k+1)
=> Exactly(k) = Atleast(k) - Atleast(k+1)
=> No. of subarrays with exactly k different integers = No. of subarrays with atleast k different integers - No. of subarrays with atleast (k+1) different integers !!
*/
int subarraysWithAtleastKDistinct(vector<int>& nums, int k)
{
    int n = nums.size();
    int start=0;
    int end = 0;
    int ans = 0;
    int current_window_size;
    unordered_map<int,int> mp;
    while(end<n)
    {
        mp[nums[end]]++;
        current_window_size = end-start+1;
        if(mp.size()==k)
        {
            ans = ans + (n-end);
            // we will now move the start index
            while(mp.size()==k)
            {
                mp[nums[start]]--;
                if(mp[nums[start]]==0)
                mp.erase(nums[start]);
                start++;
                if(mp.size()==k)
                ans = ans + (n-end);
            }
        }
        end++;
    }
    return ans;
}

class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) 
    {
        int ans = subarraysWithAtleastKDistinct(nums,k) - subarraysWithAtleastKDistinct(nums,k+1);
        return ans;
    }
};
