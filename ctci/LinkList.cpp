//
// Created by Tushar on 28/12/19.
//

struct SingleNode {
    int data;
    SingleNode *next;
};

SingleNode *singleNodeInsert(SingleNode *head, int newData) {
    SingleNode *tmp = new SingleNode;
    tmp->data = newData;
    tmp->next = NULL;
    if (head == NULL) {
        return tmp;
    } else {
        SingleNode *headPtr = head;
        while (headPtr->next != NULL) {
            headPtr = headPtr->next;
        }
        headPtr->next = tmp;
        return head;
    }
}

SingleNode *singleNodeDelete(SingleNode *head, int value) {
    if (head->data == value) {
        SingleNode *tmp;
        tmp = head->next;
        delete head;
        return tmp;
    } else {
        SingleNode *headPtr = head;
        while (headPtr->next != NULL) {
            if (headPtr->next->data == value) {
                SingleNode *tmp;
                tmp = headPtr->next;
                headPtr->next = headPtr->next->next;
                delete tmp;
                return head;
            }
            headPtr = headPtr->next;
        }
    }
    return head;
}


void singleNodePrintList(SingleNode *head) {
    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

SingleNode *singleNodeRandomLinkList(int size) {
    srand(time(0));
    SingleNode *head = new SingleNode;
    head->data = rand() % 100 + 1;
    head->next = NULL;
    SingleNode *t = head;
    for (int i = 1; i < size; i++) {
        SingleNode *tmp = new SingleNode;
        tmp->data = rand() % 100 + 1;
        tmp->next = NULL;
        t->next = tmp;
        t = t->next;
    }
    cout<<"Random List :"<<endl;
    singleNodePrintList(head);
    return head;
}




