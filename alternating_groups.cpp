/* 
We are given colors = [0,1,0,1,0], k = 3  
We use a sliding window defined by [start, end].  
The goal is to count subarrays of length k that form a valid alternating sequence.  

Step-by-step process:  
1) Initialize start = 0, end = 0. Expand the window by moving end.  
2) For each new element at index end, check the previous element:
   - If nums[end] != nums[(end-1) % n], then the sequence is still alternating, 
     so we can safely include nums[end] in our current window.  
   - Otherwise (nums[end] == nums[end-1]), the alternating property is broken.  
     In this case, any subarray that includes both nums[end-1] and nums[end] 
     cannot be alternating.  
     → So we reset the window: set start = end (begin a new sequence from here).  
3) Whenever the current window size reaches k:
   - We found one valid alternating subarray of length k.  
   - Increment ans by 1.  
   - Then slide the window forward by incrementing start (to continue checking further windows).  

We repeat this until start >= n.  
---
Example: colors = [0,1,0,0,1,0,1], k = 6  
1) start = 0, end = 0  
2) start = 0, end = 1 → alternating so far  
3) start = 0, end = 2 → still alternating  
4) start = 0, end = 3 → here nums[2] = nums[3], so alternating breaks.  
   - Any subarray containing both nums[2] and nums[3] is invalid.  
   - Reset: set start = end = 3, and continue.  
This ensures we only consider valid alternating subarrays.  
*/ 

class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) 
    {
        /* similar to question - Minimum swaps to group all 1's together - II */
        int n = colors.size();
        int start = 0;
        int end = 0;
        int current_window_size;
        int prev; // previous element
        int ans = 0;
        while(start<n)
        {
            if(start<end)
            {
                if(colors[(end-1)%n]!=colors[end%n])
                {
                    current_window_size = end - start + 1;
                    if(current_window_size==k)
                    {
                        ans++;
                        start++;
                    }
                }
                else
                start=end;
            }
            end++;
        }
        return ans;
    }
};
