#include <iostream>
using namespace std;
#include <string.h> 
struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    if (!l1) return l2;
    if (!l2) return l1;
    if (l1->val >= l2->val) {
        l2->next = mergeTwoLists(l1, l2->next);
        return l2;
    }
    if (l1->val < l2->val) {
        l1->next = mergeTwoLists(l1->next, l2);
        return l1;
    }
    return l2;
}

ListNode* createList()
{
    cout << "请输入链表节点并以0作为结尾：" << endl;
    //用到的变量
    ListNode *p_new = NULL;
    ListNode *p_old = NULL;
    int n;
    //建立尾结点
    cin >> n;
    ListNode *head = new ListNode(n);
    head->next = NULL;

    //循环建立后续节点
    p_old = head;
    int cycle = 1;
    while (cycle)
    {
        cin >> n;
        if (n != 0)
        {
            ListNode *p_new = new ListNode(n);
            p_old->next = p_new;
            p_old = p_old->next;
            p_new->next = NULL;
        }
        else
        {
            cycle = 0;
            cout << "Input done! " << endl;
        }
    }
    return head;
}
void print_list( ListNode* L1 ){
    while (L1) {
        cout << L1->val<<"----";
        L1 = L1->next;
    }
    cout << endl;
}
void main() {
    ListNode* L1 = createList();
    ListNode* L2 = createList();
    ListNode* L3 = mergeTwoLists(L1, L2);
    print_list(L3);
    system("pause");
}