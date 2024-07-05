#include <bits/stdc++.h>
using namespace std;
 
// vector<vector<int>> neighbor;
int parent[1000005];
int sz[1000005];

int mx = -1;

void DSUinit(int V){
    for(int i=0;i<V;i++){
        parent[i]=i;
        sz[i]=1;
    }
}
int Find(int node){
    if(parent[node]==node)
       return node;
    return parent[node]=Find(parent[node]);
}
void unite(int src,int dest){
    int x=Find(src),y=Find(dest);
    if(x!=y){
        parent[y]=x;
        sz[x] += sz[y];
    }
}
 
int main()
{

    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
 
    // ifstream inputFile("test_input.txt");
    // ofstream outputFile("output.txt");
 
    // // Redirect cin to read from inputFile
    // streambuf *cinbuf = cin.rdbuf();
    // cin.rdbuf(inputFile.rdbuf());
 
    // // Redirect cout to write to outputFile
    // streambuf *coutbuf = cout.rdbuf();
    // cout.rdbuf(outputFile.rdbuf());
 
    long long T;
   // cin >> T;
    T=1;
    while(T--)
    { 
        long long n, m;
        cin >> n >> m;

        vector<pair<int, int>> edges;

        for(int i = 0; i < m; i++)
        {
            int u, v;
            cin >> u >> v;
            edges.push_back({u, v});
        }

        // sort(edges.begin(), edges.end());

        long long cnt = n;

        DSUinit(n + 1);

        for(auto edge : edges)
        {
            int u = get<0>(edge);
            int v = get<1>(edge);

            int parentU = Find(u), parentV = Find(v);

            if(parentU != parentV)
            {
                unite(u, v);
                cnt--;
                mx = max(mx, sz[parentU]);
            }
            cout << cnt << " " << mx << endl;
        }
 
    }
    return 0;
}
