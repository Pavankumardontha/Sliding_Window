class Solution {
public:
    int longestSubarray(vector<int>& nums) 
    {
        int n = nums.size();
        int start=0;
        int end = 0;
        int current_window_size;
        int zero_count = 0; // tracks 0's count in the current window
        int one_count = 0; // tracks 1's count in the current window
        int max_len = 0;
        while(end<n)
        {
            if(nums[end]==0)
            zero_count++;
            if(zero_count<=1)
            {
                current_window_size = end-start+1;
                one_count = current_window_size - 1; // you must always delete one element
                max_len = max(max_len, one_count);
                cout<<max_len<<" "<<end<<endl;
            }
            else
            {
                while(zero_count>1)
                {
                    if(nums[start]==0)
                    zero_count--;
                    start++;
                }
            }
            end++;
        }
        return max_len;
    }
};
