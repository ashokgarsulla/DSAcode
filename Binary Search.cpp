#include <bits/stdc++.h>
using namespace std;

// Iterative
int BinarySearch(int arr[],int n, int x){
    int start,end,mid;
    start = 0;
    end = n-1;
    while(start<=end){
        mid = start + (end-start)/2;
        if(arr[mid] == x)
        return mid;
        else if(arr[mid]<x)
        start = mid + 1;
        else 
        end = mid - 1;
    }
    return -1;
    
}

// Recursive 
int binarySearchFRecursive(int arr[], int l, int r, int x)
{
    if (r >= l) {
        int mid = l + (r - l) / 2;
        if (arr[mid] == x)
            return mid;
        if (arr[mid] > x)
            return binarySearchFRecursive(arr, l, mid - 1, x);
        return binarySearchFRecursive(arr, mid + 1, r, x);
    }
    return -1;
}

// Recursive Reverse Order Array || Binary Search
int binarySearchReverseOrderRecursive(int arr[], int l, int r, int x)
{
    if (r >= l) {
        int mid = l + (r - l) / 2;
        if (arr[mid] == x)
            return mid;
        if (arr[mid] > x)
            return binarySearchReverseOrderRecursive(arr, mid + 1, r , x);
        return binarySearchReverseOrderRecursive(arr, l, mid - 1, x);
    }
    return -1;
}
int BinarySearchOnReverseSortedArray(int arr[],int n, int x) {
    int start,end,mid;
    start = 0;
    end = n-1;
    while(start<=end){
        mid = start + (end - start) / 2;
        if(arr[mid] == x)
        return mid;
        else if(arr[mid] < x)
        end = mid - 1;
        else
        start = mid + 1;
    }
    return mid;
}

//Order Not known || Order Agnostic Search
int OrderNotKnownSearch(int arr[], int n, int x){
    if(n > 0) {
        if(arr[0] < arr[n-1])
        return BinarySearch(arr,n,x);
        else
        return BinarySearchOnReverseSortedArray(arr,n,x);
        
    }
    
}

// First Occurence
int FirstOccurence(int arr[], int n, int x){
    int start,end,mid,res;
    start = 0;
    end  = n - 1;
    res = -1;
    while(start <= end){
        mid = start + (end - start) / 2;
        if(arr[mid] == x) {
            res = mid;
            end = mid - 1;
        }
        else if(arr[mid] < x)
        start = mid + 1;
        else 
        end = mid - 1;
    }
    return res;
}

// Last Occurence
int LastOccurence(int arr[], int n, int x){
    int start,end,mid,res;
    start = 0;
    end  = n - 1;
    res = -1;
    while(start <= end){
        mid = start + (end - start) / 2;
        if(arr[mid] == x) {
            res = mid;
            start = mid + 1;
        }
        else if(arr[mid] < x)
        start = mid + 1;
        else 
        end = mid - 1;
    }
    return res;
}
// First and Last Occurence
vector<int> FirstAndLastOccurence(int arr[], int n, int x) {
    vector<int> res;
    res.push_back(FirstOccurence(arr,n,x));
    res.push_back(LastOccurence(arr,n,x));
    return res;
}

// Count of an element
int CountOfAnElement(int arr[], int n, int x) {
    int first = FirstOccurence(arr,n,x);
    int last = LastOccurence(arr,n,x);
    return last - first + 1;
    
}

// Number of Times array Rotated ||  minimum element in sorted rotated array
int NoOfTimesArrayRotated(int arr[], int n) {
    int start,end,mid,next,prev;
    start = 0;
    end = n - 1;
    while(start <= end) {
        mid = start + (end -  start) / 2;
        next = (mid + 1 ) % n;
        prev = (mid - 1 + n ) % n;
        if (arr[mid] <= arr[prev] && arr[mid] <= arr[next])
			return mid;
		else if (arr[mid] <= arr[end])
			end = mid - 1;
		else if (arr[mid] >= arr[start])
			start = mid + 1;
    }
}

