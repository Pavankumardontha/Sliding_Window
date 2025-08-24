/*
If we want to exactly count no. of subarrays having only k odd numbers then we need to 
use the technique of counting subarrays having atleast k odd numbers and atleast (k+1)
odd numbers.
No of subarrays having exactly k odd numbers = Exactly(k)
No. of subarrays having atleast k odd numbers = Atleast(k)
Then the solution is 
Exactly(k) = Atleast(k) - Atleast(k+1)
*/

int numberofSubarraysHavingAtleastKOddNumbers(vector<int>& nums, int k)
{
    int n = nums.size();
    int start = 0;
    int end = 0;
    int odd_count = 0; // total odd numbers count in the current window 
    int ans = 0; // total subarrays count having atleast k odd numbers
    while(end<n)
    {
        if(nums[end]%2==1)
        odd_count++;
        while(odd_count == k)
        {
            ans = ans + (n-end);
            if(nums[start]%2==1)
            odd_count--;
            start++;
        }
        end++;
    }
    return ans;
}

class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) 
    {
        return numberofSubarraysHavingAtleastKOddNumbers(nums,k) - numberofSubarraysHavingAtleastKOddNumbers(nums,k+1);
    }
};
