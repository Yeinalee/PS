# DFS

한 노드에서 시작하여 최대한 깊이 내려간 후, 더 이상 갈 곳이 없으면 되돌아오는 방식

- 동작 방식

1. 현재 정점을 방문하고 방문 표시
2. 연결된 정점 중 방문하지 않은 정점이 있다면 그 정점으로 이동하여 1번부터 다시 수행
3. 더 이상 방문할 수 있는 정점이 없으면 이전 정점으로 되돌아감
4. 모든 정점을 방문할 때까지 반복

<br/>

- 특징
  - 최단 경로 보장X
  - 시간 복잡도 O(V+E)
  - 백트래킹, 위상 정렬

<br/>

- 구현 방법

  - 재귀 방식

  ```c++
    vector<int> graph[6];
    vector<bool> visited(6, false);

    void dfs(int node){
        if (visited[node]) return; // 이미 방문한 노드라면 종료

        // 노드 방문 후 처리

        visited[node] = true; //방문 처리
        for(int next: graph[node]){ //연결된 노드 탐색
            if(!visited[next])
                dfs(next);
        }
    }
  ```

  - 스택을 이용한 반복문 방식

  ```c++
    vector<int> graph[6];
    vector<bool> visited(6, false);

    void dfs(int start){
        stack<int> s;
        s.push(start);

        while(!s.empty()){
            int node = s.top();
            s.pop();

            if(!visited[node]){

                //노드 방문 후 처리

                visited[node] = true;

                for(auto it = graph[node].rbegin(); it != graph[node].rend(); it++){
                    if(!visited[*it]) //방문하지 않은 노드만 스택에 추가
                        s.push(*it);
                }
            }
        }
    }
  ```

<br/>

## 이분그래프

- 인접한 정점끼리 서로 다른 색으로 칠해서 모든 정점을 두 가지 색으로만 칠할 수 있는 그래프
- 그래프의 모든 정점이 두 그룹으로 나눠지고, 서로 다른 그룹의 정점이 간선으로 연결되어져 있는 그래프
