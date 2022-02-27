// 深度优先遍历：一条道走到黑，走不通就回来换条路，使用递归
// 广度优先遍历：有层次的一层一层的去遍历，使用队列
#include <iostream>
#include <queue>

// 广度优先
void BFS(int x) { // x表示从哪个节点开始
  flag[x] = true; // 标注x已经访问到
  std::queue<int> q;
  q.push(x);
  while(!q.empty()){
    for(int i = 0; i < arraySize; i++){
        if(G[q.front()][i] == 1 && flag[i] == false) { // 在邻接矩阵中为1且未标记过
          q.push(i);
          flag[i] = true;
        }
    }

    std::cout<<q.front()<<" ";
    q.pop();
  }
}

// 深度优先
void DFS(int x) {
    flag[x] = true;
    std::cout<<x<<" ";
    for(int i = 0; i < arraySize; i++) {
      if (G[x][i] = 1 && flag[i] == false){
        DFS(i);
      }
    }
}
