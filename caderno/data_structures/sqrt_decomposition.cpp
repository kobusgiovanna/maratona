//query de minimo
//a implementacao ta um lixo

#define MAXN 1123456
#define SQRT_MAXN 1123
#define INF INT_MAX

int n;
int bnum;//numero de baldes
int bsize;//tamanho maximo do balde
int v[MAXN];
int mini[SQRT_MAXN];//minimo por balde

//em que balde esta dado elemento
int bucket(int i){return i/bsize;}

void prep(){
    bsize=1;
    while(bsize*bsize<n)bsize++;
    bnum=(n+bsize-1)/bsize;
    for(int i=0;i<bnum;i++)mini[i]=INF;
    for(int i=0;i<n;i++)mini[bucket(i)]=min(mini[bucket(i)],v[i]);
}

int query(int i, int j){
    int resp=INF;    
    int firstb=bucket(i);
    int lastb=bucket(j);
    for(int k=i;k<=min((a+1)*bsize-1,j);k++)resp=min(resp,v[k]);
    for(int k=max(lastb*bsize,i);k<=j;k++)resp=min(resp,v[k]);
    for(int k=firstb+1;k<lastb;k++)resp=min(resp,mini[k]);
    return resp;
}

void change(int i, int x){
    v[i]=x;
    int currb=bucket(i);
    mini[currb]=INF;
    for(int k=currb*bsize;k<=min((a+1)*bsize,n)-1;k++)
        mini[currb]=min(mini[currb],v[k]);
}