class Node {
 public:
  int data;
  Node *next;

  Node(int d) {
    data = d;
    next = nullptr;
  }
};

int sizell(Node *head) {
  int size = 0;
  while (head) {
    head = head->next;
    size++;
  }
  return size;
}

void insertAtHead(Node *&head, int d) {
  if (!head) {
    head = new Node(d);
    return;
  }

  Node *n = new Node(d);
  n->next = head;
  head = n;
}

void insertAtTail(Node *&head, int d) {
  if (!head) {
    insertAtHead(head, d);
    return;
  }

  Node *temp = head;
  while (temp->next != nullptr) {
    temp = temp->next;
  }
  Node *n = new Node(d);
  temp->next = n;
}

void insertAtMiddle(Node *&head, int d, int pos) {
  if (!head || pos == 1) {
    insertAtHead(head, d);
    return;
  }

  int jump = 1;
  Node *temp = head;
  while (jump < pos - 1) {
    temp = temp->next;
    jump++;
  }

  Node *n = new Node(d);
  n->next = temp->next;
  temp->next = n;
}

void deleteAtHead(Node *&head) {
  if (!head) return;
  Node *temp = head;
  head = head->next;
  delete temp;
}

void deleteAtTail(Node *&head) {
  if (head->next == nullptr) {
    deleteAtHead(head);
    return;
  }
  Node *temp = head;
  while (temp->next->next != nullptr) temp = temp->next;

  delete temp->next;
  temp->next = nullptr;
}

void deleteAtMiddle(Node *&head, int pos) {
  int jump = 1;
  Node *temp = head;
  while (jump < pos - 1) {
    temp = temp->next;
    jump++;
  }
  Node *n;
  n = temp->next;
  temp->next = temp->next->next;
  delete n;
}

void printll(Node *head) {
  while (head) {
    std::cout << head->data << " -> ";
    head = head->next;
  }
  std::cout<<'\n';
}

Node* buildll(){
  Node *head = nullptr;
  insertAtHead(head, 1);
  insertAtHead(head, 2);
  insertAtHead(head, 3);
  insertAtHead(head, 4);
  insertAtHead(head, 5);
  insertAtHead(head, 6);
  return head;
}
