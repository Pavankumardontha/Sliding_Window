/*
Lets say we have a sliding window size of 10 and the maximum frequency character has a frequency of 5.
We can then change the remaining 10-5 = 5 characters to the maximum frequency
character and make the substring containing all same characters.

So if we have a window size and the maximum frequency count, the no. of 
changes needed to convert the substring = window_size - max_frequency;
*/

class Solution {
public:
    int characterReplacement(string s, int k) 
    {
        /*
        since we want to replace only one character then 
        there should only be 2 distinct characters in our 
        substring window.
        */
        int n = s.length();
        int start=0;
        int end=0;
        unordered_map<char,int> mp;
        int changes_required;
        int max_freq=0;
        int current_window_size;
        int max_len=0;
        while(end<n)
        {
            mp[s[end]]++;
            max_freq = max(max_freq,mp[s[end]]);
            current_window_size = end-start+1;
            changes_required = current_window_size - max_freq;
            if(changes_required<=k)
            {
                max_len = max(max_len,current_window_size);
                end++;
            }
            else
            {
                // we need to move the start now
                while(changes_required>k)
                {
                    mp[s[start]]--;
                    // we now traverse through the entire map (which only at most can have 26 keys) to find the max freq
                    start++;
                    current_window_size = end-start+1;
                    max_freq = 0;
                    for(auto it=mp.begin();it!=mp.end();it++)
                    max_freq = max(max_freq,it->second);
                    changes_required = current_window_size - max_freq;
                }
                end++;
            }
        }
        return max_len;
    }
};
