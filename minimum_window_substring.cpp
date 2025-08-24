/*
Since the string s contains only lowercase letters, the frequency map will have at most 26 entries.
First, we compute the frequency map of string t (let’s call it mp1). Next, we iterate over s using a sliding window. As we expand 
the window by moving the end pointer, we maintain another frequency map (mp2) that tracks the characters inside the current window.
At each step, we check whether the current window satisfies the requirement — i.e., the frequency of every character in the window (mp2) must 
be greater than or equal to the corresponding frequency in mp1.
Once this condition is met, the current window contains all characters of t, and at that point we can start considering its length (for example, 
to minimize or count valid windows).
*/
bool doesFrequencyMatch(unordered_map<char,int>& mp1, unordered_map<char,int>& mp2)
{
    // mp1 belongs to t and mp2 belongs to current window
    for(auto it=mp1.begin();it!=mp1.end();it++)
    {
        if(mp2.find(it->first)!=mp2.end())
        {
            if(mp2[it->first]<mp1[it->first])
            return false;
        }
        else
        return false;
    }
    return true;
}

class Solution {
public:
    string minWindow(string s, string t) 
    {
        unordered_map<char,int> mp1; // tracks the frequency of all characters in t
        int n1 = t.length();
        int n2 = s.length();
        for(int i=0;i<n1;i++)
        mp1[t[i]]++;

        unordered_map<char,int> mp2; // tracks frequency of characters in the current window
        int start=0;
        int end=0;
        int current_window_size;
        int min_len=200001; // length of minimum window substring
        int starting_index_of_min_window=-1;
        string ans="";
        while(end<n2)
        {
            mp2[s[end]]++;
            if(doesFrequencyMatch(mp1,mp2))
            {
                while(doesFrequencyMatch(mp1,mp2))
                {
                    current_window_size = end - start + 1;
                    if(min_len > current_window_size)
                    {
                        min_len = current_window_size;
                        starting_index_of_min_window = start;
                    }
                    mp2[s[start]]--;
                    start++;
                }
            }
            end++;
        }
        if(starting_index_of_min_window != -1)
        ans = s.substr(starting_index_of_min_window,min_len);
        return ans;
    }
};
