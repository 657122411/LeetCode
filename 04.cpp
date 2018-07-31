//
// Created by �ս��� on 2018/7/31.
//

/*
����������СΪ m �� n ���������� nums1 �� nums2 ��
���ҳ������������������λ����Ҫ���㷨��ʱ�临�Ӷ�Ϊ O(log (m+n)) ��
����Լ��� nums1 �� nums2 ����Ϊ�ա�
ʾ�� 1:
nums1 = [1, 3]
nums2 = [2]
��λ���� 2.0
ʾ�� 2:
nums1 = [1, 2]
nums2 = [3, 4]
��λ���� (2 + 3)/2 = 2.5
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