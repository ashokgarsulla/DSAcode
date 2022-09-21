#include <bits/stdc++.h>
using namespace std;


//print vector
void PrintVector(vector<long long> v) {
    for(long long i : v)
    cout<<i<<" ";
}
//Next Greater Element || right Greater
vector<long long> NextGreaterElement(int arr[], int n) {
        vector<long long> v;
        stack<long long> s ;
        for(int i = n - 1; i >= 0 ; i--) {
            if(s.size() == 0)
            v.push_back(-1);
            else if(s.size() > 0 && s.top() > arr[i])
            v.push_back(s.top());
            else if(s.size() > 0 && s.top() <= arr[i])
            {
                while(s.empty() == false && s.top() <= arr[i]) {
                    s.pop();
                }
                if(s.empty() == true)
                v.push_back(-1);
                else 
                v.push_back(s.top());
            }
            
            s.push(arr[i]);
            
        }
        reverse(v.begin(), v.end());
        return v;
    }

// Greater Element to Left || Left Greater
vector<long long> GreaterElementToLeft(int arr[], int n) {
        vector<long long> v;
        stack<long long> s ;
        for(int i = 0; i < n ; i++) {
            if(s.size() == 0)
            v.push_back(-1);
            else if(s.size() > 0 && s.top() > arr[i])
            v.push_back(s.top());
            else if(s.size() > 0 && s.top() <= arr[i])
            {
                while(s.empty() == false && s.top() <= arr[i]) {
                    s.pop();
                }
                if(s.empty() == true)
                v.push_back(-1);
                else 
                v.push_back(s.top());
            }
            
            s.push(arr[i]);
            
        }
        return v;
    }

// smaller Element to Left || Left smaller || Nearest left smaller
vector<long long> SmallerElementToLeft(int arr[], int n) {
        vector<long long> v;
        stack<long long> s ;
        for(int i = 0; i < n ; i++) {
            if(s.size() == 0)
            v.push_back(-1);
            else if(s.size() > 0 && s.top() < arr[i])
            v.push_back(s.top());
            else if(s.size() > 0 && s.top() >= arr[i])
            {
                while(s.empty() == false && s.top() >= arr[i]) {
                    s.pop();
                }
                if(s.empty() == true)
                v.push_back(-1);
                else 
                v.push_back(s.top());
            }
            
            s.push(arr[i]);
            
        }
        return v;
    }
    
// smaller Element to right || right smaller || Nearest right smaller
vector<long long> SmallerElementToRight(int arr[], int n) {
        vector<long long> v;
        stack<long long> s ;
        for(int i = n -1 ; i >= 0 ; i--) {
            if(s.size() == 0)
            v.push_back(-1);
            else if(s.size() > 0 && s.top() < arr[i])
            v.push_back(s.top());
            else if(s.size() > 0 && s.top() >= arr[i])
            {
                while(s.empty() == false && s.top() >= arr[i]) {
                    s.pop();
                }
                if(s.empty() == true)
                v.push_back(-1);
                else 
                v.push_back(s.top());
            }
            
            s.push(arr[i]);
            
        }
        reverse(v.begin(), v.end());
        return v;
    }


// Stock Span Problem || Similar to left Greater Problem
vector<long long> StockSapanProblem(int arr[], int n) {
        vector<long long> v;
        stack<pair<long long, int>> s ;
        for(int i = 0; i < n ; i++) {
            if(s.size() == 0)
            v.push_back(-1);
            else if(s.size() > 0 && s.top().first > arr[i])
            v.push_back(s.top().second);
            else if(s.size() > 0 && s.top().first <= arr[i])
            {
                while(s.empty() == false && s.top().first <= arr[i]) {
                    s.pop();
                }
                if(s.empty() == true)
                v.push_back(-1);
                else 
                v.push_back(s.top().second);
            }
            
            s.push({arr[i],i});
            
        }
        
        for(int i = 0; i < n ; i++) {
            v[i] =  i - v[i];
        }
        return v;
    }
    
    
