class Solution {
public:
    int minSwaps(vector<int>& nums) 
    {
        /*
        First, count the total number of 1s in the array — let this be x.
        Next, find the maximum number of 1s that can fit inside any subarray 
        of length x. Call this value y.
        To group all 1s together, we need a subarray of length x that contains only
        1s. Currently, the best subarray of that length contains y ones, which means
        the remaining x - y elements are 0s that need to be flipped.
        Hence, the minimum number of flips required is x - y.
        */
        int n = nums.size();
        int total_ones_count=0;
        for(int i=0;i<n;i++)
        {
            if(nums[i]==1)
            total_ones_count++;
        }
        if(total_ones_count == 0 or total_ones_count == 1)
        return 0;
        int max_ones_count_in_subarray = 0; // maximum no. of 1's that can fit inside a subarray of size = total_ones_count 
        int start = 0;
        int end = 0;
        int current_window_size;
        // Note how we extract all the subarrays of current_window_size = ones_count considering array circular
        int current_window_ones_count = 0;
        while(start<n)
        {
            if(end==n)
            end = 0;
            if(nums[end]==1)
            current_window_ones_count++;
            if(end<start)
            current_window_size = (n-start) + (end+1);
            else
            current_window_size = (end-start+1);
            if(current_window_size == total_ones_count)
            {
                max_ones_count_in_subarray = max(max_ones_count_in_subarray,current_window_ones_count);
                if(nums[start]==1)
                current_window_ones_count--;
                start++;
            }
            end++;
        }
        return total_ones_count - max_ones_count_in_subarray;
    }
};
