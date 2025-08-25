class Solution {
public:
    int maximumScore(vector<int>& nums, int k) 
    {
        /*
        we have to for sure take the element at index k.
        So lets start i,j from k.
        In each case , we compare i-1 and j+1
        if(nums[i-1] > nums[j+1]) -> we move to the left i--
        if(nums[i-1] < nums[j+1]) -> we move to the right j++
        Our subarray spans from [i,j] 
        We will calculate the possible score in each case.
        */
        int n = nums.size();
        int i = k;
        int j = k;
        int current_score=nums[k];
        int max_score=nums[k];
        int current_window_min = nums[k];
        int current_window_size;
        int leftValue;
        int rightValue;
        while(i>0 or j<n-1)
        {
            if(j>=n-1)
            rightValue = 0;
            else
            rightValue = nums[j+1];
            if(i<=0)
            leftValue = 0;
            else
            leftValue = nums[i-1];
            if(leftValue>rightValue)
            {
                // move left
                i--;
                current_window_min = min(current_window_min,leftValue);
            }
            else if(leftValue<rightValue)
            {
                // move right
                j++;
                current_window_min = min(current_window_min,rightValue);
            }
            else
            {
                // if both are equal , extend on both sides
                i--;
                j++;
                current_window_min = min(current_window_min,rightValue);
            }
            current_window_size = j-i+1;
            current_score = current_window_min*current_window_size;
            max_score = max(max_score,current_score);
        }
        return max_score;   
    }
};
