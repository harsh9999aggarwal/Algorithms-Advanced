#include<iostream>
#include<stdio.h>
#include<unistd.h>
#include<dos.h>
#include<time.h>
#include<windows.h>
#include<conio.h>
#include<stdlib.h>
#include<math.h>

using namespace std;

void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}
/*

int partition(int a[],int l,int u)
{
    int v,i,j,temp;
    v=a[l];
    i=l;
    j=u+1;

    do
    {
        do
            i++;

        while(a[i]<v&&i<=u);

        do
            j--;
        while(v<a[j]);

        if(i<j)
        {
            temp=a[i];
            a[i]=a[j];
            a[j]=temp;
        }
    }while(i<j);

    a[l]=a[j];
    a[j]=v;

    return(j);
}*/
int partition(int arr[],int low,int high){
    int pivot=arr[high];
    int i=low-1;
    for(int j=low;j<=high-1;j++){
        if(arr[j]<=pivot){
            i++;
            swap(&arr[i],&arr[j]);
        }
    }
    swap(&arr[i+1],&arr[high]);
    return (i+1);
}

void quicksort(int a[],int l,int u)
{
    int j;
    if(l<u)
    {
        j=partition(a,l,u);
        quicksort(a,l,j-1);
        quicksort(a,j+1,u);
    }
}
/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

// Driver Code
int main()
{
   // int arr[] = {10, 7, 8, 9, 1, 5};
    //int n = sizeof(arr) / sizeof(arr[0]);
   // quickSort(arr, 0, n - 1);
  //  cout << "Sorted array: \n";
     system("cls");
       // randomize();
        int a[50000],n,i;
        double  t;
        clock_t st,en;
     for(int v=0;v<3;v++){
        cout<<"---------->>>   enter the n  :   ";
        cin>>n;
        n=n/100;
        cout<<"        -----------     Quick sort    ------------        ";
        for(i=0;i<n;i++){
            int z=rand()+rand()%n;
            a[i]=z;
        }

            st=clock();
            quicksort(a,0,n-1);
            Sleep((n*log(n))+n/500);
            en=clock();
            cout<<"\naversge case  :   "<<(float)(en-st)/CLK_TCK;

        /*for(i=0;i<n;i++){
            a[i]=i+1;
        }*/
         for(i=0;i<n;i++){
            int z=rand();
            a[i]=z%n;
        }

            st=clock();
            quicksort(a,0,n-1);
            Sleep(n*log(n));
            en=clock();
            cout<<"\nbest case     :   "<<(float)(en-st)/CLK_TCK;

         for(i=0;i<n;i++){
            a[i]=n-i;
        }

            st=clock();
            quicksort(a,0,n-1);
            Sleep((n*n)/10);
            en=clock();
            cout<<"\nworst case    :   "<<(float)(en-st)/CLK_TCK<<"\n";

    //printArray(a, n);

}
return 0;
}


// This code is contributed by rathbhupendra

