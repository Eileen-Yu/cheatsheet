#include <iostream>;
#include <queue>;

// tree node
struct Node{
  int val;
  Node *left;
  Node *right;
 
  Node(int x){
    left = nullptr;
    right = nullptr;
    val = x;
  }
};


// recursive, for constructor
Node* makeTree(const int* a, size_t size, int idx, char invalid){
  Node* root = nullptr;
  if (idx < size && a[idx] != invalid){
    root = new Node(invalid); // 隐式转换？char --> int
    root->val = a[idx];
    root->left = makeTree(a, size, idx, invalid);
    root->right = makeTree(a, size, idx, invalid);
  }
  return root;
}


// for copy constructor
Node* copyTree(const Node* root){
  if (root == nullptr) {return nullptr;}

  Node* newRoot = new Node(root->val);
  newRoot->left = copyTree(root->left);
  newRoot->right = copyTree(root->right);

  return newRoot;
}


// for destructor
void destroy(Node* root){
  Node* tmp = root;
  if (tmp == nullptr) {return;} // 如果根节点为空, 无需delete value, 直接return
  destroy(tmp->left);
  destroy(tmp->right);
  delete tmp;  // delete tmp指向的value
  tmp = nullptr; // tmp指针会在block结束后自行消失
} 


// preorder 中左右
void _preorder(Node *root){
  Node* tmp = root;
  if (tmp == nullptr) {return;}
  std::cout<<tmp->val<<" "<<std::endl;
  _preorder(tmp->left);
  _preorder(tmp->right);
}


// inorder 左中右
void _inorder(Node* root){
  Node* tmp = root;
  if (tmp == nullptr) {return;}
  _inorder(tmp->left);
  std::cout<<tmp->val<<" "<<std::endl;
  _inorder(tmp->right);
}


// postorder 左右中
void _postorder(Node* root){
  Node* tmp = root;
  if (tmp == nullptr) {return;}
  _postorder(tmp->left);
  _postorder(tmp->right);
  std::cout<<tmp->val<<" "<<std::endl;
}


// 查找第k层的节点个数（查找第k-1层有几个child）
size_t _findKLevel(Node* root, size_t k) {
  Node* cur = root;
  if (cur == nullptr || k < 0){
    return 0;
  }
  if (k == 1) {
    return 1;
  }

  size_t left = _findKLevel(cur->left, k-1);
  size_t right = _findKLevel(cur->right, k-1);

  return left + right;
}


//精确查找值为x的节点
Node* _find(Node* root, const int& x) {
  Node* pos = nullptr;
  Node* cur = root;

  if (cur == nullptr){
    return nullptr;
  }

  if (cur->val == x){
    pos = cur;
  }

  pos = _find(cur->left,x);
  if(pos == nullptr){
    pos = _find(cur->right,x);
  }

  return pos;
}


// 查找节点总个数
size_t _size(Node* root) {
  size_t num = 0;
  if (root == nullptr){
    return num;
  }
  num++;
  num += _size(root->left);
  num += _size(root->right);
}


class BinaryTree{
  public:
  // constructor
  BinaryTree(const int* a, size_t size, int idx, char invalid){
    root = makeTree(a, size, idx, invalid);
  };
  // copy constructor
  BinaryTree(const BinaryTree &t){
    root = copyTree(t.root);
  };
  // destructor
  ~BinaryTree(){
    destroy(root);
  };

  // operator overloading( = must be a member func)
  BinaryTree& operator=(BinaryTree t){ // t自动销毁，完成了销毁root原本内容的工作
    if (this != &t){
      std::swap(root, t.root); // t是临时拷贝
    }
    return *this;
  }

  void preorder(){
    _preorder(root);
    std::cout<<std::endl;
  }

  void inorder(){
    _inorder(root);
    std::cout<<std::endl;
  }

  void postorder(){
    _postorder(root);
    std::cout<<std::endl;
  }

  size_t findKLevel(size_t k) {
    return _findKLevel(root, k);
  }
  
  Node* find(int& x){
    return _find(root, x);
  }

  size_t size(){
    return _size(root);
  }

  private:
  Node *root;
};


// 层序遍历(queue)
void _levelOrder(Node* root) {  
  Node* tmp = root;
  std::queue<Node*> q; // 创建队列
  q.push(tmp);  // 根结点先进入
  while(!q.empty()){
    Node* top = q.front();   //取队列第一个
    q.pop();
    std::cout<<top->val<<" ";
    if(top->left){
      q.push(top->left);
    }
    if(top->right){
      q.push(top->right);
    }
  }
}









