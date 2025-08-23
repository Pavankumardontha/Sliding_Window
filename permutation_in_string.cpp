class Solution {
public:
    bool checkInclusion(string s1, string s2) 
    {
        /*
        for s2 to contain a permutation of s1, there should be a subtring s in s2 which 
        contains all the characters present in s1 including duplicates. There should not 
        be any extra character . It should only contain the characters present in s1.

        we will slide over all the substrings of s2 of length n1.
        Example : s1 = "ab" s2 = "eidbaooo"
        Here we will slide over all the 2 length substrings of s2 and find if it contains 
        a permutation of s1.
        */
        unordered_map<char,int> mp1;
        int n1 = s1.length();
        for(int i=0;i<n1;i++)
        mp1[s1[i]]++;
        unordered_map<char,int> mp2;
        // iterating over all the substrings of s2 of length n1
        int n2 = s2.length();
        if(n1>n2)
        return false;
        int start = 0;
        int end = 0;
        int current_window_size=0;
        while(end<n2)
        {
            mp2[s2[end]]++;
            current_window_size = end-start+1;
            if(current_window_size == n1)
            {
                if(mp1==mp2)
                return true;
                else
                {
                    // move start
                    mp2[s2[start]]--;
                    if(mp2[s2[start]]==0)
                    mp2.erase(s2[start]);
                    start++;
                }
            }
            end++;
        }
        return false;
    }
};
