#include <vector>
#include <unordered_map>
#include <iostream> 
class Solution {
public:
    int findMaxLength(std::vector<int>& nums) {
        std::unordered_map<int, int> m;
        m[0] = -1;
        int len = 0, count = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            count = count + (nums[i] == 1 ? 1 : -1);
            if(m.find(count) != m.end())
                len = std::max(len, i - m[count]);
            else
                m[count] =  i;
        }
        return len;
    }
};
int main ()
{
    std::vector<int> nums = {0,1,0,1};
    Solution temp;
    std::cout << temp.findMaxLength(nums) << std::endl;

    return 0;
}