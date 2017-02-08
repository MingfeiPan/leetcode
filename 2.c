/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    int len1 = length(l1);
    int len2 = length(l2);
    int len = len1 >= len2 ? len1 : len2;
    struct ListNode* head;
    struct ListNode* l3 = (struct ListNode*)malloc(sizeof(struct ListNode));
    head = l3;
    int flag = 0;
    while(l1 && l2){
        if ((l1->val+l2->val+flag) <=9){
            l3->val = l1->val+l2->val+flag;
            flag=0;
        }
        else if((l1->val+l2->val+flag) >= 10) {
            l3->val = l1->val+l2->val+flag - 10;
            printf("%d\n", l3->val);
            flag = 1;
        }else{
            l3->val = l1->val+l2->val+flag;
            flag = 0;
        }
        l1=l1->next;
        l2=l2->next;
        if(!l1 && !l2){
            break;
        }          
        struct ListNode* lnext = (struct ListNode*)malloc(sizeof(struct ListNode));
        l3->next=lnext;
        l3 = l3->next;
      
    }
    
    struct ListNode* lleft = l1 ? l1 : l2;

    while(lleft){
        if((lleft->val+flag) <=9){
            l3->val = lleft->val+flag;
            flag = 0;
        }
        else if ((lleft->val+flag) == 10){
            l3->val = 0;
            flag = 1;
        }else{
            l3->val = lleft->val;
        }
        lleft=lleft->next;
        if(!lleft){
            break;
        }          
        struct ListNode* lnext = (struct ListNode*)malloc(sizeof(struct ListNode));
        l3->next=lnext;
        l3 = l3->next;    
    }
    
    if(flag == 1){
        struct ListNode* lnext = (struct ListNode*)malloc(sizeof(struct ListNode));
        l3->next=lnext;
        l3 = l3->next;        
        l3->val = 1;
    }
    l3->next = NULL;
    return head;
}

int length(struct ListNode* l){
    int count;
    while(l){
        count++;
        l = l->next;
    }
    return count;
}

/**
 *better one
 */
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode* head;
    struct ListNode* curr = (struct ListNode*)malloc(sizeof(struct ListNode));
    head = curr;
    int flag = 0;
    while(l1 || l2){
        int x = l1 ? l1->val : 0;
        int y = l2 ? l2->val : 0;
        int sum = x + y + flag;
        flag = sum / 10;
        curr->next = (struct ListNode*)malloc(sizeof(struct ListNode));
        curr->next->val = sum % 10;
        curr = curr->next;
        curr->next = NULL;
        if(l1) l1=l1->next;
        if(l2) l2=l2->next;
    }
    if(flag > 0){
        curr->next = (struct ListNode*)malloc(sizeof(struct ListNode));
        curr->next->val = flag % 10;
        curr->next->next = NULL;
    }
    return head->next;
}

