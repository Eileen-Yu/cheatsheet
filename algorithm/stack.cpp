#include <iostream>
#include <string>

using namespace std;

class Stack{
  private:
    Stack* next;
    string value;

  public:
    Stack();
    ~Stack();
    Stack* push(Stack* node, string val);
    Stack* pop(Stack* node);
    string peek(Stack* node);
    void dispaly(Stack* node);
};

Stack::Stack(){};
Stack::~Stack(){};

Stack* Stack::push(Stack* node, string val){
  Stack* temp = new Stack;
  if(temp != nullptr) {
      temp->value == val;
      temp->next == node;
  }
  return temp;
}


Stack* Stack::pop(Stack* node){
  Stack* temp = node;
  if(node != nullptr) {
    temp = node->next;
    delete node;
  }
  return temp;
}


string Stack::peek(Stack* node){
  string myValue = "No data";    // 预定义node为空的情况
  if (node != nullptr){
    myValue = node->value;
  }
  return myValue;
}


void Stack::dispaly(Stack* node){
  if (node == nullptr) {
    cout<<"Stack is empty."<<endl;
  }

  Stack* temp = node;
  while(temp != nullptr){
    cout<<temp->value<<" ";
    temp = temp->next;
  }
}


int main(){
  string data;
  Stack stack; // object
  Stack* ptr = nullptr;
  char option;

  cout<<"Welcome to the stack program."<<endl;
  cout << "Press 1 to push, 2 to pop, 3 to peek, 4 to display"<<endl;
  cin>>option;
  switch(option){
    case '1':
      cout<<"Enter your data:"<<endl;
      cin>>data;
      ptr = stack.push(ptr, data);  // assign new ptr to ptr
      if (ptr != nullptr) {
        cout<<"Data "<<data<<" is pushed into stack."<<endl;
      }
      else {
        cout<<"Unable to push data."<<endl;
      }
      break;               // Don't forget to break!!!!!!!
     
    case '2':
      ptr = stack.pop(ptr);
      if (ptr == nullptr) {
        cout<<"Stack is empty."<<endl;
      break;

    case '3':
      data = stack.peek(ptr);
      if(data == ""){
        cout<<"Stack is empty."<<endl;
      }
      cout<<"Peek element: "<<data<<endl;
      break;

    case '4':
      stack.dispaly(ptr);
      break;
    default:
      cout<<"Invalid input."<<endl;
  }
}
