/*
Since its a binary subarray the values are only 0's and 1's.
if the goal is x , we need no. of subarrays in which there are exactly x 1's
Let the no. of subarrays in which there are exatly x 1's be = Exactly(x)
Lets the no. of subarrays in which there are atleast x 1's be = Atleast(x)
then 
Atleast(x) = Exactly(x) + Exactly(x+1) ... Exactly(n) -> 1, where n is the total no. of 1's in the array
Similarly , 
Atleast(x+1) = Exactly(x+1) + Exactly(x+2)....Exactly(n) -> 2

from 1,2 we have 
Atleast(x) = Exactly(x) + Atleast(x+1)
Exactly(x) = Atleast(x) - Atleast(x+1)  
*/

int numSubarraysWithSumAtleastK(vector<int>& nums, int k)
{
    int n = nums.size();
    int start = 0;
    int end = 0;
    int current_window_size;
    int ans = 0;
    int sum = 0; // count of 1's in the current_window
    while(end<n)
    {
        if(nums[end]==1)
        sum++;
        current_window_size = end-start+1;
        if(sum==k)
        {
            ans = ans + (n-end);
            while(sum==k)
            {
                if(nums[start]==1)
                sum--;
                start++;
                if(sum==k)
                ans = ans + (n-end);
            }
        }
        end++;
    }
    return ans;
}
class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) 
    {
        int n = nums.size();
        if(goal==0)
        {
            // no of subarrays with sum atleast 0 = All non empty subarrays of nums = n*(n+1)/2 where n is the size of the array 
            return n*(n+1)/2 - numSubarraysWithSumAtleastK(nums,goal+1);
            
        }
        return numSubarraysWithSumAtleastK(nums,goal) - numSubarraysWithSumAtleastK(nums,goal+1);
    }
};
