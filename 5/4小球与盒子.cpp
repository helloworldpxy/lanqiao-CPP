#include<bits/stdc++.h>

using namespace std;
using ll=long long;
const ll N=1e6+5;

ll tree[N<<2],tag[N<<2];
int a[N];//因为该题没有预先给出盒子里面的球，所以无需a数组
int lson(int i){//访问左儿子
    return i<<1;
}
int rson(int i){//访问右儿子
    return i<<1|1;
}

void laze(ll i,ll pl,ll pr,ll d){
    tag[i]+=d;
    tree[i]+=d*(pr-pl+1);//更新树
}

void up(int i){
    tree[i]=tree[lson(i)]+tree[rson(i)];
}

void down(ll i,ll pl,ll pr){
    if(tag[i]){
        ll mid=(pl+pr)>>1;
        laze(lson(i),pl,mid,tag[i]);
        laze(rson(i),mid+1,pr,tag[i]);
        tag[i]=0;    
    }
}

void build(ll i,ll pl,ll pr){//该题同样无需建树，可以忽略不用
    tag[i]=0;
    if(pl==pr){//说明到了叶子节点
        tree[i]=a[pl];
        return ;
    }
    int mid=(pl+pr)>>1;//分治，继续查节点
    build(lson(i), pl, mid);
    build(rson(i), mid + 1, pr);
    up(i);//自底向上传递区间值
}

void update(ll i,ll pl,ll pr,ll L,ll R,ll d){//在[pl,pr]里面，更新[L,R]区间的数
    if(L<=pl&&pr<=R){
        laze(i,pl,pr,d);//利用懒信息拦住，避免不必要的运行
        //下一次修改时，需要用再往下发放懒信息
        return ;
    }
    down(i,pl,pr);//不能覆盖的话就看看有没有懒信息需要下发
    //把懒信息传给子树
    ll mid=(pl+pr)>>1;
    if(L<=mid){update(lson(i),pl,mid,L,R,d);}
    if(R>mid) {update(rson(i),mid+1,pr,L,R,d);}
    up(i);
}

ll querr(ll i,ll pl,ll pr,ll L,ll R){//在[pl,pr]里面，查询[L,R]区间的和
    if(L<=pl&&pr<=R){
        return tree[i];
    }
    ll res=0;
    down(i,pl,pr);//不能覆盖，将懒信息下发，递归子树
    ll mid=(pl+pr)>>1;
    if(L<=mid){res+=querr(lson(i),pl,mid,L,R);}
    if(R>mid) {res+=querr(rson(i),mid+1,pr,L,R);}
    return res;
}

int main() {
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    ll n,m;
    cin>>n>>m;
    //build(1,1,n);
    while(m--){
        ll op,x,y;
        cin>>op>>x>>y;
        if(op==1){
            update(1,1,n,x,x,y);
        }else{
            cout<<querr(1,1,n,x,y)<<'\n';
        }
    }
    return 0;
}