// Find element in Sorted Rotated array
int FindElementInSortedRotatedArray(int arr[],int n, int x) {
    int start,end,mid,next,prev,index;
    start = 0;
    end = n - 1;
    while(start <= end) {
        mid = start + (end -  start) / 2;
        next = (mid + 1 ) % n;
        prev = (mid - 1 + n ) % n;
        if (arr[mid] <= arr[prev] && arr[mid] <= arr[next]){
            index = mid;
            int res = binarySearchFRecursive(arr,0,index-1,x);
            if(res > -1)\
            return res;
            else 
            return binarySearchFRecursive(arr,index+1,n-1,x);
        }
		else if (arr[mid] <= arr[end])
			end = mid - 1;
		else if (arr[mid] >= arr[start])
			start = mid + 1;
    }
    
}

// Searching element in nearly sorted array arr[i] may be in arr[i-1],arr[i] and arr[i+1] || Modified Binaryu Search
int SearchElementInNearlySortedArray(int arr[],int n, int x) {
    int start,end,mid;
    start = 0;
    end = n - 1;
    while(start <= end) {
        mid = start + (end - start) / 2;
        if(x == arr[mid])
        return mid;
        if(mid - 1 >= start && x == arr[mid - 1])
        return mid - 1;
        if(mid + 1 <= end && x == arr[mid + 1])
        return mid + 1;
        
        else if(arr[mid] < x)
        start = mid + 2;
        else
        end = mid - 2;
    }
}

// Floor of an element in sorted array ||  Modified Binary Search
int FloorOfAnElementInSortedArray(int arr[], int n, int x) {
    int start,end,mid,result;
    start = 0;
    end = n - 1;
    while(start <= end) {
        mid = start + (end - start) / 2;
        if(arr[mid] == x)
        return arr[mid];
        else if(arr[mid] < x){
            result = arr[mid];
            start = mid + 1;
        }
        else
        end = mid - 1;
    }
    return result;
    
}

// Ceil of an element in sorted array ||  Modified Binary Search
int CeilOfAnElementInSortedArray(int arr[], int n, int x) {
    int start,end,mid,result;
    start = 0;
    end = n - 1;
    while(start <= end) {
        mid = start + (end - start) / 2;
        if(arr[mid] == x)
        return arr[mid];
        else if(arr[mid] < x)
            start = mid + 1;
        else{
            result = arr[mid];
            end = mid - 1;
        }
    }
    return result;
    
}

// Next Alphabate in sorted character array ||  Modified Binary Search
int NextAlphabateInSortedCharacterArray(char arr[], int n, char ch) {
    int start,end,mid;
    char result;
    start = 0;
    end = n - 1;
    while(start <= end) {
        mid = start + (end - start) / 2;
        if(arr[mid] == ch)
        start = mid + 1;
        else if(arr[mid] < ch)
            start = mid + 1;
        else{
            result = arr[mid];
            end = mid - 1;
        }
    }
    return result;
    
}

// Find position of element in infinte sorted array || Modified Binary Search
int PositionInInfiniteSortedArray(int arr[],int x) {
    int start,end,mid;
    start = 0;
    end = 1;
    while(x > arr[end]){
        start = end;
        end = end * 2;
    }
    return binarySearchFRecursive(arr,start,end,x);
    
}

// Index of First 1 in Binary infinte sorted Array
int IndexOfFirst1BinarySortedArray(int arr[], int x) {
    int start,end,mid,res;
    start = 0;
    end = 1;
    while(x > arr[end]) {
        start = end;
        end = end * 2;
    }
    while(start <= end) {
        mid = start + (end  - start) / 2;
        if(arr[mid] == x){
            res = mid;
            end = mid - 1;
        }
        else if (arr[mid] < x)
        start = mid + 1;
        else 
        end = mid - 1;
    }
    return res;
}

// Minimum difference with key in sorted Array
int MinimumDifferenceInSortedArray(int arr[], int n, int x) {
    
    int start,end,mid;
    start = 0;
    end = n - 1;
    while(start <= end) {
        mid = start + (end - start) / 2;
        if(arr[mid] == x)
        return arr[mid];
        else if(arr[mid] > x)
        end = mid - 1;
        else 
        start = mid + 1;
    }
    if(abs(arr[start] - x) > abs(arr[end] - x))
    return arr[end];
    else
    return arr[start];
}

