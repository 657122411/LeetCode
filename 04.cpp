//
// Created by 陶剑浩 on 2018/7/31.
//

/*
给定两个大小为 m 和 n 的有序数组 nums1 和 nums2 。
请找出这两个有序数组的中位数。要求算法的时间复杂度为 O(log (m+n)) 。
你可以假设 nums1 和 nums2 均不为空。
示例 1:
nums1 = [1, 3]
nums2 = [2]
中位数是 2.0
示例 2:
nums1 = [1, 2]
nums2 = [3, 4]
中位数是 (2 + 3)/2 = 2.5
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
    {
        vector<int> nums3;
        for(vector<int>::iterator iter=nums1.begin();iter<nums1.end();)
        {
            nums3.push_back(*iter);
            iter++;
        }
        for(vector<int>::iterator iter=nums2.begin();iter<nums2.end();)
        {
            nums3.push_back(*iter);
            iter++;
        }
        sort(nums3.begin(),nums3.end());
        int index = nums3.size()/2;
        int odd = nums3.size()%2;
        if(odd==1)
        {
            return nums3.at(index);
        }
        else
        {
            return ((double)nums3.at(index-1)+(double)nums3.at(index))/2;
        }

    }
};

int main()
{
    vector<int> nums1 = {1,2};
    vector<int> nums2 = {3,4};
    Solution sl;
    cout<<sl.findMedianSortedArrays(nums1,nums2);
    return 0;
}