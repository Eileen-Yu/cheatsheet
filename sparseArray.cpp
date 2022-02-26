#include <iostream>
#include <string>

using namespace std;

#define MAX 23

class Node{
  private:
    Node* next;
    string val;

  public:
    Node(){};
    ~Node(){};

    Node* putNode(Node* head, string val){
      Node* temp = new Node;
      if(temp){
        temp->next = head;
        temp->val = val;
      }
      return temp;
    };

    string getVal(){
      return val;  
    };

    Node* getNextPtr(){
      return next;
    };

    void putNextPtr(Node* newNode){
      this->next = newNode;
    };
};


class HashList{
  private:
    Node* head;
  public:
    HashList(){
      head = nullptr;
    };

    bool putListNode(string val){
      bool x = false;
      Node a;                 // object
      Node* temp = a.putNode(head, val);
      if(temp){
        head = temp;
        x = true;
      }
      return x;
    };

    Node* getListNode(){
     return head;  
    }

    Node* findNode(string val){
      Node* temp = head;
      while(temp != nullptr && temp->getVal()!= val){
        temp = temp->getNextPtr(); 
      }
      return temp;
    }

    void displayList(){
      Node* temp = head;
      while(head != nullptr) {
        cout<<temp->getVal()<<endl;
        temp = temp->getNextPtr();
      }
    }

    void deleteNode(string val){
      Node* deletePtr = findNode(val);   // 先用find定位要删除的ptr，再check是否为链表头，分类处理
      if(deletePtr != nullptr){
        // 1. deletePtr == head
        if (deletePtr == head){
          head = deletePtr->getNextPtr();
        }

        //2. deletePtr != head
        else{
          Node* prePtr = nullptr;
          Node* temp = head;
          while(temp != deletePtr){
            prePtr = temp;
            temp = temp->getNextPtr();
          }
          // when temp == deletePtr
          prePtr->putNextPtr(temp->getNextPtr());
        }

        delete deletePtr; 
      }
      
      // when deletePtr == nullptr
      else{
        cout<<"Invalid data entered."<<endl;
      }
    }
};

int calculate(string inputLine){
  int hashValue, modHash;
  for (auto ch : inputLine){     // 遍历string
    hashValue += static_cast<int>(ch);
    modHash = hashValue % MAX;
  }
  return modHash;
}

int main(){
  string inputLine;
  HashList namePtr[MAX];
  cout << "Please enter each string of characters followed by <Enter>. "<< endl;
  getline(cin,inputLine);
  int modHash = calculate(inputLine);
  namePtr[modHash].putListNode(inputLine);
  cout << " hashes to position " << modHash << endl;

  // display contents of data structure
  for(int i = 0; i < MAX; i++){
    if(namePtr[i].getListNode()) {
      cout<<"For position "<<i<<" attached list follows: "<<endl;
      namePtr[i].displayList();
    }
  }

}
