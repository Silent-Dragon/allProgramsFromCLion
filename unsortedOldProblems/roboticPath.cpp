#include <iostream>
#include <cmath>
#include <string>
#include <map>
#include <stack>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int a1[4]={1,0,0,-1};
int b1[4]={0,-1,1,0};

bool check(int i,int j,int n,int m)
{
    if(i>=1&&i<=n&&j>=1&&j<=m)
        return true;

    return false;

}

int main()
{
    int n,m;
    cin>>n>>m;
    char a[n+1][m+1];
    bool vis[n+1][m+1];
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            cin>>a[i][j];
            vis[i][j]=false;
        }

    }

    int q;
    cin>>q;
    while(q--)
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                // cin>>a[i][j];
                vis[i][j]=false;
            }

        }

        int a2,b,x,y;
        cin>>a2>>b>>x>>y;

        queue<pair<int,pair<int,string> > >q;

        q.push(make_pair(a2,make_pair(b,"")));
        int flag=0;
        vis[a2][b]=true;
        while(!q.empty())
        {
            pair<int,pair<int,string> >p=q.front();
            q.pop();

            if(p.first==x&&p.second.first==y)
            {
                cout<<p.second.second<<endl;
                flag=1;

            }
            vis[p.first][p.second.first]=true;
            for(int k=0;k<4;k++)
            {
                int i1=p.first+a1[k];
                int j1=p.second.first+b1[k];
                if(check(i1,j1,n,m))
                {
                    if(vis[i1][j1]==false&&a[i1][j1]=='.')
                    {


                        vis[i1][j1]=true;
                        string s=p.second.second;
                        if(k==0)
                            q.push(make_pair(i1,make_pair(j1,s+'D')));
                        else if(k==1)
                            q.push(make_pair(i1,make_pair(j1,s+'L')));
                        else if(k==2)
                            q.push(make_pair(i1,make_pair(j1,s+'R')));
                        else if(k==3)
                            q.push(make_pair(i1,make_pair(j1,s+'U')));

                    }
                }
            }


        }
        if(!flag)
            cout<<"Impossible"<<endl;

    }

}