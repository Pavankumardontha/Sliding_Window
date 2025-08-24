/*
Given a = [1,1,1,1]
          [0,1,2,3]
find no. of pairs where pairs of indices (i, j) such that i < j and a[i] == a[j].
ans : (0,1) (0,2) (0,3) (1,2) (1,3) (2,3)
pair_count = 0
1) Initially mp[1]=0 , new 1 comes so mp[1]=1 , pair_count = mp[1]-1 = 1-1 = 0
2) mp[1] = 1, new 1 comes so mp[1]=2, pair_count = pair_count + mp[1]-1 = 0 + 2-1 = 1 
3) mp[1] = 2 , new 1 comes so mp[1]=3 , pair_count = pair_count + mp[1]-1 = 1 + 3-1 = 3
4) mp[1] = 3 , new 1 comes so mp[1]=4 , pair_count = pair_count + mp[1]-1 = 3 + 4-1 = 6
and the loop ends.

Coming to the decrement part , lets say start = 0 , and mp[1]=4
We want to move start by 1, In this case we need to decrement the pair count . We need to remove all the 
pairs formed by using the start index.
if nums[start]=1 and mp[nums[start]]= 4 => this means there are mp[nums[start]]-1 no. of pairs which are 
formed using the start index. We need to subtract these from the total_pair_count while we move the start
index.
*/
class Solution {
public:
    long long countGood(vector<int>& nums, int k) 
    {
        int n = nums.size();
        int start = 0;
        int end = 0;
        unordered_map<int,int> mp;
        for(int i=0;i<n;i++)
        mp[nums[i]]=0;
        int pair_count = 0; // count of pairs satisfying the given condition in the current window
        long long int ans = 0;
        while(end<n)
        {
            mp[nums[end]]++;
            pair_count += mp[nums[end]]-1;
            while(pair_count>=k)
            {
                ans = ans + (n-end);
                // decrement the pair count by removing all the pairs which are formed by the start index
                pair_count -= mp[nums[start]]-1;
                mp[nums[start]]--;
                start++;
            }
            end++;
        }
        return ans;
    }
};
