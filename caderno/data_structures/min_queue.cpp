
struct min_queue{
    deque<pair<int,int>> dq;
    void insert(int a){
        int counter=1;
        while(dq.size()>0&&dq.front().first>=a){
            counter+=dq.front().second;
            dq.pop_front();
        }
        dq.push_front(make_pair(a,counter));
    }
    void remove(){
        pair<int,int> back=dq.back();
        dq.pop_back();
        back.second--;
        if(back.second!=0)dq.push_back(back);
    }
    int mini(){
        return dq.back().first;
    }
};