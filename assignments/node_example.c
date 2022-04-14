typedef struct node node_t;           // typedef so node_t can be used in definition

struct node {
    int data;
    node_t *next;                    // ptr to next node on the list
}

// scanning the list
// [5| ]-->[2| ]-->[7| ]-->NULL
node_t *search(node_t *node, int value) {
    // if we dereference a null pointer, code will break
    while (node != NULL) {
        if (node->data == value) {
            return node;             // if found, return pointer to element
        }
        node = node->next;
    }
    return NULL;                     // not found
}

// add node to front of list
// initial [2| ]-->[5| ]-->NULL
void add(int data, node_t *head) {
    node_t *newNode = (node_t *) malloc(sizeof(node_t));
    newNode->data = data;

    if (head == NULL) {
        head = newNode;
    }
    else {
        newNode->next = head;
        head = newNode;
    }
}
