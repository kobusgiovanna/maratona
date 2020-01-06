
#define MAXN 1123456

int bit[MAXN];

void upd(int a, int x){
	if(a==0)return;
	for(int i=a;i<MAXN;i+=(i&-i))bit[i]+=x;
}

int get(int a){
	int resp=0;
	for(int i=a;i>0;i-=(i&-i))resp+=bit[i];
	return resp;
}
