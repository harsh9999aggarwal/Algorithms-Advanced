#include<iostream>
using namespace std;
void pop(int s[50][50],int i,int j){
if(i==j){
    cout<<"A";
    return;}
else
    cout<<"(";
pop(s,i,s[i][j]);
pop(s,s[i][j]+1,j);
cout<<")";
}

int main()
    {
        int p[10]={30,35,15,5,10,20,25};
        int m[20][20],s[50][50];
        int n=6,l,j,q,i,k;

        for(i=0;i<=n;i++){
            m[i][i]=0;
        }
        for(l=2;l<=n;l++){
            for(i=1;i<=n-l+1;i++){
                j=i+l-1;
                m[i][j]=999999;
                for(k=i;k<=j-1;k++){
                    q=m[i][k] + m[k+1][j] + (p[i-1]*p[k]*p[j]);
                    if(q<m[i][j]){
                        m[i][j]=q;
                        s[i][j]=k;
                    }
                }
            }
        }
        for(i=1;i<=n;i++){
            for(j=1;j<=n;j++){
                if(i>j)
                    cout<<"\t";
                else
                    cout<<m[i][j]<<"\t";

            }
            cout<<"\n";
        }
        for(i=1;i<=n;i++){
            for(j=1;j<=n;j++){
                if(i>j)
                    cout<<"\t";
                else
                    cout<<s[i][j]<<"\t";

            }
            cout<<"\n";
        }
pop(s,1,6);
cout<<"\n\n";
return 0;
}
