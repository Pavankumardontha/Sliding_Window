class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& a, int k) 
    {
        /*
        lets take the test case of [10,5,2,6] and k = 100
        No of subarrays with first 1 element = [10] = 1
        No of subarrays with first 2 elements = [10,5] , [5] = 2 
        No of subarrays with first 3 elements = [10,5,2] , [5,2] , [2] = 3
        .
        .
        So by adding each element to the array at index i , you are adding (i+1) extra subarrays to already 
        existing subarrays. 
        So initially our start and end will be at 0 and we have only [10] with us and current_product = 10 
        [start,end] is our current subarray
        we will add 5 to it and see if the product is less than k or not 
        if it is less we add (j-i) + 1 to our count of subarrays 
        if it is greater , than we remove the element at index start and see the product.We repeat this step
        untill we get a product which is less than k and then add 
        */
        int start = 0;
        int end = 0;
        int n = a.size();
        int current_product = 1;
        int ans = 0;
        while(start<n and end<n)
        {   
            current_product = current_product*a[end];
            /* 
            we have to start removing elements from the front if and only if our current_product is greater
            than or equal to k
            */
            while(current_product>=k and start<=end)
            {
                /* removing the start element untill product is less than k */
                current_product = current_product/a[start];
                start++;
            }
            if(start<=end)
            {
                /* when we have any element x greater than k , then there exists no subarray which will 
                contain this x and start becomes greater than end by 1*/
                ans = ans + (end-start) + 1;
            }
            end++;
        }
        return ans;
        
    }
};
