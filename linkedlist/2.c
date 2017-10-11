struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    if(l1==NULL) return l2;
    if(l2==NULL) return l1;
    int temp = 0;
    int total = 0;    

    struct ListNode *h1 = l1;
    struct ListNode *h2 = l2;
    struct ListNode *t1 = NULL;
    struct ListNode *t2 = NULL;
    while(l1 && l2)
    {
        total = l1->val + l2->val + temp;
        if(total <= 9)
        {
            l1->val = total;
            l2->val = total;
            t1 = l1;
            t2 = l2;
            l1 = l1->next;
            l2 = l2->next;
            temp = 0;
        }
        else
        {
            l1->val = total - 10;
            l2->val = total - 10;
            t1 = l1;
            t2 = l2;
            l1 = l1->next;
            l2 = l2->next;
            temp = 1;
        }
    }
    if(l1)
    {
        while(temp)
        {
            total = temp + l1->val;
            if(total <= 9)
            {
                l1->val = total;
                return h1;
            }
            else
            {
                if(l1->next){
                    temp = 1;
                    l1->val = total - 10;
                    l1 = l1->next;
                    continue;
                }
                else{
                    struct ListNode* new = (struct ListNode *)malloc(sizeof(struct ListNode));
                    l1->val = total - 10;
                    new->val = 1;
                    new->next = NULL;
                    l1->next = new;
                    temp = 0;
                }
            }
        }
        return h1;   
    }
    else if(l2)
    {
        while(temp)
        {
            total = temp + l2->val;
            if(total <= 9)
            {
                l2->val = total;
                return h2;
            }
            else
            {
                if(l2->next){
                    temp = 1;
                    l2->val = total - 10;
                    l2 = l2->next;
                    continue;
                }
                else{
                    struct ListNode* new = (struct ListNode *)malloc(sizeof(struct ListNode));
                    l2->val = total - 10;
                    new->val = 1;
                    new->next = NULL;
                    l2->next = new;
                    temp = 0;
                }
            }
        }
        return h2;   
    }
    else
    {
        if(temp)
        {
            struct ListNode* new = (struct ListNode *)malloc(sizeof(struct ListNode));
            new->val = 1;
            new->next = NULL;
            t1->next = new;
        }
        return h1;
    }

}
