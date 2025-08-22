class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) 
    {
        /*
        Lets analyse all the options 
        1) take 0 from left + k from right
        2) take 1 from left + (k-1) from right
        3) take 2 from left + (k-2) from right
        .
        .
        In each case we calculate the points and take the maximum of all
        */
        int max_points = 0;
        int n = cardPoints.size();
        vector<int> prefix(n,0);
        int sum = 0;
        for(int i=0;i<n;i++)
        {
            sum = sum + cardPoints[i];
            prefix[i]=sum;
        }
        int points;
        if(k==n)
        return sum;
        for(int i=0;i<=k;i++)
        {
            // take i elements from the left and k-i elements from the right
            /*
            [0,1,2,3,4,5]
            [1,2,3,4,5,6]
            [1,3,6,10,15,21]
            [0,1,2,3,4,5,6]
            */
            if(i==0) // all k elements from right (last)
            points = prefix[n-1] - prefix[n-1-k];
            else if(i==k) // all k elements from the left (start)
            points = prefix[k-1];
            else // i elements from left (start) and k-i elements from right (last)
            points = prefix[i-1] + (prefix[n-1]-prefix[n-1-(k-i)]);
            max_points = max(max_points,points);
        }
        return max_points;
    }
};
