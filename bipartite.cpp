#include<bits/stdc++.h>
using namespace std;
/*bool f(int start,vector<int>adj[],vector<int> &color)
{
    queue<int>q;
    q.push(start);
    color[start]=1;
    while(!q.empty())
    {
        int node=q.front();
        q.pop();
        for(auto it:adj[node])
        {
            if(color[it]==-1)
            {
                q.push(it);
                color[it]=1-color[node];
            }
            else if(color[node]==color[it])
            return false;
        }
        
    }
    return true;
    
}*/
bool f(int start,vector<int>adj[],vector<int> &color)
{
    if(color[start]=-1)
    color[start]=1;
    for(auto it:adj[start])
    {
        if(color[it]==-1)
        {
            color[it]=1-color[start];
            if(!f(it,adj,color))return false;
        }
        else if(color[it]==color[start])
        {
            return false;
        }
    }
    return true;
}
bool checkBipartite(vector<int>adj[],int n)
{
    vector<int>color(n,-1);
    for(int i=0;i<n;i++)
    {
        if(color[i]!=-1)
        {
             color[i]=0;
            if(!f(i,adj,color))
            {
                return false;
            }
        }
    }
    return true;
}
int main() {
	int n, m;
	cin >> n >> m;
	vector<int> adj[n];
	for(int i = 0;i<m;i++) {
	    int u, v;
	    cin >> u >> v;
	    adj[u].push_back(v); 
	    adj[v].push_back(u); 
	}
	
	if(checkBipartite(adj, n)) {
	    cout << "yes"; 
	} else {
	    cout << "No"; 
	}
	return 0;
}

/*
8 7 
0 1 
1 2 
2 3 
3 4 
4 6 
6 7 
1 7
4 5 

// bipartite graph example 
*/ 

/*
7 7 
0 1 
1 2 
2 3 
3 4 
4 6 
6 1
4 5 
// not bipartite example
*/
