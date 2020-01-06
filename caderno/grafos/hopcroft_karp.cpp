
#define pb push_back
#define MAXN 112345
#define INF LLONG_MAX/2

vector<int> are[MAXN];
//number of left noes, number of right nodes
int n,m;
int mn[MAXN],mm[MAXN],dis[MAXN];

bool matching_bfs(){
    queue<int> q;
    for(int i=0;i<n;i++)dis[i]=-1;
    for(int i=0;i<n;i++)if(mn[i]<0){dis[i]=0;q.push(i);}
    bool r=0;
    while(!q.empty()){
        int x=q.front();q.pop();
        for(int y:are[x]){
            if(mm[y]>=0&&dis[mm[y]]<0){
                dis[mm[y]]=dis[x]+1;q.push(mm[y]);
            }
            else if(mm[y]<0)r=true;
        }
    }
    return r;
}

bool matching_dfs(int x){
    for(int y:are[x]){
        if(mm[y]<0||(dis[mm[y]]==dis[x]+1&&matching_dfs(mm[y]))){
            mm[y]=x;mn[x]=y;return true;
        }
    }
    dis[x]=INF;
    return false;
}

int max_matching(){
    int r=0;
    for(int i=0;i<n;i++)mn[i]=-1;
    for(int i=0;i<m;i++)mm[i]=-1;
    while(matching_bfs()){
        for(int i=0;i<n;i++){if(mn[i]<0)r+=matching_dfs(i);}
    }
    return r;
}