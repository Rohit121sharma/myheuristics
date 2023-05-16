#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
void print(vector<vector<int>>&vec){
    for(int i=0;i<vec.size();i++){
        for(int j=0;j<vec[i].size();j++)cout<<vec[i][j]<<" ";cout<<endl;
    }
}
void print(vector<int>&vec){for(int i=0;i<vec.size();i++)cout<<vec[i]<<" ";cout<<endl;}
int arr[][8]={{1,2},{-1,2},{1,-2},{-1,-2},{-2,1},{-2,-1},{2,1},{2,-1}};
int flag=1;
int grade(int x,int y,vector<vector<int>>&vec){
    if(x<0||y<0||x>=8||y>=8||vec[x][y]!=0)return 10;
    int g=0;
    for(int i=0;i<8;i++){
        if(x+arr[i][0]>=0&&x+arr[i][0]<8&&y+arr[i][1]>=0&&y+arr[i][1]<8)g++;
    }
    return g;
}
void fill(vector<vector<int>>&moves,vector<vector<int>>&vec,int x,int y){
    for(int i=0;i<8;i++){
        vector<int>temp;
        int g=grade(x+arr[i][0],y+arr[i][1],vec);
        temp.push_back(g);
        temp.push_back(x+arr[i][0]);
        temp.push_back(y+arr[i][1]);
        moves.push_back(temp);
    }
}
void dfs(int x,int y,vector<vector<int>>&vec,int put){
    vec[x][y]=put;
    if(put==64){print(vec);flag=0;return;}
    vector<vector<int>>moves;
    fill(moves,vec,x,y);
    sort(moves.begin(),moves.end());
    for(int i=0;i<moves.size();i++){
        if(flag&&moves[i][1]>=0&&moves[i][1]<8&&moves[i][2]>=0&&moves[i][2]<8
            &&vec[moves[i][1]][moves[i][2]]==0)dfs(moves[i][1],moves[i][2],vec,put+1);
    }
    vec[x][y]=0;
}
int main(){
    long long int n,n1,temp1,temp2,itr,x,y;
    cin>>y>>x;
    vector<vector<int>>vec(8,vector<int>(8,0));
    dfs(x-1,y-1,vec,1);
    return 0;
}