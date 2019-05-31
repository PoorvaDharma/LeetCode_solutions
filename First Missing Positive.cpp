class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        
        int n = nums.size();
        int val;
        int nxt;
        if(!n)
          return 1;
        
        for(int i = 0;i<n;i++)
        {
            if(nums[i]<=0 || nums[i]>n)
                continue;
            
            val = nums[i];
            
            //store each number at index-1 position if the number is -ve or greater than n ignore
            while( val !=  nums[val-1])
            {
                nxt = nums[val-1];
                nums[val-1] = val;
                val = nxt;
                if(val<=0 || val>n)
                    break;
            }  
        }
        
        //find the first number that is out of place return the index
        for(int i=0;i<n;i++)
        {
            if(nums[i]!=i+1)
                return  i+1;
        }
       return n+1;
    }
};
