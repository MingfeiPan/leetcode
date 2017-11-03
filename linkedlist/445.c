/**
 * 需要用到栈
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
typedef struct Node{
    int val;
    struct Node *next;
}Node;

typedef struct Stack{
    Node *top;
    Node *bottom;
}Stack;

void init(Stack *s);
void push(Stack *s, int i);
int pop(Stack *s);
bool isEmpty(Stack *s);

void init(Stack *s)
{
    s->top = (Node*)malloc(sizeof(Node));
    if(!s->top) exit(-1);
    s->bottom =s->top;
    s->top->next = NULL;
    return;
}

void push(Stack *s, int i)
{
    Node *p = (Node*)malloc(sizeof(Node));
    p->val = i;
    p->next = s->top;
    s->top = p;
    return;
}

int pop(Stack *s)
{   
    if(isEmpty(s)) return;
    Node * p = s->top;
    s->top = p->next;
    int i = p->val;
    free(p);
    return i;
}

bool isEmpty(Stack *s)
{
    return s->top == s->bottom;
    
}
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    Stack s1,s2;
    init(&s1);
    init(&s2);
    while(l1)
    {
        push(&s1, l1->val);
        l1 = l1->next;
    }
    while(l2)
    {
        push(&s2, l2->val);
        l2 = l2->next;
    }
    
    int sum = 0;
    struct ListNode *head = (struct ListNode*)malloc(sizeof(struct ListNode));
    while(!isEmpty(&s1) || !isEmpty(&s2))
    {
        if(!isEmpty(&s1)) sum += pop(&s1);
        if(!isEmpty(&s2)) sum += pop(&s2);
        head->val = sum % 10;
        struct ListNode *cur = (struct ListNode*)malloc(sizeof(struct ListNode));
        cur->val = sum / 10;
        cur->next = head;
        head = cur;
        sum /= 10;
    }
    return head->val == 0 ? head->next : head;
    
}
