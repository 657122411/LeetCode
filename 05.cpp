//
// Created by �ս��� on 2018/7/31.
//
/*
����һ���ַ��� s���ҵ� s ����Ļ����Ӵ�������Լ��� s ����󳤶�Ϊ1000��
ʾ�� 1��
����: "babad"
���: "bab"
ע��: "aba"Ҳ��һ����Ч�𰸡�
ʾ�� 2��
����: "cbbd"
���: "bb"*/
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    string longestPalindrome(string s) {
        if (s.empty()) return "";
        int len = s.size();
        if (len == 1)return s;
        int longest = 1;
        int start = 0;
        vector<vector<int> > dp(len, vector<int>(len));
        for (int i = 0; i < len; i++) {
            dp[i][i] = 1;
            if (i < len - 1) {
                if (s[i] == s[i + 1]) {
                    dp[i][i + 1] = 1;
                    start = i;
                    longest = 2;
                }
            }
        }
        for (int l = 3; l <= len; l++)//�Ӵ�����
        {
            for (int i = 0; i + l - 1 < len; i++)//ö���Ӵ�����ʼ��
            {
                int j = l + i - 1;//�յ�
                if (s[i] == s[j] && dp[i + 1][j - 1] == 1) {
                    dp[i][j] = 1;
                    start = i;
                    longest = l;
                }
            }
        }
        return s.substr(start, longest);
    }
};

string stringToString(string input) {
    assert(input.length() >= 2);
    string result;
    for (int i = 1; i < input.length() - 1; i++) {
        char currentChar = input[i];
        if (input[i] == '\\') {
            char nextChar = input[i + 1];
            switch (nextChar) {
                case '\"':
                    result.push_back('\"');
                    break;
                case '/' :
                    result.push_back('/');
                    break;
                case '\\':
                    result.push_back('\\');
                    break;
                case 'b' :
                    result.push_back('\b');
                    break;
                case 'f' :
                    result.push_back('\f');
                    break;
                case 'r' :
                    result.push_back('\r');
                    break;
                case 'n' :
                    result.push_back('\n');
                    break;
                case 't' :
                    result.push_back('\t');
                    break;
                default:
                    break;
            }
            i++;
        } else {
            result.push_back(currentChar);
        }
    }
    return result;
}


int main() {
    string line;
    while (getline(cin, line)) {
        string s = stringToString(line);

        string ret = Solution().longestPalindrome(s);

        string out = (ret);
        cout << out << endl;
    }
    return 0;
}