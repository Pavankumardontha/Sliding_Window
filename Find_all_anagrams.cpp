class Solution {
public:
    vector<int> findAnagrams(string s, string p) 
    {
        int n1 = p.length();
        int n2 = s.length();
        unordered_map<char,int> mp1,mp2;
        /*store all the characters in p with their frequency count */
        for(int i=0;i<n1;i++)
        mp1[p[i]]++;

        vector<int> ans;
        int start=0;
        int end=0;
        while(start<n2 and end<n2)
        {
            if(mp1.find(s[end])!=mp1.end())
            {
                /* if the present character is present in p , increment its map count */
                mp2[s[end]]++;
            }
            if(end-start+1==n1)
            {
                /* if size of the windown becomes equal to the size of p, then see if mp1 matches mp2.
                if mp1 equals mp2 then we have an answer. 
                */
                if(mp1==mp2)
                ans.push_back(start);

                /*
                check if frequency of start is greater than 1. If it is greater than  1 then just decrement
                its frequency by 1 and if it is equal to 1,remove it from the map.
                */
                if(mp2[s[start]]>1)
                mp2[s[start]]--;
                else
                mp2.erase(s[start]);
                start++;
            }
            end++;
        }
        return ans;
    }
};
