 
#define MAXN 1123

int bit[MAXN][MAXN];
 
void upd(int x,int y, int val){
	for(int i=x;i<=n;i+=(i&-i))
		for(int j=y;j<=n;j+=(j&-j))
			bit[i][j]+=val;
}
 
int get(int x,int y){
	int resp=0;
	for(int i=x;i>0;i-=(i&-i))
		for(int j=y;j>0;j-=(j&-j))
			resp+=bit[i][j];
	return resp;
}
 