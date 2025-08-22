class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) 
    {
        /*
        Lets say we have an array a=[1,2,3,4..n]
        which all form an arithmetic sequence , the no. of arithmetic
        slices are 
        a = [1,2,3] => 1
        a = [1,2,3,4] => 3
        a = [1,2,3,4,5] => 3 + 2 + 1 => 6
        a = [1,2,3,4,5,6] => 4 + 3 + 2 + 1 => 10
        .
        .
        so if the size of a subarray that forms an arithmetic sequence is x,
        then the no. of arithmetic slices = (x-2) + (x-3) . . . 1
        */
        int n = nums.size();
        if(n<3)
        return 0;
        int start = 0;
        int end = 0;
        int current_len = 0;
        int ans = 0;
        while(end<n-2)
        {
            int d = nums[end+1]-nums[end];
            while(end<n-1 and nums[end+1]-nums[end]==d)
            end++;

            current_len = end-start+1;
            ans += (current_len-2)*(current_len-1)/2;
            start = end;
        }
        return ans;
    }
};
