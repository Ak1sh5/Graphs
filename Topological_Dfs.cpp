/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include<bits/stdc++.h>
using namespace std;
class Solution{
  public:
  bool ans(int n,vector<int> adj[],vector<int> &visited,stack<int> &s,vector<int> &visal)
  {
      visal[n]=1;
      visited[n]=1;
      for(auto it:adj[n])
      {
          if(!visited[it])
          {
              if(ans(it,adj,visited,s,visal))return false;
          }
          else if(visited[it]==visal[it])
          {
              
              return true;
          }
          
      }
      visal[n]=0;
      s.push(n);
      return false;
  }
  vector<int> topoSort(int n,vector<int> adj[])
  {
      bool a;
      stack<int>s;
      vector<int> visal(n,0);
      vector<int> answer;
      vector<int>visited(n,0);
      for(int i=0;i<n;i++)
      {
          if(!visited[i])
          {
             a =ans(i,adj,visited,s,visal);
          }
      }
      if(!a)
      {
         while(!s.empty())
         {
          answer.push_back(s.top());
          s.pop();
         } 
          
      }
      else{
          cout<<"Cycle detected";
      }
      
      return answer;
  }
};
void addEdge(vector < int > adj[], int u, int v) {
  adj[u].push_back(v);
  adj[v].push_back(u);
}

int main() {

  int V = 6;

  vector < int > adj[V];
  addEdge(adj, 0, 1);
  addEdge(adj, 1, 2);
  addEdge(adj, 1, 5);
  addEdge(adj, 2, 3);
  addEdge(adj, 3, 4);
  addEdge(adj, 4, 0);
  addEdge(adj, 4, 1);

  Solution obj;
  vector < int > res = obj.topoSort(6, adj);

  
  for (int i = 0; i < res.size(); i++) {
    cout << res[i] << " ";
  }

  return 0;
} 
