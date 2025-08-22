/* this problem is similar to Longest repeating character replacement problem we will track the frequency of 1's here  */
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) 
    {
        int freq = 0;
        int start = 0;
        int end = 0;
        int n = nums.size();
        int current_window_size=0;
        int flips_required=0;
        int max_len = 0;
        while(end<n)
        {
            if(nums[end]==1)
            freq++;
            current_window_size = end-start+1;
            flips_required = current_window_size - freq; // this gives no. of 0's count in current window
            if(flips_required <= k)
            {
                max_len = max(max_len,current_window_size);
            }
            else
            {
                while(flips_required>k)
                {
                    if(nums[start]==1)
                    freq--;
                    start++;
                    current_window_size = end-start+1;
                    flips_required = current_window_size - freq;
                }
            }
            end++;
        }
        return max_len;   
    }
};
