vector<long long> printFirstNegativeInteger(long long int a[],long long int n, long long int k) 
{
    vector<long long> ans;
    int start = 0;
    int end = 0;
    queue<int> q;
    while(start<n and end<n)
    {
        if(a[end]<0)
        q.push(end);
        if(end-start+1==k)
        {
            if(q.empty())
            ans.push_back(0);
            else
            {
                ans.push_back(a[q.front()]);
                if(q.front()==start)
                q.pop();
            }
            start++;
        }
        end++;
    }
    return ans;                                             
}
