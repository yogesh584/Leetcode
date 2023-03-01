class Solution {
public:
    void merge(vector<int>& nums,int start,int end){
        int mid  = start + (end - start)/2;
        int size1 = mid - start + 1;
        int size2 = end - mid;
        int* first = new int [size1];
        int* second = new int [size2];
        
        // filling the first array.
        int numsMainIndex = start;
        for(int i = 0;i < size1;i++){
            first[i] = nums[numsMainIndex++];
        }
        
        // filling the second array.
        numsMainIndex = mid + 1;
        for(int i = 0;i < size2;i++){
            second[i] = nums[numsMainIndex++];
        }
        
        // merge two sorted arrays.
        int index1 = 0;
        int index2 = 0;
        numsMainIndex = start;
        
        while(index1 < size1 && index2 < size2){
            if(first[index1] < second[index2]){
                nums[numsMainIndex++] = first[index1++];
            }
            else{
                nums[numsMainIndex++] = second[index2++];
            }
        }
        
        while(index1 < size1){
            nums[numsMainIndex++] = first[index1++];
        }
        
        while(index2 < size2){
            nums[numsMainIndex++] = second[index2++];
        }
        
        delete[] first;
        delete[] second;
    }
    
    void mergeSort(vector<int> & nums,int start,int end){
        if(start >= end){
            return ;
        }
        
        int mid = start + (end - start)/2;
        mergeSort(nums,start,mid);
        mergeSort(nums,mid+1,end);
        
        merge(nums,start,end);
    }
    
    vector<int> sortArray(vector<int>& nums) {
        mergeSort(nums,0,nums.size() - 1);
        return nums;
    }
};