
#define MAXN 112345

pair<int,int> sf[MAXN];

bool sa_comp(int a,int b){return sf[a]<sf[b];}

vector<int> sa_make(string &s){
    int n=s.size();
    vector<int> sa(n),r(n);
    for(int i=0;i<n;i++)r[i]=s[i];
    for(int i=1;i<n;i*=2){
        for(int j=0;j<n;j++){
            sa[j]=j;
            sf[j]=make_pair(r[j],j+i<n?r[j+i]:-1);
        }
        stable_sort(sa.begin(),sa.end(),sa_comp);
        r[sa[0]]=0;
        for(int j=1;j<n;j++)r[sa[j]]=sf[sa[j]]!=sf[sa[j-1]]?j:r[sa[j-1]];
    }
    return sa;
}

vector<int> sa_lcp(string &s, vector<int> &sa){
    int n=s.size(),L=0;
    vector<int> lcp(n),plcp(n),phi(n);
    phi[sa[0]]=-1;
    for(int i=1;i<n;i++)phi[sa[i]]=sa[i-1];
    for(int i=0;i<n;i++){
        if(phi[i]<0){plcp[i]=0;continue;}
        while(s[i+L]==s[phi[i]+L])L++;
        plcp[i]=L;
        L=max(L-1,0ll);
    }
    for(int i=0;i<n;i++){
        lcp[i]=plcp[sa[i]];
    }
    return lcp;
}
















