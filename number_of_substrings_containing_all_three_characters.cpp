class Solution {
public:
    int numberOfSubstrings(string s) 
    {
        /*
        stop at a point where we have all the 3 characters occur in the substring.
        for example s = "abcabc"
        we will stop at index 2.
        If we consider all the characters starting from 0 to index 2 , we will have all the 3 characters in the substring s(0,2)
        now , any substring starting from start=0 and end>=2 will all count into answers. 
        Example:
        "abc" , "abca" "abcab" "abcabc" => no. of substrings starting from index=0 and having all 3 characters = len(s)-end = 6-2=4
        we will now move start till any of the 3 characters miss in the range [start,end]
        */
        unordered_map<char,int> mp;
        int start = 0;
        int end = 0;
        int n = s.length();
        int ans = 0;
        while(end<n)
        {
            if(s[end]=='a' or s[end]=='b' or s[end]=='c')
            mp[s[end]]++;

            if(mp.size()==3)
            {
                // we got the substring s(start,end) with all the 3 characters present.
                ans += n-end;
                cout<<ans<<endl;
            }
            while(mp.size()==3)
            {
                mp[s[start]]--;
                if(mp[s[start]]==0)
                mp.erase(s[start]);
                else
                ans += n-end;
                start++;
            }
            end++;
        }
        return ans;
    }
};
