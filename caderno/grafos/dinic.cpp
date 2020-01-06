
#define int long long
#define MAXN 112345
#define INF LLONG_MAX
#define pb push_back

int n,src,dst;
int dis[MAXN],q[MAXN],work[MAXN];
struct edge{int to,rev;int f,cap;};
vector<edge> are[MAXN];

void dinic_add(int s,int t,int cap){
	are[s].pb((edge){t,(int)are[t].size(),0,cap});
	are[t].pb((edge){s,(int)are[s].size()-1,0,0});
}

bool dinic_bfs(){
	fill(dis,dis+n,-1);dis[src]=0;
	int qt=0;q[qt++]=src;
	for(int qh=0;qh<qt;qh++){
		int u=q[qh];
		for(int i=0;i<are[u].size();i++){
			edge &e=are[u][i];int v=are[u][i].to;
			if(dis[v]<0&&e.f<e.cap)dis[v]=dis[u]+1,q[qt++]=v;
		}
	}
	return dis[dst]>=0;
}

int dinic_dfs(int u, int f){
	if(u==dst)return f;
	for(int &i=work[u];i<are[u].size();i++){
		edge &e=are[u][i];
		if(e.cap<=e.f)continue;
		int v=e.to;
		if(dis[v]==dis[u]+1){
			int df=dinic_dfs(v,min(f,e.cap-e.f));
			if(df>0){
				e.f+=df;
				are[v][e.rev].f-=df;
				return df;
			}
		}
	}
	return 0;
}

int max_flow(int _src,int _dst){
	src=_src;dst=_dst;
	int resp=0;
	while(dinic_bfs()){
		fill(work,work+n,0);
		while(int delta=dinic_dfs(src,INF))
			resp+=delta;
	}
	return resp;
}
