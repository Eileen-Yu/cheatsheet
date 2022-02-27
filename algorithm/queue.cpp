#include <iostream>
#include <string>

using namespace std;

class Node{
  private:
    Node* prior;
    Node* next;
    string value;
  
  public:
    Node(){};
    ~Node(){};
    // 添加节点
    Node* admit(Node* endPtr, string value){
      Node* temp;
      if(temp = new Node){
        temp->prior = endPtr;
        temp->next = nullptr;
        temp->value = value;
        if(endPtr != nullptr){
          endPtr->next = temp;
        }
      }
      else{
        cout<<"Heap exhausted."<<endl;
      }
      return temp;
    }
    
    //servePtr是要删除的节点
    Node* serve(Node* servePtr){
      Node* temp;
      temp = servePtr->next;
      delete servePtr;
      if(temp != nullptr){          // temp变成了front
        temp->prior = nullptr;
      }
      return temp;      // temp现在是最下面要pop的第一个
    }

    string peek(){
      return value;
    }

    Node* getNextPtr(Node* node){
      return next;
    }
};


class Queue{
  private:
    Node* front;  // 最下面要pop的
    Node* end;    // 最上面新加的
    bool peekFlag; // check if the node is peeked before served

  public:
    Queue();
    bool admitNode(string value);
    void serveSeniorNode();       // pop最前面的
    string peekSeniorNode();
};

Queue::Queue(){
  front = end = nullptr;
  peekFlag = false;
}

bool Queue::admitNode(string value){
  bool admitSuccess = false;
  Node a;   // object
  end = a.admit(end, value);
  if (end != nullptr){
    if(front == nullptr){
      front = end;
      admitSuccess = true;
    }
  }
  return admitSuccess; 
}

string Queue::peekSeniorNode(){
  string returnValue = "";
  if (front != nullptr){
    peekFlag = true;
    returnValue = front->peek();
  }
  else{
    cout<<"Queue is empty."<<endl;
  }
  return returnValue;
}

void Queue::serveSeniorNode(){
  if (peekFlag == true){
    Node a;
    front = a.serve(front);
    if (front == nullptr){   //　pop之后没有元素了
      end = nullptr;
    }
  }
  else{   //peekFlag == false 时即 1. front == nullptr / 2. 未peek
    if(front == nullptr){
      cout<<"Queue is empty."<<endl;
    }
    else {
      cout<<"Senior queue member hasn't been peeked."<<endl;
    }
  }
  peekFlag = false; // pop 后刷新peekFlag给新的front
}

