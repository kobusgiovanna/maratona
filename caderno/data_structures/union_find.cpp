
#define MAXN 1123456

int n;
int pai[MAXN],peso[MAXN];

int find(int x){
	return pai[x]=(x==pai[x]?x:find(pai[x]));
}

void join(int x,int y){
	if((x=find(x))==(y=find(y)))return;
	if(peso[x]<peso[y])swap(x,y);
	peso[x]+=peso[y];pai[y]=x;
}

void init(){
	for(int i=0;i<n;i++)peso[pai[i]=i]=1;
}