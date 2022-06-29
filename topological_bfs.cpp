
#include <iostream>
#include<bits/stdc++.h>
using namespace std;
class Solution{
  public:
bool topo(int n,vector<int> adj[],vector<int>&topo)
  {
      queue<int> q;
      vector<int> answer;
      vector<int> indegree(n,0);
      for(int i=0;i<n;i++)
      {
          for(auto it: adj[i])
          indegree[it]++;
      }
      for(int i=0;i<n;i++)
      {
          if(indegree[i]==0)
          q.push(i);
      }
      
      int count=0;
      while(!q.empty())
      {
          int node=q.front();
          topo.push_back(node);
          count++;
          q.pop();
          for(auto it: adj[node])
          {
              indegree[it]--;
              if(indegree[it]==0)
              q.push(it);
          }
      }
       if(count==n)
       return true;
       return false;
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
        vector<int>topo;
    	Solution obj;
    	bool a=obj.topo(6, adj,topo);
    	if(a)
    	{
    	for(auto it:topo)
    	cout<<it<<" ";
    	}
    	else
    	cout<<"cycle detected";
    

    return 0;
}
