class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int len = nums.size();
        vector<int> count(32,0);
        for (int i=0;i<nums.size();i++)
        {
            int num = nums[i];
            for (int j=0;j<32;j++)
            {
                if (num&1)
                    count[j] ++;
                num = num >> 1;
            }
        }
        int ans = 0;
        int flag = 1;
        for (int i=0;i<32;i++)
        {
            if (count[i]>(len/2))
                ans += flag;
            flag = flag << 1;
        }
        return ans;
    }
};
