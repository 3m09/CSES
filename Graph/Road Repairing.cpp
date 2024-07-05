#include <bits/stdc++.h>
using namespace std;
 
// vector<vector<int>> neighbor;
int parent[1000005];
int rnk[1000005];
void DSUinit(int V){
    for(int i=0;i<V;i++){
        parent[i]=i;
        rnk[i]=0;
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
        if(rnk[x]<rnk[y])
            swap(x,y);
        parent[y]=x;
        if(rnk[x]==rnk[y])
          rnk[x]++;
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

        vector<tuple<long long, int, int>> edges;

        for(int i = 0; i < m; i++)
        {
            int u, v, w;
            cin >> u >> v >> w;
            edges.push_back({w, u, v});
        }

        sort(edges.begin(), edges.end());

        long long ans = 0, cnt = 0;

        DSUinit(n);

        for(auto edge : edges)
        {
            int u = get<1>(edge);
            int v = get<2>(edge);
            int w = get<0>(edge);

            if(Find(u) != Find(v))
            {
                unite(u, v);
                ans += w;
                cnt++;
            }
        }

        if(cnt == n - 1)
            cout << ans << endl;
        else
            cout << "IMPOSSIBLE" << endl;
 
    }
    return 0;
}
