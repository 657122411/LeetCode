//
// Created by 陶剑浩 on 2018/8/2.
//
/*给定一个 32 位有符号整数，将整数中的数字进行反转。

示例 1:
输入: 123
输出: 321
 示例 2:
输入: -123
输出: -321
示例 3:
输入: 120
输出: 21
注意:
假设我们的环境只能存储 32 位有符号整数，其数值范围是 [?231,  231 ? 1]。根据这个假设，如果反转后的整数溢出，则返回 0。*/

#include <iostream>
#include <math.h>
#include <vector>
using namespace std;

class Solution {
public:
    int reverse(int x) {
        int length=0;
        if(x==-pow(2,31))
            return 0;
        int flag;
        if(x<0)
        {
            flag= -1;
            x=-x;
        }
        else
            flag = 1;
        vector<int> temp;

        do{
            temp.push_back(x%10);
            x=x/10;
        }while(x!=0);


        int i=0;
        long int ans=0;

        for(vector<int>::iterator iter=temp.end()-1;iter>=temp.begin();iter--)
        {

            ans=ans+pow(10,i)*(*iter);
            i++;
        }
        if((ans>pow(2,31)-1))
            return 0;
        return flag*(int)ans;

    }
};

int stringToInteger(string input) {
    return stoi(input);
}

int main() {
    string line;
    while (getline(cin, line)) {
        int x = stringToInteger(line);

        int ret = Solution().reverse(x);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}