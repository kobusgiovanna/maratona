
int tothe(int a,int b){
    if(b==1)return a%MOD;
    return (((b%2==1)?a:1)*tothe((a*a)%MOD,b/2))%MOD;
}

int inv(int a){
    return tothe(a,MOD-2);
}