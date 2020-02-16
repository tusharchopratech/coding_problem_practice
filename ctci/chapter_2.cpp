//
// Created by Tushar on 28/12/19.
//

#include "LinkList.cpp"

void TestSingleLinkList() {
    SingleNode *head;
    head = singleNodeInsert(head, 1);
    head = singleNodeInsert(head, 2);
    head = singleNodeInsert(head, 3);
    head = singleNodeInsert(head, 1);
    head = singleNodeInsert(head, 2);
    head = singleNodeInsert(head, 4);
    singleNodePrintList(head);
    head = singleNodeDelete(head, 1);
    singleNodePrintList(head);
}

void P1S1() {
    SingleNode *head, *headPtr;
    head = singleNodeInsert(head, 1);
    head = singleNodeInsert(head, 2);
    head = singleNodeInsert(head, 3);
    head = singleNodeInsert(head, 1);
    head = singleNodeInsert(head, 2);
    head = singleNodeInsert(head, 4);
    singleNodePrintList(head);
    headPtr = head;

    vector<int> v;
    v.push_back(headPtr->data);
    while (headPtr->next != NULL) {
        if (find(v.begin(), v.end(), headPtr->next->data) == v.end()) {
            //First Time added
            v.push_back(headPtr->next->data);
            headPtr = headPtr->next;
        } else {
            //Next Time delete
            SingleNode *tmp = headPtr->next;
            headPtr->next = headPtr->next->next;
            delete tmp;
        }
    }
    singleNodePrintList(head);
}


void P1S2() {
    SingleNode *head, *headPtr;
    head = NULL;
    head = singleNodeInsert(head, 1);
    head = singleNodeInsert(head, 2);
    head = singleNodeInsert(head, 3);
    head = singleNodeInsert(head, 1);
    head = singleNodeInsert(head, 2);
    head = singleNodeInsert(head, 4);
    singleNodePrintList(head);
    headPtr = head;

    while (headPtr != NULL) {
        int element = headPtr->data;
        SingleNode *runner = headPtr;
        while (runner->next != NULL) {
            if (runner->next->data == element) {
                //Delete Now
                SingleNode *tmp = runner->next;
                runner->next = runner->next->next;
                delete tmp;
            } else {
                runner = runner->next;
            }
        }
        headPtr = headPtr->next;
    }
    singleNodePrintList(head);
}


int depthOfLinklist(SingleNode *head, int kth) {
    if (head == NULL) {
        return 0;
    }
    int reverseSize = depthOfLinklist(head->next, kth) + 1;
    if (reverseSize == kth) {
        cout << head->data << endl;
    }
    return reverseSize;
}

void P2S1() {
    SingleNode *head = singleNodeRandomLinkList(10);
    cout << depthOfLinklist(head, 3);
}

void P2S2() {
    SingleNode *head = singleNodeRandomLinkList(10);
    int k = 3;
    SingleNode *h1, *h2;
    h1 = head;
    h2 = head;
    for (int i = 0; i < k - 1; i++) {
        h2 = h2->next;
    }
    while (h2->next != NULL) {
        h1 = h1->next;
        h2 = h2->next;
    }
    cout << h1->data;
}

void P3S1() {
    SingleNode *head = singleNodeRandomLinkList(10);
    int k = 5;
    SingleNode *node = head;
    for (int i = 0; i < k - 1; i++) {
        node = node->next;
    }
    cout << k << "th element is " << node->data << endl;
    while (node->next->next != NULL) {
        node->data = node->next->data;
        node = node->next;
    }
    SingleNode *tmp = node->next;
    node->data = node->next->data;
    node->next = NULL;
    delete tmp;
    singleNodePrintList(head);
}

void P4S1() {
    SingleNode *head = singleNodeRandomLinkList(10);
    SingleNode *headItr = head, *valNode = head, *valNodeItr, *tt;
    int k = 5;
    for (int i = 0; i < k - 1; i++) {
        valNode = valNode->next;
    }
    cout << valNode->data << endl;

    // From valNode to End
    valNodeItr = valNode;
    while (valNodeItr->next != NULL) {
        if (valNodeItr->next->data < valNode->data) {
            // Detach node and add to head.
            SingleNode *tmp = valNodeItr->next;
            valNodeItr->next = valNodeItr->next->next;
            tmp->next = head;
            head = tmp;
        } else {
            valNodeItr = valNodeItr->next;
        }
    }
    singleNodePrintList(head);

    headItr = head;
    while (headItr->next->data != valNode->data) {
        if (headItr->next->data >= valNode->data) {
            SingleNode *tmp = headItr->next;
            headItr->next = headItr->next->next;
            tmp->next = NULL;

            while (valNodeItr->next != NULL) {
                valNodeItr = valNodeItr->next;
            }
            valNodeItr->next = tmp;

        } else {
            headItr = headItr->next;
        }
    }

    singleNodePrintList(head);

}

void P5S1() {
    SingleNode *no1 = NULL, *no2 = NULL, *sum = NULL;

    no1 = singleNodeInsert(no1, 7);
    no1 = singleNodeInsert(no1, 1);
    no1 = singleNodeInsert(no1, 6);
    singleNodePrintList(no1);

    no2 = singleNodeInsert(no2, 5);
    no2 = singleNodeInsert(no2, 9);
    no2 = singleNodeInsert(no2, 2);
    singleNodePrintList(no2);

    int carryOver = 0;
    while (no1 != NULL) {
        int tmp = no1->data + no2->data + carryOver;
        if (no1->next != NULL) {
            if (tmp >= 10) {
                carryOver = tmp / 10;
                tmp = tmp % 10;
            }
        }
        sum = singleNodeInsert(sum, tmp);
        no1 = no1->next;
        no2 = no2->next;
    }
    singleNodePrintList(sum);
}

void P5S2() {
    SingleNode *no1 = NULL, *no2 = NULL, *sum = NULL;
    no1 = singleNodeInsert(no1, 6);
    no1 = singleNodeInsert(no1, 1);
    no1 = singleNodeInsert(no1, 7);
    singleNodePrintList(no1);

    no2 = singleNodeInsert(no2, 2);
    no2 = singleNodeInsert(no2, 9);
    no2 = singleNodeInsert(no2, 5);
    singleNodePrintList(no2);

    int n1 = 0, n2 = 0, s = 0;
    while (no1 != NULL) {
        n1 = n1 * 10 + no1->data;
        n2 = n2 * 10 + no2->data;
        no1 = no1->next;
        no2 = no2->next;
    }
    s = n1 + n2;
    while (s > 0) {
        if (sum == NULL) {
            sum = new SingleNode;
            sum->data = s % 10;
            sum->next = NULL;
        } else {
            SingleNode *tmp = new SingleNode;
            tmp->data = s % 10;
            tmp->next = sum;
            sum = tmp;
        }
        s = s / 10;
    }
    singleNodePrintList(sum);
}

void chapter2_run() {
//    P1S1();
//    P1S2();
//    P2S1();
//    P2S2();
//    P3S1();
//    P4S1();
//    P5S1();
    P5S2();
}
