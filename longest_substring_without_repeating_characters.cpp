class Solution {
public:
    int lengthOfLongestSubstring(string s) 
    {
        unordered_map<char,int> mp;
        int n = s.length();
        int start=0;
        int end=0;
        int current_len=0;
        int max_len = 0;
        while(end<n)
        {
            while(end<n and mp.find(s[end])==mp.end())
            {
                mp[s[end]]++;
                end++;
            }
            current_len = end-start;
            max_len = max(max_len,current_len);
            if(end != n)
            {
                // we will move start till we find s[end]
                while(s[start]!=s[end])
                {
                    mp.erase(s[start]);
                    start++;
                }
                // start will now be at index where s[start]=s[end] and start<end
                mp.erase(s[start]);
                start++;
            }
        }
        return max_len;
    }
};
