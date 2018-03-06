class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int num;
        int count = 0;
        for (int i=0;i<nums.size();i++)
        {
            if(count==0)
            {
                num = nums[i];
                count++;
            }
            else
            {
                if (nums[i]==num)
                    count ++;
                else
                    count --;
            }
        }
        return num;
    }
};
