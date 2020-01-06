
#define pb push_back
#define MAXN 112345

vector<int> are[MAXN];
int n;
//lexicographically smallest
vector<int> tsort(){
	vector<int> resp;
	priority_queue<int> q;
	vector<int> d(n,0);
	for(int i=0;i<n;i++){
		for(int j=0;j<are[i].size();j++)
			d[are[i][j]]++;
	}
	for(int i=0;i<n;i++)if(!d[i])q.push(-i);
	while(!q.empty()){
		int x=-q.top();q.pop();resp.pb(x);
		for(int i=0;i<are[x].size();i++){
			d[are[x][i]]--;
			if(!d[are[x][i]])q.push(-are[x][i]);
		}
	}
	return resp;
}





