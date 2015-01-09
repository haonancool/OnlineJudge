/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
  ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
    ListNode *p0 = l1, *p1 = l2;
    ListNode *ret = 0, *tail = 0;
    int carry = 0;
    while (p0 || p1 || carry) {
      int sum = carry;
      if (p0) {
        sum += p0->val;
        p0 = p0->next;
      }
      if (p1) {
        sum += p1->val;
        p1 = p1->next;
      }
      carry = sum / 10;
      sum %= 10;
      ListNode *tmp = new ListNode(sum);
      tmp->next = 0;
      if (tail)
        tail->next = tmp;
      if (!ret)
        ret = tmp;
      tail = tmp;
    }
    if (!ret) {
      ret = new ListNode(0);
      ret->next = 0;
    }
    return ret;
  }
};