// Peak element on Unsorted Array || Binary Search on Answer Based problem
int PeakElementInUnsortedArray(int arr[],int n) {
    int start,end,mid;
    start = 0;
    end = n - 1;
    while(start <= end) {
        mid = start + (end - start ) / 2;
        if(mid > 0 && mid < n - 1) {
            if(arr[mid] > arr[mid-1] && arr[mid] > arr[mid+1])
            return mid;
            else if(arr[mid] < arr[mid - 1])
            end = mid - 1;
            else 
            start = mid + 1;
        }
        else if(mid == 0) {
            if(arr[mid] < arr[mid+1])
            return mid + 1;
            else
            return mid ;
        }
        else if (mid = n - 1) {
            if(arr[mid] < arr[mid - 1])
            return mid - 1;
            else 
            return mid ;
        }
    }
}

// Peak element on Bitonic Array || Binary Search on Answer Based problem
// Biotonic mean no duplicate      1,2,3,4,5,6,7,(8),4,3,2,1 ====> 8 peak than decrease
int PeakElementInBitonicArray(int arr[],int n) {
    int start,end,mid;
    start = 0;
    end = n - 1;
    while(start <= end) {
        mid = start + (end - start ) / 2;
        if(mid > 0 && mid < n - 1) {
            if(arr[mid] > arr[mid-1] && arr[mid] > arr[mid+1])
            return mid;
            else if(arr[mid] < arr[mid - 1])
            end = mid - 1;
            else 
            start = mid + 1;
        }
        else if(mid == 0) {
            if(arr[mid] < arr[mid+1])
            return mid + 1;
            else
            return mid ;
        }
        else if (mid = n - 1) {
            if(arr[mid] < arr[mid - 1])
            return mid - 1;
            else 
            return mid ;
        }
    }
}

// Search an element on Bitonic element
int SearchOnBitonicArray(int arr[], int n, int key) {
    int peakIndex;
    peakIndex = PeakElementInBitonicArray(arr,n);
    if(binarySearchFRecursive(arr, 0, peakIndex, key ) != -1)
    return binarySearchFRecursive(arr, 0, peakIndex, key );
    else if (binarySearchReverseOrderRecursive(arr,peakIndex + 1, n-1, key) != -1)
    return binarySearchReverseOrderRecursive(arr,peakIndex + 1, n-1, key);
    else return -1;
    
}

// Search in row and column wise sorted matrix
bool SearchInRowColSortedArray(int mat[4][4],int N, int M, int key) {
    int i,j;
    pair<int,int> matPosition;
    matPosition = make_pair(-1,-1);
    
    i = 0;
    j = M-1;
    while(i >= 0 && i < N && j >= 0 && j < M) {
        if(mat[i][j] == key ){
            matPosition = make_pair(i,j);
            cout<<"position :"<<"["<<matPosition.first<<"]"<<"["<<matPosition.second<<"]"<<endl;
            return true;
        }
        
        else if(mat[i][j] > key)
        j--;
        else if(mat[i][j] < key)
        i++;
    }
    cout<<"position :"<<"["<<matPosition.first<<"]"<<"["<<matPosition.second<<"]"<<endl;
    return false;
}

// Allocate minimum number of pages
int maxElement(int arr[], int n) {
        
        return *max_element(arr , arr + n);
    }
    
    int sumOfElements(int arr[], int n){
        int sum = 0;
        for(int i = 0 ;i < n; i++)
        sum = sum + arr[i];
        return sum;
    }
    
bool isValid(int arr[],int n, int NStudent , int max) {
    int student = 1;
    int sum = 0;
    
    for(int i = 0; i < n; i++) {
        sum = sum + arr[i];
        if(sum > max){
            student++;
            sum = arr[i];
        }
        if(student > NStudent){
            return false;
            
        }
        
    }
    
    return true;
}

int MinimumNoOfPageAllocation(int A[], int N, int M) 
    {
        //code here
        int start,end,mid,res;
        start = maxElement(A,N);
        end = sumOfElements(A,N);
        res = -1;
        if(M > N)
        return -1;
        while(start <= end) {
            mid = start + (end - start) / 2;
            if(isValid(A,N,M,mid) == true) {
                res = mid;
                end = mid - 1;
                
            }
            else 
            start = mid + 1;
        }
        return start;
        
    }


