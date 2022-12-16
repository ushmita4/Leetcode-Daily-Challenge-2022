class MyQueue {
public:
    
    struct queueType
    {
        int val;
        queueType *next;
    };
    queueType *myQueue = NULL, *head = NULL; 
    void push(int x) {
        if(myQueue == NULL)
        {
            head = new queueType();
            head->val = x;
            head->next = NULL;
            myQueue = head;;
        }
        else
        {
            queueType *pik;
            pik = new queueType();
            pik->val = x;
            pik->next = NULL;
            myQueue->next = pik;
            myQueue = myQueue->next;
        }
    }
    
   
    int pop() {
        queueType *pik = head;
        head = head->next;
        int ret = pik->val;
        delete(pik);
        myQueue = head == NULL ? NULL : myQueue;
        return ret;
    }
    
  
    int peek() { return head->val; }
    
    
    bool empty() { return head == NULL; }
};
