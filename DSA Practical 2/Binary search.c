#include<stdio.h>
int BS(int arr[], int l, int r, int target);
int main(){
int arr[] = {10, 20, 30, 40, 50};
int n = sizeof(arr) / sizeof(arr[0]);
int target;
printf("Enter the target element: ");
scanf("%d", &target);
int Result = BS(arr, 0, n-1, target);
if(Result != -1){
printf("Target Found");
}
else{
printf("Target is not Found");
}
}
int BS(int arr[], int l, int r, int target){
if(l > r)
return -1;
int mid = l + ((r-l)/2);
if(arr[mid] == target){
return mid;}
else if (arr[mid] > target){
return BS(arr, l , mid - 1, target);}
else if(arr[mid] < target){
return BS(arr, mid + 1, r, target);}
}
