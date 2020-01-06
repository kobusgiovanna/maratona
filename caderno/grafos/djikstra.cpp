
typedef pair<int,int> pii;
#define mp make_pair
#define f first
#define s second
#define MAXN 112345

vector<pii> are[MAXN];
int dis[MAXN];

void dij(int x){
	for(int i=0;i<MAXN;i++)dis[i]=-1;
	priority_queue<pii> q;
	dis[x]=0;q.push(mp(0,x));
	while(!q.empty()){
		x=q.top().s;int c=-q.top().f;q.pop();
		if(dis[x]!=c)continue;
		for(pii at:are[x]){
			int y=at.s,c=at.f;
			if(dis[y]==-1||dis[x]+c<dis[y]){
				dis[y]=dis[x]+c;
				q.push(mp(-dis[y],y));
			}
		}
	}
}


