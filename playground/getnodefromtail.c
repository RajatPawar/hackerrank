int getNode(SinglyLinkedListNode* head, int positionFromTail) {
    SinglyLinkedListNode *ahead_head_itr = head;
    while(positionFromTail-- >= 0 && ahead_head_itr) 
        ahead_head_itr = ahead_head_itr->next;
    while(ahead_head_itr && head) {
        head = head->next;
        ahead_head_itr = ahead_head_itr->next;
    }
    return head->data;
}
