class Solution {
public:
    int totalFruit(vector<int>& fruits) 
    {
        /* length of longest substring that has only 2 distinct fruit types */
        int n = fruits.size();
        int start = 0;
        int end = 0;
        int max_len = 0;
        int current_window_size;
        unordered_map<int,int> mp;
        while(end<n)
        {
            mp[fruits[end]]++;
            current_window_size = end-start+1;
            if(mp.size()<=2)
            max_len = max(max_len,current_window_size);
            else
            {
                while(mp.size()>2)
                {
                    mp[fruits[start]]--;
                    if(mp[fruits[start]]==0)
                    mp.erase(fruits[start]);
                    start++;
                }
            }
            end++;
        }
        return max_len;
    }
};
