class Solution {
public:
    long long countSubarrays(vector<int>& a, long long k) 
    {
        int n = a.size();
        long long current_sum=0;
        long long current_score = 0;
        long long ans = 0; // count of subarrays
        int start = 0;
        int end = 0;
        while(start<n and end<n)
        {
            current_sum = current_sum + a[end];
            current_score = current_sum*(end-start+1);
            while(current_score>=k and start<=end)
            {
                /* start removing elements from the right */
                current_sum = current_sum - a[start];
                start++;
                current_score = current_sum*(end-start+1);
            }
            if(start<=end)
            ans = ans + (end-start)+1;
            end++;
        }
        return ans;
    }
};
