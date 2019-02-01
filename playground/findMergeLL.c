int min(int a, int b) {
    return (a >= b) ? b : a;
}

int findMergeNode(SinglyLinkedListNode* head1, SinglyLinkedListNode* head2) {
    if(!head1) return head2;
    if(!head2) return head1;
    
    SinglyLinkedListNode *start1 = head1, *start2 = head2;
    int cnt_head1 = 0, cnt_head2 = 0;
    
    while(head1) {
        head1 = head1->next;
        cnt_head1++;
    }

    while(head2) {
        head2 = head2->next;
        cnt_head2++;
    }

    cnt_head1 = (cnt_head1 - min(cnt_head1, cnt_head2)) + 1;
    cnt_head2 = (cnt_head2 - min(cnt_head1, cnt_head2)) + 1;
    //printf("\nstart1: %d, start2: %d, cnt1 %d, cnt2 %d", start1->data, start2->data, cnt_head1, cnt_head2);
    while(--cnt_head1 >= 0) start1 = start1->next;
    while(--cnt_head2 >= 0) start2 = start2->next;
    //printf("\nstart1: %d, start2: %d", start1->data, start2->data);
    return start1->data;
}
