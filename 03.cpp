//
// Created by �ս��� on 2018/7/30.
//

/*
����һ���ַ������ҳ��������ظ��ַ�����Ӵ��ĳ��ȡ�

ʾ����
���� "abcabcbb" ��û���ظ��ַ�����Ӵ��� "abc" ����ô���Ⱦ���3��
���� "bbbbb" ������Ӵ����� "b" ��������1��
���� "pwwkew" ����Ӵ��� "wke" ��������3����ע��𰸱�����һ���Ӵ���"pwke" �� ������  �������Ӵ���
 */

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s)
    {

        if(s=="")
        {
            return 0;
        }
        if(s.size()==1)
        {
            return 1;
        }
        vector<int> length;
        vector<char> subs;
        for(int i=0;i<s.length()-1;i++)
        {
            subs.push_back(s.at(i));
            for(int j=i+1;j<s.length()+1;j++)
            {
                if(j==s.length())
                {
                    length.push_back(subs.size());
                    subs.clear();
                    break;
                }
                if(find(subs.begin(),subs.end(),s.at(j))==subs.end())
                {
                    subs.push_back(s.at(j));
                    continue;
                }
                length.push_back(subs.size());
                subs.clear();
                break;
            }

        }

        vector<int>::iterator final =  max_element(begin(length),end(length));
        int max = *final;
        return max;
    }
};

int main()
{
    string s = "au";
    Solution sl;
    sl.lengthOfLongestSubstring(s);
    return 0;
}