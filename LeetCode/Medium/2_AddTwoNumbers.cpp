struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        ListNode* ptr1 = l1, *ptr2 = l2;
        int up = 0;
        
        ListNode* result = new ListNode();
        ListNode* resultPtr = result;
        
        while(ptr1 != nullptr || ptr2 != nullptr) {
            int val1 = ptr1 != nullptr ? ptr1->val : 0;
            int val2 = ptr2 != nullptr ? ptr2->val : 0;
            
            int sum = val1 + val2 + up;
            up = sum / 10;
            
            resultPtr->next = new ListNode(sum % 10);
            resultPtr = resultPtr->next;
            
            if(ptr1 != nullptr) ptr1 = ptr1->next;
            if(ptr2 != nullptr) ptr2 = ptr2->next;
        }
        
        if(up != 0)
            resultPtr->next = new ListNode(up);
        
        return result->next;
    }
};