class Solution {
public:
    int subarraysDivByK(vector<int>& a, int k) 
    {
        /*
        lets say we have 2 subarrays [0,i] and [0,j]
        2 3 5 4 5 3 4 
            i     j
        
        if subarray sum [0,i] = x1 and it leaves remainder r1 when divided by k then 
        x1 = k*n1 + r1
        if subarray sum [0,j] = x2 and it leaves remainder r2 when divided by k then
        x2 = k*n2 + r2 

        Now the subarray sum [i+1,j+1] = x2-x1 = k*(n2-n1) + r2-r1 is divisible by k if and only if r2=r1 
        Generally negative numbers give negative remainders. So if remainder is negative we just add k to
        it.
        ex : [-1,2,9] k = 2
        current_sum  = cs = -1 , ans = 0 mp[-1]=1 , mp[0]=1
        cs = -1+2 = 1 , r = 1, ans = 0 mp[-1]=1 , mp[0]=1, mp[1]=1 
        cs = 1 + 9 = 10 , r = 0 , ans = 1 , mp[-1]=1 , mp[0]=2, mp[1]=1
        which is not the correct answer. If we add +k if the remainder is negative for negative integers
        then our process gives is the correct result.
        */
        int n = a.size();
        unordered_map<int,int> mp;
        mp[0]=1;
        int ans = 0;
        int current_sum = 0;
        for(int i=0;i<n;i++)
        {
            current_sum = current_sum + a[i];
            int r = current_sum%k;
            if(r<0)
            r=r+k;
            if(mp.find(r)!=mp.end())
            ans = ans + mp[r];
            mp[r]++;
        }
        return ans;
    }
};
