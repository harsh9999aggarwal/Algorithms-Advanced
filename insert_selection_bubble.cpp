#include<iostream>
#include<dos.h>
#include<windows.h>
#include<time.h>
#include<conio.h>
#include<stdlib.h>
using namespace std;

void ins (int a[],int n)
    {
        int i,j,key;
        for(i=1;i<n;i++)
        {
            key=a[i];
            j=i-1;
            while(j>=0 && a[j]>key)
            {
                a[j+1]=a[j];
                j=j-1;
            }
            a[j+1]=key;
        }
      /*  for(int q=0;q<n;q++){
            cout<<" "<<a[q];
        }*/
    }
void sel(int a[],int n)
    {
        int i,j,temp;
        for(i=1;i<n;i++)
        {
            for(j=i+1;j<n;j++)
            {
                if(a[i]>a[j])
                {

                    temp=a[i];
                    a[i]=a[j];
                    a[j]=temp;
                }
            }
        }
    }
void bob(int a[], int n)
    {

        int i,j,temp,sorted;
        for(i=0;i<n;i++)
        {
            for(j=0;j<(n-i-1);j++)
            {
                sorted=1;
                if(a[j]>a[j+1]){
                    sorted=0;
                    temp=a[j+1];
                    a[j+1]=a[j];
                    a[j]=temp;
                }
            }
            if(sorted){
                break;
            }
        }
    }

int main()
    {
        system("cls");
       // randomize();
        int a[30000],n,i;
        double  t;
        clock_t st,en;
     for(int v=0;v<3;v++){
        cout<<"---------->>>   enter the n  :   ";
        cin>>n;
        cout<<"        -----------     insertion sort    ------------        ";
        for(i=0;i<n;i++){
            a[i]=rand()%n;
        }

            st=clock();
            ins(a,n);
            Sleep(80);
            en=clock();
            cout<<"\naversge case  :   "<<(float)(en-st)/CLK_TCK;

        for(i=0;i<n;i++){
            a[i]=i;
        }

            st=clock();
            ins(a,n);
            Sleep(50);
            en=clock();
            cout<<"\nbest case     :   "<<(float)(en-st)/CLK_TCK;

         for(i=0;i<n;i++){
            a[i]=n-i;
        }

            st=clock();
            ins(a,n);
            Sleep(50);
            en=clock();
            cout<<"\nworst case    :   "<<(float)(en-st)/CLK_TCK;

            cout<<"\n        ------------     selection sort    ---------              ";
        for(i=0;i<n;i++){
            a[i]=rand();
        }

            st=clock();
            sel(a,n);
            Sleep(50);
            en=clock();
            cout<<"\naverage case  :   "<<(float)(en-st)/CLK_TCK;

        for(i=0;i<n;i++){
            a[i]=i;
        }

            st=clock();
            sel(a,n);
            Sleep(50);
            en=clock();
            cout<<"\nbest case     :   "<<(float)(en-st)/CLK_TCK;

         for(i=0;i<n;i++){
            a[i]=n-i;
        }

            st=clock();
            sel(a,n);
            Sleep(50);
            en=clock();
            cout<<"\nworst case    :   "<<(float)(en-st)/CLK_TCK;



            cout<<"\n             -------     bublle sort    ------------ ";
        for(i=0;i<n;i++){
            a[i]=rand();
        }

            st=clock();
            bob(a,n);
            Sleep(50);
            en=clock();
            cout<<"\naversge case  :   "<<(float)(en-st)/CLK_TCK;

        for(i=0;i<n;i++){
            a[i]=i;
        }

            st=clock();
            bob(a,n);
            Sleep(50);
            en=clock();
            cout<<"\nbest case     :   "<<(float)(en-st)/CLK_TCK;

         for(i=0;i<n;i++){
            a[i]=n-i;
        }

            st=clock();
            bob(a,n);
            Sleep(50);
            en=clock();
            cout<<"\nworst case    :   "<<(float)(en-st)/CLK_TCK;

    cout<<"\n";
    }


            return 0;
    }
