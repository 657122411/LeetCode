//
// Created by 陶剑浩 on 2018/7/30.
//

/*
给定一个字符串，找出不含有重复字符的最长子串的长度。

示例：
给定 "abcabcbb" ，没有重复字符的最长子串是 "abc" ，那么长度就是3。
给定 "bbbbb" ，最长的子串就是 "b" ，长度是1。
给定 "pwwkew" ，最长子串是 "wke" ，长度是3。请注意答案必须是一个子串，"pwke" 是 子序列  而不是子串。
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