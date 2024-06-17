#include<bits/stdc++.h>
 
using namespace std;
    char tabel[10005][10005];
    int n,m,ans,q;

int a[100][100]; 
 
void fill(int i,int j){
    tabel[i][j]='o';
    if(tabel[i-1][j]=='#' && i>1){
        ans++;
    }
    if(tabel[i][j-1]=='#' && j>1){
        ans++;
    }
     if(tabel[i+1][j]=='#' && i<n){
        ans++;
    }
     if(tabel[i][j+1]=='#' && j<m){
        ans++;
    }
    if(tabel[i-1][j]=='.' && i>1){
        fill(i-1,j);
    }
    if(tabel[i][j-1]=='.' && j>1){
        fill(i,j-1);
    }
     if(tabel[i+1][j]=='.' && i<n){
        fill(i+1,j);
    }
     if(tabel[i][j+1]=='.' && j<m){
        fill(i,j+1);
    }
    
    
}
    
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>m>>q;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>tabel[i][j];
        }
    }
    for(int i=0;i<q;i++){
        for(int l=1;l<=n;l++){
        for(int j=1;j<=m;j++){
            if(tabel[l][j]=='o')tabel[l][j]='.';
        }
    }
        ans=0;
        memset(a, 0, sizeof(a));
        int b,k;
        cin>>b>>k;
        if(tabel[b][k]=='.'){
              fill(b,k);
            }
        cout<<ans<<endl;
    }
    
}
