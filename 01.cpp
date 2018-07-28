//
// Created by �ս��� on 2018/7/27.
//
/*
����һ�����������һ��Ŀ��ֵ���ҳ������к�ΪĿ��ֵ����������

����Լ���ÿ������ֻ��Ӧһ�ִ𰸣���ͬ����Ԫ�ز��ܱ��ظ����á�

ʾ��:

���� nums = [2, 7, 11, 15], target = 9

��Ϊ nums[0] + nums[1] = 2 + 7 = 9
���Է��� [0, 1]
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