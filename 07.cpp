//
// Created by �ս��� on 2018/8/2.
//
/*����һ�� 32 λ�з����������������е����ֽ��з�ת��

ʾ�� 1:
����: 123
���: 321
 ʾ�� 2:
����: -123
���: -321
ʾ�� 3:
����: 120
���: 21
ע��:
�������ǵĻ���ֻ�ܴ洢 32 λ�з�������������ֵ��Χ�� [?231,  231 ? 1]������������裬�����ת�������������򷵻� 0��*/

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