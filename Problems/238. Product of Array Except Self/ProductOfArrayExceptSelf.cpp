#include <vector>
#include <string>
#include <algorithm>
#include <iostream> 
class Solution {
public:
    std::vector<int> productExceptSelf(std::vector<int>& nums) {
        std::vector<int> left, right;
        int sum = 1;
        for(int i = 0; i < nums.size(); i++)
        {
            sum *= nums[i];
            left.push_back(sum);
        }

        sum = 1;
        for(int i = nums.size()-1; i >= 0; i--)
        {
            sum *= nums[i];
            right.push_back(sum); 
        }
        std::reverse(right.begin(), right.end());

        for(int i = 0; i < nums.size(); i++)
        {
            if(i == 0)
            {
                nums[i] = right[1];
            }
            else if( i == nums.size()-1)
            {
                nums[i] = left[nums.size()-2];
            }
            else
            {
                nums[i] = left[i-1]*right[i+1];
            }
        }
        return nums;
    }
};
int main ()
{
    std::vector<int> nums = {1,2,3,4};
    Solution temp;
    nums = temp.productExceptSelf(nums);
    for(auto x : nums)
        std::cout << x << std::endl;

    return 0;
}