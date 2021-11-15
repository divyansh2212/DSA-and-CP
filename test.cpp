class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) 
    {
        vector<int> ans;
        vector<int> prefixXr(nums.size());
        prefixXr[0] = nums[0];
        for(int i=1; i < nums.size(); i++)
        {
            prefixXr[i] = (prefixXr[i-1] ^ nums[i]);
        }
        
        for(int i= nums.size()-1; i >= 0 ; i--)
        {
            for(int j=0; j < (1 << maximumBit); j++)
            {
                if((prefixXr[i] ^ j) == ((1 << maximumBit) - 1))
                {
                    ans.push_back(j); break;
                }
            }
        }

        return ans;
    }
};