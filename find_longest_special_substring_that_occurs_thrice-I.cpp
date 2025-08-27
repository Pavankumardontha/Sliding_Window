int countOfSubstring(int i, int j, string& s)
{
    // returns the count of no. of times the substring s[i,j] occurs in the entire string s
    // time complexity = O(N^(2)) because of substr function being used in the while loop
    int n = s.length();
    int current_window_size;
    int required_window_size=j-i+1;
    string required_substring = s.substr(i,required_window_size);
    string current_substring;
    int ans = 0;
    int start = 0;
    int end = 0;
    while(end<n)
    {
        current_window_size = end-start+1;
        if(current_window_size == required_window_size)
        {
            current_substring = s.substr(start,current_window_size);
            if(current_substring == required_substring)
            ans++;
            start++;
        }
        end++;
    }
    return ans;
}

class Solution {
public:
    int maximumLength(string s) 
    {
        /* 
        we will generate all the possible substrings of s having same characters and 
        then calculate how many times the substring ocurred in the string 
        */
        int n = s.length();
        int max_len=-1; // max length of substring
        int current_len; // current length of substring
        int current_substring_count;
        for(int i=0;i<n;i++)
        {
            for(int j=i;j<n;j++)
            {
                if(s[i]!=s[j])
                break;
                current_len = j-i+1;
                current_substring_count = countOfSubstring(i,j,s);
                if(current_len > max_len and current_substring_count>=3)
                max_len = current_len;
            }
        }
        return max_len;
    }
};

/*
Maximum length = 50
No. of possible substrings for a string of length n = n(n+1)/2
No of possible substrings for a string of length 50 = 25*51 => 1275
For each substring , we are counting the no. of times it occurred in the string which takes O(N^(2))
time complexity
So the entire time complexity = N(N+1)*N^2 `=~ N^(4) < 10^(8)
*/
