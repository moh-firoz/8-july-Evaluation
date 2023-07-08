#include <iostream>
#include <vector>

using namespace std;

class ListNode {
public:
    int val;
    ListNode* next;
    
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty())
            return nullptr;
        
        int n = lists.size();
        while (n > 1) {
            int k = (n + 1) / 2;
            
            for (int i = 0; i < n / 2; ++i) {
                lists[i] = mergeTwoLists(lists[i], lists[i + k]);
            }
            
            n = k;
        }
        
        return lists[0];
    }
    
private:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (!l1)
            return l2;
        if (!l2)
            return l1;
        
        ListNode* mergedHead = nullptr;
        
        if (l1->val <= l2->val) {
            mergedHead = l1;
            l1 = l1->next;
        } else {
            mergedHead = l2;
            l2 = l2->next;
        }
        
        ListNode* curr = mergedHead;
        
        while (l1 && l2) {
            if (l1->val <= l2->val) {
                curr->next = l1;
                l1 = l1->next;
            } else {
                curr->next = l2;
                l2 = l2->next;
            }
            curr = curr->next;
        }
        
        if (l1)
            curr->next = l1;
        if (l2)
            curr->next = l2;
        
        return mergedHead;
    }
};

void printList(ListNode* head) {
    while (head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    Solution solution;
    
    int k;
    cout << "Enter the number of linked lists: ";
    cin >> k;
    
    vector<ListNode*> lists(k);
    for (int i = 0; i < k; ++i) {
        int n;
        cout << "Enter the number of elements in linked list " << (i + 1) << ": ";
        cin >> n;
        
        ListNode* head = nullptr;
        ListNode* curr = nullptr;
        for (int j = 0; j < n; ++j) {
            int val;
            cout << "Enter the value of node " << (j + 1) << ": ";
            cin >> val;
            
            ListNode* node = new ListNode(val);
            if (!head) {
                head = node;
                curr = node;
            } else {
                curr->next = node;
                curr = curr->next;
            }
        }
        
        lists[i] = head;
    }
    
    ListNode* merged = solution.mergeKLists(lists);
    cout << "Merged List: ";
    printList(merged);
    
    return 0;
}
