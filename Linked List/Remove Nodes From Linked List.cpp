/*     Scroll below to see JAVA code also    */
/*
    MY YOUTUBE VIDEO ON THIS Qn : 
    Company Tags                : will soon update
    Leetcode Link               : https://leetcode.com/problems/remove-nodes-from-linked-list/
*/

/*************************************************************** C++ ***************************************************************/
//Approach-1 (Using stack)
//T.C  : O(n)
//S.C  : O(n)
class Solution {
public:
    ListNode* removeNodes(ListNode* head) {
        stack<ListNode*> st;
        ListNode* current = head;

        while (current != nullptr) {
            st.push(current);
            current = current->next;
        }

        current = st.top();
        st.pop();
        int maximum = current->val;
        ListNode* resultHead = new ListNode(maximum);

        while (!st.empty()) {
            current = st.top();
            st.pop();
            if (current->val < maximum) {
                continue;
            }
            else {
                ListNode* newNode = new ListNode(current->val);
                newNode->next = resultHead;
                resultHead = newNode;
                maximum = current->val;
            }
        }

        return resultHead;
    }
};



//Approach-2 (Using Recursion - instead of stack, use system's stack)
//T.C : O(n)
//S.C : O(n) system stack
class Solution {
public:
    ListNode* removeNodes(ListNode* head) {
        if (head == NULL || head->next == NULL) {
            return head;
        }

        ListNode* nextNode = removeNodes(head->next);

        if (head->val < nextNode->val) {
            delete head;
            return nextNode;
        }

        head->next = nextNode;
        return head;
    }
};


//Approach-3 (Using reverse)
//T.C : O(n)
//S.C : O(1)
class Solution {
private:
    ListNode* reverseList(ListNode* head) {
        if(head == NULL || head->next == NULL) {
            return head;
        }
        
        ListNode* last = reverseList(head->next);
        head->next->next = head;
        head->next = NULL;
        
        return last;
    }
public:
    ListNode* removeNodes(ListNode* head) {
        head = reverseList(head);

        int maximum = 0;
        ListNode* prev = NULL;
        ListNode* current = head;

        while (current != NULL) {
            maximum = max(maximum, current->val);

            if (current->val < maximum) {
                prev->next = current->next;
                ListNode* deleted = current;
                current = current->next;
                delete(deleted);
            }

            else {
                prev = current;
                current = current->next;
            }
        }
        
        return reverseList(head);
    }
};




/*************************************************************** JAVA ***************************************************************/
//Approach-1 (Using stack)
//T.C  : O(n)
//S.C  : O(n)
class Solution {
    public ListNode removeNodes(ListNode head) {
        Stack<ListNode> st = new Stack<>();
        ListNode current = head;

        while (current != null) {
            st.push(current);
            current = current.next;
        }

        current = st.pop();
        int maximum = current.val;
        ListNode resultHead = new ListNode(maximum);

        while (!st.empty()) {
            current = st.pop();
            if (current.val < maximum) {
                continue;
            }
            else {
                ListNode newNode = new ListNode(current.val);
                newNode.next = resultHead;
                resultHead = newNode;
                maximum = current.val;
            }
        }

        return resultHead;
    }
}


//Approach-2 (Using Recursion - instead of stack, use system's stack)
//T.C : O(n)
//S.C : O(n) system stack
class Solution {
    public ListNode removeNodes(ListNode head) {
        if (head == null || head.next == null) {
            return head;
        }

        ListNode nextNode = removeNodes(head.next);

        if (head.val < nextNode.val) {
            head = null;
            return nextNode;
        }

        head.next = nextNode;
        return head;
    }
}


//Approach-3 (Using reverse)
//T.C : O(n)
//S.C : O(1)
class Solution {
    private ListNode reverseList(ListNode head) {
        if(head == null || head.next == null) {
            return head;
        }
        
        ListNode last = reverseList(head.next);
        head.next.next = head;
        head.next = null;
        
        return last;
    }
    
    public ListNode removeNodes(ListNode head) {
        head = reverseList(head);

        int maximum = 0;
        ListNode prev = null;
        ListNode current = head;

        while (current != null) {
            maximum = Math.max(maximum, current.val);

            if (current.val < maximum) {
                prev.next = current.next;
                ListNode deleted = current;
                current = current.next;
                deleted.next = null;
            }

            else {
                prev = current;
                current = current.next;
            }
        }
        
        return reverseList(head);
    }
}