// Maximum Area of Histogram
long long MaximumAreaHistogram(long long arr[], int n)
    {
        vector<long long> v;
        vector<long long> left;
        vector<long long> right;
        vector<long long> width;
        vector<long long> area;
        long long max = 0;
        int leftpseduindex = -1;
        int rightpseduindex = n;
        stack<pair<long long, int>> s ;
        
        
        for(int i = 0; i < n ; i++) {
            if(s.size() == 0)
            left.push_back(-1);
            else if(s.size() > 0 && s.top().first < arr[i])
            left.push_back(s.top().second);
            else if(s.size() > 0 && s.top().first >= arr[i])
            {
                while(s.empty() == false && s.top().first >= arr[i]) {
                    s.pop();
                }
                if(s.empty() == true)
                left.push_back(-1);
                else 
                left.push_back(s.top().second);
            }
            
            s.push({arr[i],i});
            
        }
        
        
        while(!s.empty())
        s.pop();
        
        for(int i = n - 1; i >= 0 ; i--) {
            if(s.size() == 0)
            right.push_back(rightpseduindex);
            else if(s.size() > 0 && s.top().first < arr[i])
            right.push_back(s.top().second);
            else if(s.size() > 0 && s.top().first >= arr[i])
            {
                while(s.empty() == false && s.top().first >= arr[i]) {
                    s.pop();
                }
                if(s.empty() == true)
                right.push_back(rightpseduindex);
                else 
                right.push_back(s.top().second);
            }
            
            s.push({arr[i],i});
            
        }
        
        reverse(right.begin(), right.end());
        
        for (int i = 0; i < n ; i++ ) {
            width.push_back(right[i] - left[i] - 1);
        }
        
        for(int i = 0; i < n ; i++) 
            area.push_back(arr[i] *  width[i]);
            
        max = 0;
        for(int i = 0; i < area.size() ; i++){
            if(n == 1)
            max = area[0];
            else {
                if(max < area[i])
                max = area[i];
            
            }
            
        }
        
        return max;
        
    }


// Maximum Area in Binary Matrix 
long long MaximumAreaInBinaryMatrix(long long mat[4][4], long long R, long long C) {
    long long arr[C];
    long long max ;
    
    for(int j = 0; j < C ; j++ )
        arr[j] = mat[0][j];
     max = MaximumAreaHistogram(arr, C);
    for(int i = 1 ; i < R ; i++) {
        for (int j = 0 ; j < C ; j++) {
            if(mat[i][j] == 0)
            arr[j] = 0;
            else 
            arr[j] = arr[j] + mat[i][j];
        }
        
        max = MaximumAreaHistogram(arr, C);
    }
    
    return max;
}
///////////////////////////////////////////////////////////////////////////////////////////////
// Design min Sract with extra sapace
stack<int> glbl_stack;
stack<int> glbl_ss_stack;

void specialStackPush(int a) {
    glbl_stack.push(a);
    
    if(glbl_ss_stack.size() == 0 || glbl_ss_stack.top() >= a)
    glbl_ss_stack.push(a);
    return ;
}

int specialStackPop() {
    
    if(glbl_stack.size() == 0) 
    return -1;
    
    int ans = glbl_stack.top();
    glbl_stack.pop();
    
    if(ans == glbl_ss_stack.top())
    glbl_ss_stack.pop();
    
    return ans;
}

int specialStackGetMin() {
    if(glbl_ss_stack.size() == 0)
    return -1;
    
    return glbl_ss_stack.top();
    
}
int main() {
    vector<long long> Next_Greater_Element;
	int arr[] = {1,3,6,7,2,10};
	long long llarr[] = {6,2,5,4,5,1,6};
	int lln = sizeof(llarr) / sizeof(long long);
	int n = sizeof(arr) / sizeof(int);
	long long binMAT[4][4] = { { 0, 1, 1, 0 },
                      { 1, 1, 1, 1 },
                      { 1, 1, 0, 1 },
                      { 0, 1, 1, 1 } };
	
	
// 	Next_Greater_Element = NextGreaterElement(arr,n);
	cout<<"\nNext Greater Element "; PrintVector(NextGreaterElement(arr,n));
	cout<<"\nGreater Element to left "; PrintVector(GreaterElementToLeft(arr,n));
	cout<<"\nNearest smaller Element to left "; PrintVector(SmallerElementToLeft(arr,n));
	cout<<"\nNearest smaller Element to right "; PrintVector(SmallerElementToRight(arr,n));
	cout<<"\nStock Span Problem "; PrintVector(StockSapanProblem(arr,n));
	cout<<"\nMaximum Area of Histogram "<<MaximumAreaHistogram(llarr,lln);
	cout<<"\nMaximum Area in Binary Matrix "<<MaximumAreaInBinaryMatrix(binMAT,4,4);
	cout<<"\nSpecial stack extra space push(a)  ";
	specialStackPush(18);
	specialStackPush(25);
	specialStackPush(15);
	specialStackPush(32);
	cout<<"\nSpecial stack extra space pop()  "<<specialStackPop();
	cout<<"\nSpecial stack extra space getmin()  "<<specialStackGetMin();
	specialStackPush(11);
	cout<<"\nSpecial stack extra space pop()  "<<specialStackPop();
	cout<<"\nSpecial stack extra space getmin()  "<<specialStackGetMin();
	
	
	return 0;
}