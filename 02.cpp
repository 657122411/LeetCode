//
// Created by �ս��� on 2018/7/28.
//

/**
���������ǿ���������ʾ�����Ǹ�������λ����������ʽ�洢�����ǵ�ÿ���ڵ�ֻ�洢�������֡���������ӷ���һ���µ�����

����Լ���������� 0 ֮�⣬���������ֶ��������㿪ͷ��

ʾ����

���룺(2 -> 4 -> 3) + (5 -> 6 -> 4)
�����7 -> 0 -> 8
ԭ��342 + 465 = 807
 */

#include <iostream>
using namespace std;
struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
    {
        if(l1==NULL)
            return l2;
        if(l2==NULL)
            return l1;
        int Num=(l1->val+l2->val)%10;
        int count = (l1->val+l2->val)/10;
        ListNode *head = new ListNode(Num);
        ListNode *p = head;
        l1=l1->next;
        l2=l2->next;
        while(true)
        {
            if(l1!=NULL&&l2!=NULL)
            {
                p->next=new ListNode((l1->val+l2->val+count)%10);
                count=(l1->val+l2->val+count)/10;
                l1=l1->next;
                l2=l2->next;
                p=p->next;
            }
            if(l1!=NULL&&l2==NULL)
            {
                p->next=new ListNode((l1->val+count)%10);
                count = (l1->val+count)/10;
                l1=l1->next;
                p=p->next;
            }
            if(l1==NULL&&l2!=NULL)
            {
                p->next=new ListNode((l2->val+count)%10);
                count = (l2->val+count)/10;
                l2=l2->next;
                p=p->next;
            }
            if(l1==NULL&&l2==NULL)
            {
                if(count!=0)
                {
                    p->next = new ListNode(count);
                    count=0;
                    p=p->next;
                }
                break;
            }

        }
        p->next = NULL;
        return head;
    }
};

int main()
{
    ListNode *l1= new ListNode(3);
    ListNode *ll1=l1;
    l1->next = new ListNode(7);
    ListNode *l2= new ListNode(9);
    ListNode *ll2=l2;
    l2->next=new ListNode(2);
    Solution ls;
    ls.addTwoNumbers(ll1,ll2);

    return  0;
}