int partition(int arr[],int left,int right){
    int key = arr[left];
    int i = left;
    for (int j = left+1;j<=right;j++){
        if (arr[j]<key){
            i++;
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[i],arr[left]);
    return i;

}
// 3 2 1 5 4  pivot= 1 
// i = 2 swap(arr[i],arr[low]);

void quicksort(int arr[],int left,int right){
    if (left<right){
        int index = partition(arr,left,right);
        quicksort(arr,left,index-1);
        quicksort(arr,index+1,right);
    }
    

}
