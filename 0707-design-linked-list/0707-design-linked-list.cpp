class Node{
public:
    int data;
    Node* next;

    Node(int val){
        data = val;
        next = NULL;
    }
};

class MyLinkedList {
public:

    Node* head;

    MyLinkedList() {
        head = NULL;
    }
    
    int get(int index) {
        Node* temp = head;

    for(int i = 0; i < index; i++) {

        if(temp == NULL)
            return -1;

        temp = temp->next;
    }

    if(temp == NULL)
        return -1;

    return temp->data;
    }
    
    void addAtHead(int val) {
          Node* newNode = new Node(val);

    newNode->next = head;

    head = newNode;
    }
    
    void addAtTail(int val) {
         // Create new node
    Node* newNode = new Node(val);

    // If list is empty
    if(head == NULL){
        head = newNode;
        return;
    }

    // Start from first node
    Node* temp = head;

    // Go to last node
    while(temp->next != NULL){
        temp = temp->next;
    }

    // Connect last node to new node
    temp->next = newNode;
    }
    
    void addAtIndex(int index, int val) {
        
    Node* newNode = new Node(val);

    // Insert at beginning
    if(index == 0){
        newNode->next = head;
        head = newNode;
        return;
    }

    Node* temp = head;

    // Go to node before index
    for(int i = 0; i < index - 1; i++){

        if(temp == NULL)
            return;

        temp = temp->next;
    }

    if(temp == NULL)
        return;

    newNode->next = temp->next;
    temp->next = newNode;
    }
    
    void deleteAtIndex(int index) {
        // Delete first node
    if(index == 0) {

        if(head == NULL)
            return;

        head = head->next;
        return;
    }

    Node* temp = head;

    // Go to node before target
    for(int i = 0; i < index - 1; i++) {

        if(temp == NULL)
            return;

        temp = temp->next;
    }

    // Invalid index
    if(temp == NULL || temp->next == NULL)
        return;

    // Skip the node
    temp->next = temp->next->next;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */