 #include<bits/stdc++.h>

using namespace std;
class Solution{
    public :
 void printadjmatrix(vector<int>pf[],int n)
 {
     for(int i=0;i<n;i++)
     {
         cout<<i<<" ";
     
     for(int j=0;j<pf[i].size();i++)
     {
         cout<<pf[i][j]<<" ";
     }
      cout<< endl;
     }
 }
};
int main()
{
    
    int n,m;
    cout<<"Enter the number of nodes";
    cin>>n;
    cout<<"Enter the number of edges";
    cin>>m;
    vector<int> adj[n+1];
    for(int i=0; i<m; i++)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    Solution obj;
    obj.printadjmatrix(adj,n);
        return 0;
}


//If the graph is weighted then use vector<pair<int,int>> adj[n+1]; and inside for loop take it wt cin wt and then push back along with v 
vector<pair<int,int>> adj[n+1];
for(int i=0;i<m;i++)
{
   int u,v,wt;
   cin>>u>>v>>wt;
   adj[u].push_back({v,wt});
   adj[v].push_back({u,wt});
  }
