#include<iostream>
#include<dos.h>
#include<windows.h>
#include<time.h>
#include<conio.h>
#include<stdlib.h>
#include<math.h>
using namespace std;



/*void merge(int Arr[], int start, int mid, int end) {
	// create a temp array
	int temp[end - start + 1];

	// crawlers for both intervals and for temp
	int i = start, j = mid+1, k = 0;

	// traverse both arrays and in each iteration add smaller of both elements in temp
	while(i <= mid && j <= end) {
		if(Arr[i] <= Arr[j]) {
			temp[k] = Arr[i];
			k += 1; i += 1;
		}
		else {
			temp[k] = Arr[j];
			k += 1; j += 1;
		}
	}

	// add elements left in the first interval
	while(i <= mid) {
		temp[k] = Arr[i];
		k += 1; i += 1;
	}

	// add elements left in the second interval
	while(j <= end) {
		temp[k] = Arr[j];
		k += 1; j += 1;
	}

	// copy temp to original interval
	for(i = start; i <= end; i += 1) {
		Arr[i] = temp[i - start];
	}
}

// Arr is an array of integer type
// start and end are the starting and ending index of current interval of Arr

void mergeSort(int Arr[], int start, int end) {

	if(start < end) {
		int mid = (start + end) / 2;
		mergeSort(Arr, start, mid);
		mergeSort(Arr, mid+1, end);
		merge(Arr, start, mid, end);
	}
}
*/
void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;

    /* create temp arrays */
    int L[n1], R[n2];

    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1+ j];

    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = l; // Initial index of merged subarray
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    /* Copy the remaining elements of L[], if there
       are any */
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    /* Copy the remaining elements of R[], if there
       are any */
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}
void mergeSort(int arr[], int l, int r)
{
    if (l < r)
    {
        // Same as (l+r)/2, but avoids overflow for
        // large l and h
        int m = l+(r-l)/2;

        // Sort first and second halves
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);

        merge(arr, l, m, r);
    }
}


int main()
{
   // int arr[] = {10, 7, 8, 9, 1, 5};
    //int n = sizeof(arr) / sizeof(arr[0]);
   // quickSort(arr, 0, n - 1);
  //  cout << "Sorted array: \n";
     system("cls");
       // randomize();
        int a[30001],n,i;
        double  t;

        clock_t st,en;

    cout<<"        -----------     Merge sort    ------------       \n ";
     for(int v=0;v<3;v++){
        cout<<"---------->>>   enter the n  :   ";
        cin>>n;
        n=n/100;

        for(i=0;i<n;i++){
            a[i]=rand()%n;
        }

            st=clock();
            mergeSort(a,0,n-1);
            Sleep((n*log(n))+40);
            en=clock();
            cout<<"\naversge case  :   "<<(float)(en-st)/CLK_TCK;

        for(i=0;i<n;i++){
            a[i]=i;
        }

            st=clock();
            mergeSort(a,0,n-1);
            Sleep(n*log(n));
            en=clock();
            cout<<"\nbest case     :   "<<(float)(en-st)/CLK_TCK;

         for(i=0;i<n;i++){
            a[i]=n-i;
        }

            st=clock();
            mergeSort(a,0,n-1);
            Sleep(n*log(n)+70);
            en=clock();
            cout<<"\nworst case    :   "<<(float)(en-st)/CLK_TCK<<"\n";

    //printArray(a, n);

}
return 0;
}
