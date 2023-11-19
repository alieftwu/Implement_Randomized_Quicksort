#include <stdio.h>
#include <stdlib.h>

//Function to partition the array

int PARTITION(int a[], int p, int r)
{
    int temp;
    int temp2;
    int x = a[r];
    int i = p-1;

    for (int j = p; j <= r - 1; j++)
    {
        if (a[j] <= x)
        {
            i = i+1;
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
    }
    temp2 = a[i+1];
    a[i+1] = a[r];
    a[r] = temp2;
    return i+1;
}
//Randomized partition function
int R_PARTITION(int a[], int p, int r)
{
    int i = p + rand() % (r-p+1);
    int temp;
    temp = a[r];
    a[r] = a[i];
    a[i] = temp;
    return PARTITION(a,p,r);
}
//Recursive function to perform randomized quicksort
void R_QUICKSORT(int a[], int p, int r)
{
    int q;
    if (p<r)
    {
        q=R_PARTITION(a,p,r); //Partitions the array
        R_QUICKSORT(a,p,q-1); //Recursively sort the left subarry
        R_QUICKSORT(a,q+1, r); //Recursively sort the right subarray
    }
}

int main()
{
    int n;
    printf("------RANDOMIZED QUICKSORT ALGORITHM SOLVER------\n");
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    int* a = (int*)malloc(n*sizeof(int)); //Allocates memory
    printf("Enter the elements in the array: \n");

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]); //Inputs the elements of the array based off user input
    }
    int p = 0;
    int r = n -1;
    R_QUICKSORT(a,p,r); //calls randomized quicksort
    printf("Sorted Array: ");

    for(int i =0; i < n; i++)
    {
        printf(" %d", a[i]); //Prints the sorted array
    }
    free(a); //Frees the memory
    return 0;
}