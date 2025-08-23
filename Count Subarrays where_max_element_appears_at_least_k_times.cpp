/*
We are given nums = [1,3,2,3,3] and k = 2.
The maximum element in the array is 3.
We want to count the number of subarrays where this maximum element appears at least k times.

Step-by-step walkthrough:
1) Start with start = 0, end = 0:
Window = [1], frequency map = {1:1}
Max element 3 hasn’t appeared enough times yet.

2) Expand to end = 1:
Window = [1,3], frequency map = {1:1, 3:1}
3 appears once, still < k.

3) Expand to end = 2:
Window = [1,3,2], frequency map = {1:1, 3:1, 2:1}
3 appears once, still < k.

4) Expand to end = 3:
Window = [1,3,2,3], frequency map = {1:1, 2:1, 3:2}
Now 3 appears twice, which satisfies k = 2.
At this point, any extension of this subarray (by adding more elements to the right) will 
also satisfy the condition.
Array length = 5
Current end = 3
Number of valid subarrays starting at start = 0 = len - end = 5 - 3 = 2
→ [1,3,2,3], [1,3,2,3,3]
Total count so far = 2

5) Move start forward → start = 1:
Window = [3,2,3], frequency map = {3:2, 2:1}
3 appears twice → valid again.
Number of valid subarrays = 5 - 3 = 2
→ [3,2,3], [3,2,3,3]
Total count = 4

6) Move start forward → start = 2:
Window = [2,3], frequency map = {2:1, 3:1}
3 appears only once → not valid.
So, we expand end.

7) Expand end = 4:
Window = [2,3,3], frequency map = {2:1, 3:2}
3 appears twice → valid.
Number of valid subarrays = 5 - 4 = 1
→ [2,3,3]
Total count = 5

8) Move start = 3:
Window = [3,3], frequency map = {3:2}
3 appears twice → valid.
Number of valid subarrays = 5 - 4 = 1
→ [3,3]
Total count = 6
*/

int findMax(vector<int>& nums, int& n)
{
    int ans = nums[0];
    for(int i=0;i<n;i++)
    ans = max(ans,nums[i]);
    return ans;
}

class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) 
    {
        int n = nums.size();
        int long long ans=0;
        int current_window_size;
        int start=0;
        int end = 0;
        unordered_map<int,int> mp;
        int max_element = findMax(nums,n);
        mp[max_element] = 0;
        while(end<n)
        {
            mp[nums[end]]++;
            if(mp[max_element]==k)
            {
                ans = ans + (n-end);
                // start moving 'start' index
                while(mp[max_element]==k)
                {
                    mp[nums[start]]--;
                    if(mp[max_element]==k)
                    ans = ans + (n-end);
                    start++;
                }
            }
            end++;
        }
        return ans;
    }
};
