class Solution {
public:
    int numberOfSubstrings(string s, int k) 
    {
        int n = s.length();
        int start=0,end=0;
        int current_window_size;
        unordered_map<char,int> mp;
        int ans = 0;
        while(end<n)
        {
            mp[s[end]]++;
            current_window_size = end-start+1;
            if(mp[s[end]]==k)
            {
                while(mp[s[end]]==k)
                {
                    ans = ans + (n-end);
                    mp[s[start]]--;
                    if(mp[s[start]]==0)
                    mp.erase(s[start]);
                    start++;
                }
            }
            end++;
        }
        return ans;
    }
};
