#include <iostream>
#include <vector>
#include <stack>

using namespace std;

vector< vector<int> > graph;
vector<bool> seen;

void fillStack(int v, stack<int> &st, vector< vector<int> > transposed) {
  seen[v] = true;

  for(int i = 0; i < transposed[v].size(); i++) {
    int u = transposed[v][i];
    if(!seen[u])
      fillStack(u, st, transposed);
  }

  st.push(v);
}

vector< vector<int> > getTranspose() {
  vector< vector<int> > aux(graph.size(), vector<int> ());

  for(int i = 0; i < graph.size(); i++) {
    for(int j = 0; j < graph[i].size(); j++) {
      int tmp = graph[i][j];
      aux[tmp].push_back(i);
    }
  }

  return aux;
}

void dfs(int v) {
  seen[v] = true;

  cout << v << " ";

  for(int i = 0; i < graph[v].size(); i++) {
    int u = graph[v][i];
    if(!seen[u])
      dfs(u);
  }
}

void stronglyConnectedComponents() {
  stack<int> st;

  vector< vector<int> > transposed = getTranspose();

  for(int i = 0; i < transposed.size(); i++) {
    if(!seen[i])
      fillStack(i, st, transposed);
  }

  for(int i = 0; i < graph.size(); i++)
    seen[i] = false;

  cout << "Connected components: " << endl;

  while(!st.empty()) {
    int v = st.top();
    st.pop();

    if(!seen[v]) {
      dfs(v);
      cout << endl;
    }
  }
}

int main() {

  graph.assign(5, vector<int>());

  graph[1].push_back(0);
  graph[0].push_back(2);
  graph[2].push_back(1);
  graph[0].push_back(3);
  graph[3].push_back(4);

  seen.assign(graph.size(), false);

  stronglyConnectedComponents();

  graph.clear();
  seen.clear();

  return 0;
}