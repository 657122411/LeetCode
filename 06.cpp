//
// Created by 陶剑浩 on 2018/8/1.
//
/*将字符串 "PAYPALISHIRING" 以Z字形排列成给定的行数：

P   A   H   N
A P L S I I G
Y   I   R
之后从左往右，逐行读取字符："PAHNAPLSIIGYIR"

实现一个将字符串进行指定行数变换的函数:

string convert(string s, int numRows);
示例 1:

输入: s = "PAYPALISHIRING", numRows = 3
输出: "PAHNAPLSIIGYIR"
示例 2:

输入: s = "PAYPALISHIRING", numRows = 4
输出: "PINALSIGYAHRPI"
解释:

P     I    N
A   L S  I G
Y A   H R
P     I*/
#include <iostream>
#include <math.h>
#include <vector>
using namespace std;

class Solution {
public:
    string convert(string s, int numRows)
    {
        if(s==" "||s.empty())
        {
            return "";
        }
        if(numRows ==1)
        {
            return s;
        }
        int length = s.length();
        int group = ceil((double)length/(2*numRows-2));
        int numColumns = group*(numRows-1);
        vector<vector<char> > a(numRows,vector<char>(0));
        for(int i = 0;i<length;i++)
        {
            int index = i%(2*numRows-2);
            if(index>(numRows-1))
            {
                index = index-2*(index-(numRows-1));
            }
            a[index].push_back(s[i]);
        }

        string ans = "";

        for(int i =0;i<numRows;i++)
        {
            for(vector<char>::iterator iter = a[i].begin();iter!=a[i].end();iter++)
            {
                ans=ans+*iter;
            }
        }

        return ans;
    }
};

string stringToString(string input) {
    assert(input.length() >= 2);
    string result;
    for (int i = 1; i < input.length() -1; i++) {
        char currentChar = input[i];
        if (input[i] == '\\') {
            char nextChar = input[i+1];
            switch (nextChar) {
                case '\"': result.push_back('\"'); break;
                case '/' : result.push_back('/'); break;
                case '\\': result.push_back('\\'); break;
                case 'b' : result.push_back('\b'); break;
                case 'f' : result.push_back('\f'); break;
                case 'r' : result.push_back('\r'); break;
                case 'n' : result.push_back('\n'); break;
                case 't' : result.push_back('\t'); break;
                default: break;
            }
            i++;
        } else {
            result.push_back(currentChar);
        }
    }
    return result;
}

int stringToInteger(string input) {
    return stoi(input);
}

int main() {
    string line;
    while (getline(cin, line)) {
        string s = stringToString(line);
        getline(cin, line);
        int numRows = stringToInteger(line);

        string ret = Solution().convert(s, numRows);

        string out = (ret);
        cout << out << endl;
    }
    return 0;
}