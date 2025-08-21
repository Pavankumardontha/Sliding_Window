class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) 
    {
        int n = s.length();
        int start = 0;
        int end = 0;
        int max_len=0;
        int current_len=0;
        int current_cost = 0;
        while(end<n)
        {
            // add character at index end to the substring s(start,end)
            while(end<n and current_cost + abs(s[end]-t[end])<=maxCost)
            {
                current_cost += abs(s[end]-t[end]);
                end++;
            }
            current_len = end - start;
            max_len = max(max_len,current_len);
            if(end!=n)
            {
                /*
                we start removing elements from the start such that 
                current_cost + abs(s[end]-t[end]) <= maxCost
                */
                while(current_cost + abs(s[end]-t[end]) > maxCost)
                {
                    // start removing elements from the start and decrement current_cost
                    current_cost -= abs(s[start]-t[start]);
                    start++;
                }
                if(start==end)
                {
                    // our current_cost will now be zero since we have removed all the added characters of the substring
                    if(abs(s[end]-t[end])>maxCost)
                    {
                        end++;
                        start++;
                    }
                }
            }
        }
        return max_len;
    }
};
