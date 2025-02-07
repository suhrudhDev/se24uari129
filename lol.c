#include <stdio.h>
// mentioning the functions for the compiler
int  Binarysearch(int* d,int lp,int up,int target);
void BucketSort(int* arr,int lp,int up);
void selectsort(int arr[100][100],int lp, int up,int p[100]);
void insertsort(int arr[100][100],int lp, int up,int p[100]);

int main(){
// Taking the length of the array
int len;
scanf("%d",&len);
int length = len - 1 ;

//creating array of given length and scanning for inputs
int arr[len];
for (int i =0;i<len;i++){
 scanf("%d",&arr[i]);    

}

//scaning for the target to be checked
int check;
scanf("%d",&check);

//sorting the elements into buckets
BucketSort(arr,0,length);

//printing the sorted array 
for (int i =0;i<len;i++){

 printf("%d ",arr[i]);   

}

printf("\n");

// using binary search for all elements
Binarysearch(arr,0,length,check);

}

void BucketSort(int* arr,int lp,int up) {

// for the largest element and smallest element respectively
int check = 0;
int check2 = 0;

// for largest element
for(int i = 0;i<=up;i++){

if(arr[i]>check){

check = arr[i];

}

}

check2 = check;

// for smallest element
for(int i = 0;i<=up;i++){

if(arr[i]<check){

check2 = arr[i];

}

}

      // calculating the range
       int range = (check-check2/(up+1));
       
       //assigning the lower limit and upper limit of the range
       int l = lp;
       int q = range;
       
       // calculating no of buckets required
       int bucket = (check-check2)/range + 1;
       
       //creating the required no of buckets
       int a[up][up];
       
       // to track the no of elements in ecah bucket
       int h[100];
       
       // storing the array elements in the resp buckets
       for(int i = 0;i<=bucket;i++){
       int o = 0;
       for(int j = 0;j<=up;j++){
       if(arr[j]>=l && arr[j]< q){
       
       a[i][o] = arr[j];
       o++;
       
       }
       
       }
       // updating the tracker and changing the limits for next bucket
        h[i] = o;
        l += range;
        q += range;
       }
       
      
      // sorting half elements using selective sort and half using insertsort 
      selectsort(a,0,bucket/2,h);
      insertsort(a,(bucket/2)+1,bucket,h);
      
      //reassigning the values in array after sort
      int g = 0;
      for(int i = 0;i<=bucket;i++){
       for(int j = 0;j<h[i];j++){
      arr[g] = a[i][j];
      g++;
       
       }
   
       }
       
       }
       
void selectsort(int arr[100][100],int lp, int up,int p[100]){

//going through all the rows
for(int k = lp;k<=up;k++){

 //going through all the columns and sorting them
    for(int i = 0;i<=p[k];i++){

     for(int j = i+1;j<=p[k];j++){

         if(arr[k][i]>arr[k][j]){

          int temp = arr[k][i];

          arr[k][i] = arr[k][j];

          arr[k][j] = temp;      

         }
     }

    }

    
}
    

}


 void insertsort(int arr[100][100],int lp, int up,int p[100]){
//going through all the rows
for(int k = lp;k<=up;k++){
 //going through all the columns and sorting them
    for(int i = lp;i<=p[k];i++){

      for(int j = i;j>0;j--){

          

        if(arr[k][j]<arr[k][j-1]){

          int temp = arr[k][j];
          arr[k][j] = arr[k][j-1];
          arr[k][j-1] = temp;


        }



      }

    }


}

 }


int Binarysearch(int* d,int lp,int up,int target){

// The return function only used here to give back a value to main as the output is printed here itself 
 int mid = lp + (up-lp)/2;
    if(lp>up){

     printf("Not Found");
     return -1;   

    }   

if(d[mid]==target){

printf("found %d at index %d\n",target,mid);

return mid;

}

else if(d[mid]>target){

    return Binarysearch(d,lp,mid-1,target);

    }

else{ return Binarysearch(d,mid+1,up,target);

}


}