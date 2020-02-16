//
// Created by Tushar on 04/01/20.
//


int testFac(int n) {
    if (n == 0 || n == 1) {
        return 1;
    }
    int result = n * testFac(n - 1);
    return result;
}

void isPalindrome(int n) {
    int newN = 0, tmp = n;
    while (tmp > 0) {
        int t = tmp % 10;
        newN = newN * 10 + t;
        tmp = tmp / 10;
    }
    if (n == newN) {
        cout << "Palin";
    } else {
        cout << "Not Palin";
    }
}


int isPalindrome2(int n, int nn) {
    if (n > 0 && n < 10) {
        return nn * 10 + n;
    }
    nn = (nn * 10) + (n % 10);
    return isPalindrome2(n / 10, nn);
}

void deleteMiddleElementFromLinkList(){
    SingleNode *head = singleNodeRandomLinkList(9);
    SingleNode *s1=head, *s2=head, *prev;
    while(s2->next!=NULL && s2->next->next!=NULL){
        s2=s2->next->next;
        prev=s1;
        s1=s1->next;
    }
    SingleNode *tmp=prev->next;
    prev->next=prev->next->next;
    delete tmp;
    singleNodePrintList(head);
}