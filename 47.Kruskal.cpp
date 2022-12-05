//It is used to find mst 
//TC:O(V+E) + O(MlogM) +M*4*alpha*2
//SC:O(V)

class Solution

{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        //SC: O(V)
       vector<pair<int ,pair<int,int>>> edges;
       //TC: O(V+E)
       for(int i=0;i<V;i++)
       {
           for(auto it: adj[i])
           {
               int wt=it[1];
               int adjnode=it[0];
               int node=i;
               
               edges.push_back({wt,{node,adjnode}});
           }
       }
       
       sort(edges.begin(),edges.end()); // TC: O(nlongn)
       DisjointSet d(V);
       int mstwt=0;
       
       for(auto it:edges){       //TC: M*2*4 alpha
           int wt=it.first;
           int u=it.second.first;
           int v=it.second.second;
           if(d.findUPar(u)!=d.findUPar(v)){
               mstwt+=wt;
               d.unionByRank(u,v);
               
           }
           
       }
       return mstwt;
    }
};

//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}