int main() {
    // int arr[] = {1,2,3,4,5,6,7,8,9,10,12,15,19,22,24,34,36,39,40,46,53,65,89,98}; // Sorted Array
    // int arr[] = {1,2,4,5,6,7,10,10,10,10,10,10,12,13}; // ASC order
    // int arr[]  = {10,9,8,7,6,4,3,2,1}; // DESC order
    // int arr[] = {12,13,14,15,16,17,18,19,20,21,2,3,4,5,6,7}; // sorted rotated array
    // int arr[] = {2,3,5,7,6,9,8,10,12,11}; // Nearly Sorted Array
    // {2,3,5,6,7,8,9,10,11,12}
    // {2,3,5,7,6,9,8,10,11,12}
    // int arr[] = {2,4,5,7,8,9,12,13,14,15,16,22,35,45,23,34,56,33,34,35,36}; // array for peak elemet problem Binary Search on Answer
    // int arr[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15}; // array for peak elemet problem Binary Search on Answer ASC
    // int arr[] = {9,10,8,7,6,5,4,3,2,1}; // array for peak elemet problem Binary Search on Answer DESC
    // int arr[] = {1,3,5,7,8,9,10,6,4,3,2,1}; // Biotonic Array
    int arr[] = {15,17,20}; // Minimum page allocate
    int n = sizeof(arr) / sizeof(int);
    char charr[] = {'a','b','c','e','g','h','k','m','n','o'};
    int chn = sizeof(charr) / sizeof(char);
    int infinteArr [] = {2, 5, 7, 9, 10, 12, 15, 16, 18, 20, 24, 28, 32, 35,36,37,38,39,41,45,47,48,51,53,55,140};
    int infinteBinArr [] = {0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
    // int infinteArr [] =  {3, 5, 7, 9, 10, 90, 100, 130,140, 160, 170};
    int MAT[4][4] = { { 10, 20, 30, 40 },
                      { 15, 25, 35, 45 },
                      { 27, 29, 37, 48 },
                      { 32, 33, 39, 50 } }; // 2D square Matrix
    // cout<<"Binary Search "<<BinarySearch(arr,n,12);
    // cout<<"Recursive Approach "<<binarySearchFRecursive(arr,0,n-1,7);
    // cout<<"Recursive Approach on reverse order array "<<binarySearchReverseOrderRecursive(arr,0,n-1,7);
    // cout<<"Binary search on reverse sorted array "<<BinarySearchOnReverseSortedArray(arr,n,6);
    // cout<<"Order not known search "<<OrderNotKnownSearch(arr,n,6);
    // cout<<"First Occurence "<< FirstOccurence(arr,n,10);
    // cout<<"Last Occurence "<< LastOccurence(arr,n,10);
    // cout<<"Count of an Element "<<CountOfAnElement(arr,n,10);
    // cout<<"No. of Time of Rotated "<<NoOfTimesArrayRotated(arr,n);
    // cout<<"Find element in sorted Rotated array "<<FindElementInSortedRotatedArray(arr,n,5);
    // cout<<"Find element in Nearly sorted array "<<SearchElementInNearlySortedArray(arr,n,10);
    // cout<<"Find Floor of an element in Sorted Array "<<FloorOfAnElementInSortedArray(arr,n,14);
    // cout<<"Find Ceil of an element in Sorted Array "<<CeilOfAnElementInSortedArray(arr,n,20);
    // cout<<"Find Next Alphabate "<<char(NextAlphabateInSortedCharacterArray(charr,chn,'c'));
    // cout<<"Find position of element in infinte sorted Array "<<PositionInInfiniteSortedArray(infinteArr,140);
    // cout<<"Find index of First 1 in Binary infinte sorted Array "<<IndexOfFirst1BinarySortedArray(infinteBinArr,1);
    // cout<<"Find minimum difference in Sorted array "<<MinimumDifferenceInSortedArray(arr,n,42);
    // cout<<"Peak element in Unsoted Array "<<PeakElementInUnsortedArray(arr,n);
    // cout<<"Peak element in Biotonic Array "<<PeakElementInBitonicArray(arr,n);
    // cout<<"Search element on Bitonic Array "<<SearchOnBitonicArray(arr,n,23);
    // cout<<"Search in row and column wise sorted matrix "<<SearchInRowColSortedArray(MAT,4,4,29);
    cout<<"Minimum No. of Page Allocation : " <<MinimumNoOfPageAllocation(arr,n,2);
    
    
    return 0;
}
    