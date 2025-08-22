class Solution {
public:
    int kDistinctChar(string& s, int k) 
    {
        int n = s.length();
        int start = 0;
        int end = 0;
        int current_size_window;
        int max_len = 0;
        unordered_map<char,int> mp;
        while(end<n)
        {
            mp[s[end]]++;
            current_size_window = end - start + 1;
            if(mp.size()<=k)
            max_len = max(max_len,current_size_window);
            else
            {
                while(mp.size()>k)
                {
                    mp[s[start]]--;
                    if(mp[s[start]]==0)
                    mp.erase(s[start]);
                    start++;
                }
            }
            end++;
        }
        return max_len;
    }
};
