#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define F first
#define S second
#define pb push_back
const ll MAX_N=1e6+10,INF=99999999;
ll n,a[MAX_N],s[MAX_N],from[MAX_N],to[MAX_N],w[MAX_N];
vector<int> adj[MAX_N];
void dfs(int v,int p){
    for(int k:adj[v]){
        int u=from[k]^to[k]^v;
        if(u!=p){
            dfs(u,v);
            if(adj[u].size()==1){
                w[k]=a[u];
            }
            else{
                w[k]=(2*a[u])-s[u];
            }
            if(w[k]<0){
                cout<<"NO";
                exit(0);
            }
            s[v]+=w[k];
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n-1;i++){
        cin>>from[i]>>to[i];
        adj[from[i]].pb(i);
        adj[to[i]].pb(i);
    }
    dfs(1,0);
    ll sum=0;
    for(int u:adj[1]){
        sum+=w[u];
    }
    if(adj[1].size()>1 && 2*a[1]!=sum){
        cout<<"NO";
        return 0;
    }
    if(adj[1].size()==1 && a[1]!=sum){
        cout<<"NO";
        return 0;
    }
    for(int i=1;i<=n;i++){
        ll mx=-INF,sum=0;
        for(int u:adj[i]){
            mx=max(mx,w[u]);
            sum+=w[u];
        }
        if(2*mx>sum && adj[i].size()>1){
            cout<<"NO";
            return 0;
        }
    }
    cout<<"YES";
}
