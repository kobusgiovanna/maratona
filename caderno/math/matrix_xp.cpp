
#define MAXN 112
#define MOD 1000000007

int n;

struct matrix{
    int m[MAXN][MAXN];
    //assumes same size
    matrix mult(matrix b){
        matrix aux;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                aux.m[i][j]=0;
                for(int k=0;k<n;k++){
                    aux.m[i][j]+=m[k][j]*b.m[i][k]%MOD;
                    aux.m[i][j]%=MOD;
                }
            }
        }
        return aux;
    }
    int sum(){
        int resp=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                resp+=m[i][j];
                resp%=MOD;
            }
        }
        return resp;
    }
    //does not work for i==0
    matrix exp(int i){
        if(i==1)return *this;
        if(i%2==0)return (this->mult(*this)).exp(i/2);
        return this->mult(this->mult(*this).exp(i/2));
    }
};
 
 