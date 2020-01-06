
//define k as ceiling of log of MAXN
const int k=21;
 
int n;
vector<int> are[MAXN];
int h[MAXN];
int lc[k][MAXN];
 
//node, parent, height
void lca_dfs(int u, int p, int ha){
	h[u]=ha;
	lc[0][u]=p;
	for(int i=1;i<k;i++)
		lc[i][u]=lc[i-1][lc[i-1][u]];
	for(int v:are[u]){
		if(v!=p)lca_dfs(v,u,ha+1);
	}
}
 
int lca(int u, int v){
	if(h[u]>h[v])swap(u,v);
	for(int i=k-1;i>=0;i--){
		if(h[lc[i][v]]>=h[u])v=lc[i][v];
	}
	if(u==v)return u;
	for(int i=k-1;i>=0;i--){
		if(lc[i][u]!=lc[i][v]){
			u=lc[i][u];
			v=lc[i][v];
		}
	}
	return lc[0][u];
}
 