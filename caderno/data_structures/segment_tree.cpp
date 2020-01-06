//estou me forcando a usar a versao iterativa, apesar de nao estar tao 
//confortavel com ela quanto com a recursive

#define MAXN 112345
int n;
int seg[4*MAXN];

//v[i]=seg[n+i]

void build(){//build the tree
  for (int i=n-1;i>0;--i)seg[i]=seg[i<<1]+seg[i<<1|1];
}

void modify(int p,int value){// set value at position p
  for(seg[p+=n]=value;p>1;p>>=1)seg[p>>1]=seg[p]+seg[p^1];
}

int query(int l,int r){ //sum on interval [l, r)
  int resp=0;
  for(l+=n,r+=n;l<r;l>>=1,r>>=1){
    if(l&1)resp+=seg[l++];
    if(r&1)resp+=seg[--r];
  }
  return resp;
}