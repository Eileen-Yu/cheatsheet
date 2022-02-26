// any internal node can be removed from the linked list
#include <iostream>
using namespace std;

class Node{
  private:
    double val;
    Node* next;

  public:
    Node();
    ~Node();
    Node* putNode(Node* head, double val);
    Node* findNode(Node* head, double val);
    Node* deleteNode(Node* head, double val);
    void getList(Node* head);
};

Node::Node(){};
Node::~Node(){};

Node* Node::putNode(Node* head, double val){
  Node* temp = nullptr;
  temp = new Node;
  if(temp){
    temp->next = head;
    temp->val = val;
  }
  return temp;  // temp is the new head
}

Node* Node::findNode(Node* head, double val ){
  Node* temp = head;
  while(temp != nullptr && temp->val != val){
    temp = temp->next;
  }
  return temp;
}

Node* Node::deleteNode(Node* head, double val){
  Node* deleteNode = findNode(head, val);
  if(deleteNode == nullptr) {
    cout<<"No such node."<<endl;
  }
  
  if(deleteNode == head){
    head = head->next;    
  }

  else {
    //if node is "in" the list
    Node* prev;
    Node* temp = head; // 遍历查找，才能确定pre指针
    for(prev = nullptr; temp != deleteNode; prev = temp, temp = temp->next);
    prev->next = deleteNode->next; // 跳过删除的，指向后一个
  }

  delete deleteNode;
  deleteNode = nullptr;
  cout<<"Node "<< val<< "is deleted."<<endl;
  
  return head;
}

void Node::getList(Node* head){
  Node* temp = head;
  while (temp != nullptr) {
    cout<<temp->val<<" ";
    temp = temp->next;  
  }
}
