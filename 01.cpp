//
// Created by 陶剑浩 on 2018/7/27.
//
/*
给定一个整数数组和一个目标值，找出数组中和为目标值的两个数。

你可以假设每个输入只对应一种答案，且同样的元素不能被重复利用。

示例:

给定 nums = [2, 7, 11, 15], target = 9

因为 nums[0] + nums[1] = 2 + 7 = 9
所以返回 [0, 1]
*/
#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target)
    {
        for(vector<int>::iterator iterator1=nums.begin();iterator1!=nums.end();iterator1++)
        {
            for(vector<int>::iterator iterator2 = iterator1+1;iterator2!=nums.end();iterator2++)
            {
                if(*iterator1+*iterator2==target)
                {
                    vector<int> answer;
                    answer.push_back(distance(nums.begin(),iterator1));
                    answer.push_back(distance(nums.begin(),iterator2));
                    return answer;
                }
            }
        }
    }
};


int main()
{
    Solution sl;
    vector<int> nums = {2, 7, 11, 15};
    vector<int> answer = sl.twoSum(nums,9);
    for(auto a:answer)
    {
        cout<<a<<",";
    }
    return 0;
}