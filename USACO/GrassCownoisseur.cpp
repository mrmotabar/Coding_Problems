#include<bits/stdc++.h>
using namespace std;
#define pb push_back
const int MAX_N=1e6;
int n,m,lab,cntc[MAX_N],col[MAX_N],dp1[MAX_N],dp2[MAX_N],ans,jay[MAX_N];
vector<int> khor[MAX_N],vor[MAX_N],topol,topo;
bool mark[MAX_N];
void dfs(int v){
    mark[v]=1;
    for(int u:khor[v]){
        if(!mark[u]){
            dfs(u);
        }
    }
    topol.pb(v);
}
void sfd(int v){
    topol.pb(v);
    jay[v]=topol.size()-1;
    mark[v]=1;
    col[v]=lab;
    cntc[lab]++;
    for(int u:vor[v]){
        if(!mark[u]){
            sfd(u);
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("grass.in","r",stdin);
    freopen("grass.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        a--;
        b--;
        khor[a].pb(b);
        vor[b].pb(a);
    }
    for(int i=0;i<n;i++){
        if(!mark[i]){
            dfs(i);
        }
    }
    reverse(topol.begin(),topol.end());
    memset(mark,0,sizeof mark);
    topo=topol;
    topol.clear();
    for(int i=0;i<n;i++){
        if(!mark[topo[i]]){
            sfd(topo[i]);
            lab++;
        }
    }
    dp1[col[0]]=cntc[col[0]];
    dp2[col[0]]=cntc[col[0]];
    for(int i=jay[0]+1;i<topol.size();i++){
        if(col[topol[i]]==col[0]){
        }
        else{
            for(int u:vor[topol[i]]){
                if(col[u]!=col[topol[i]] && dp1[col[u]]>0){
                    dp1[col[topol[i]]]=max(dp1[col[topol[i]]],dp1[col[u]]+cntc[col[topol[i]]]);
                }
            }
        }
    }
    for(int i=jay[0]-1;i>=0;i--){
        if(col[topol[i]]==col[0]){;
        }
        else{
            for(int u:khor[topol[i]]){
                if(col[u]!=col[topol[i]] && dp2[col[u]]>0){
                    dp2[col[topol[i]]]=max(dp2[col[topol[i]]],dp2[col[u]]+cntc[col[topol[i]]]);
                }
            }
        }
    }
    ans=dp1[col[0]];
    for(int i=0;i<topol.size();i++){
        for(int u:vor[topol[i]]){
            if(col[u]!=col[topol[i]] && dp1[col[topol[i]]]>0 && dp2[col[u]]>0){
                ans=max(ans,dp1[col[topol[i]]]+dp2[col[u]]-cntc[col[0]]);
            }
        }
    }
    cout<<ans<<endl;
}
