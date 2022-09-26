#include <bits/stdc++.h> 
using namespace std;

//print vector
void printVector(vector<long long> A) {
    for(auto i: A) cout<<i<<" ";
}

// print queue
void printQueue(queue<int> q) {
    while (!q.empty()) {
            int a = q.front();
            q.pop();
            cout << a << " ";
        }
}

// Print string
void printString(string s) {
    for(int i =0; i < s.length(); i++) cout<<s[i];
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////
// 0.queueSTLTesting
///////////////////////////////////////////////////////////////////////////////////////////////////////////
// STL queue Testing
void queueSTLTesting(){
    queue<int> q;
	
	q.push(1);
	q.push(2);
	q.push(3);
	q.push(4);
	q.push(5);
	
	cout<<"\nsize of queue :"<<q.size();
	cout<<"\nfront :"<<q.front();
	q.pop();
	cout<<"\nsize of queue :"<<q.size();
	cout<<"\nback :"<<q.back();

	if(q.empty()) {
	    cout<<"\nqueue is empty ";
	}
	else {
	    cout<<"\nqueue is not empty ";
	}
}


///////////////////////////////////////////////////////////////////////////////////////////////////////////
// 1.Queue Implemented
///////////////////////////////////////////////////////////////////////////////////////////////////////////

class Queue {
    int *arr;
    int qfront;
    int rear;
    int size;
public:
    Queue() {
        size = 100000;
        arr = new int[size];
        qfront = 0;
        rear = 0;
    }

    /*----------------- Public Functions of Queue -----------------*/

    bool isEmpty() {
        if(qfront == rear) {
            return true;
        } 
        else {
            return false;
        }
    }

    void enqueue(int data) {
        if(rear == size){
            cout<<"Queue is full "<<endl;
        }
        else {
            arr[rear] = data;
            rear++;
        }
    }

    int dequeue() {
        if(qfront == rear){
            return -1;
        }
        else {
            int ans = arr[qfront];
            arr[qfront] = -1;
            qfront++;
            if(qfront == rear) {
                qfront = 0;
                rear = 0;
            }
            return ans;
        }
    }

    int front() {
        if(qfront == rear) {
            return -1;
        }
        else {
            return arr[qfront];
        }
    }
};

///////////////////////////////////////////////////////////////////////////////////////////////////////////
// 2.Circular Queue Implemented
///////////////////////////////////////////////////////////////////////////////////////////////////////////
class CircularQueue{
    int *arr ;
    int front;
    int rear;
    int size;
    public:
    // Initialize your data structure.
    CircularQueue(int n){
        size = n;
        arr = new int[size];
        front = rear = -1;
    }

    // Enqueues 'X' into the queue. Returns true if it gets pushed into the stack, and false otherwise.
    bool cenqueue(int value){
        
        if((front == 0 && rear == size -1) || (rear == (front -1) % (size - 1))) 
           return false;
        else if(front == -1)
           front = rear = 0;
        else if(rear == size -1 && front != 0)
           rear = 0;
        else
           rear++;
        arr[rear] = value;
        
        return true;

    }

    // Dequeues top element from queue. Returns -1 if the stack is empty, otherwise returns the popped element.
    int cdequeue(){
        if(front == -1) {
//             cout<<"Queue is Empty"<<endl;
            return -1;
        } 
        int ans = arr[front];
        arr[front] = -1;
        if (front == rear) // Single element is present
        {
            front = rear = -1;
        }
        else if( front == size -1) 
        {
            front = 0;
        }
        else 
            front++ ;
        return ans;
    }
};

///////////////////////////////////////////////////////////////////////////////////////////////////////////
// 3.Input restricted Queue Implemented
///////////////////////////////////////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////////////////////////////////
// 4.Input restricted Queue Implemented
///////////////////////////////////////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////////////////////////////////
// 5.Doubly Ended Queue STL
///////////////////////////////////////////////////////////////////////////////////////////////////////////

void doublyEndedQueueSTL() {
    deque<int> dq;
    cout<<"\npush : ";
    dq.push_front(12);
    dq.push_back(13);
    dq.push_back(14);
    dq.push_back(15);
    dq.push_back(16);
    cout<<"\nfront : "<<dq.front();
    cout<<"\nback : "<<dq.back();
    dq.push_front(11);
    cout<<"\nfront : "<<dq.front();
    cout<<"\nback : "<<dq.back();
    cout<<"\npop front";
    dq.pop_front();
    cout<<"\nfront : "<<dq.front();
    cout<<"\nback : "<<dq.back();
    cout<<"\npop back";
    dq.pop_back();
    cout<<"\nfront : "<<dq.front();
    cout<<"\nback : "<<dq.back();
    
    
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////
// 6.Doubly Ended Queue Implemented
///////////////////////////////////////////////////////////////////////////////////////////////////////////

class Deque
{
    int *arr;
    int front;
    int rear;
    int size;
public:
    // Initialize your data structure.
    Deque(int n)
    {
        size =n;
        arr = new int[size];
        front = -1;
        rear = -1;
    }

    // Pushes 'X' in the front of the deque. Returns true if it gets pushed into the deque, and false otherwise.
    bool pushFront(int x)
    {
        if(isFull()) 
           return false;
        else if(isEmpty())
           front = rear = 0;
        else if(front == 0 && rear != size - 1 ) // maintain cyclic
           front = size -1;
        else
          front--;
        arr[front] = x;

        return true;
        
        
    }

    // Pushes 'X' in the back of the deque. Returns true if it gets pushed into the deque, and false otherwise.
    bool pushRear(int x)
    {
        if(isFull()) 
           return false;
        else if(isEmpty())
           front = rear = 0;
        else if(rear == size -1 && front != 0)
           rear = 0;
        else
           rear++;
        
        arr[rear] = x;
        return true;
        
    }

    // Pops an element from the front of the deque. Returns -1 if the deque is empty, otherwise returns the popped element.
    int popFront()
    {
        if(isEmpty()) {
            return -1;
        } 
        int ans = arr[front];
        arr[front] = -1;
        if (front == rear) // Single element is present
        {
            front = rear = -1;
        }
        else if( front == size -1) 
        {
            front = 0;
        }
        else 
            front++ ;
        return ans;
    }

    // Pops an element from the back of the deque. Returns -1 if the deque is empty, otherwise returns the popped element.
    int popRear()
    {
        if(isEmpty()) {
            return -1;
        } 
        int ans = arr[rear];
        arr[rear] = -1;
        if (front == rear) // Single element is present
        {
            front = rear = -1;
        }
        else if( rear == 0) {
            rear = size -1;
        }
        else 
            rear-- ;
        return ans;
    }

    // Returns the first element of the deque. If the deque is empty, it returns -1.
    int getFront()
    {
        if(isEmpty()){
            return -1;
        }
        return arr[front];
    }

    // Returns the last element of the deque. If the deque is empty, it returns -1.
    int getRear()
    {
        if(isEmpty()) {
            return -1;
        }
        return arr[rear];
    }

    // Returns true if the deque is empty. Otherwise returns false.
    bool isEmpty()
    {
        if(front == -1 && rear == -1) {
            return true;
        }
        else {
            return false;
        }
        
    }

    // Returns true if the deque is full. Otherwise returns false.
    bool isFull()
    {
        if( (front == 0 && rear == size-1) || (front != 0 && rear == (front-1)%(size-1) ) ) 
            return true;
        else
            return false;
    }
};

// ###########################################################################################################
//                  INTERVIEW QUESTION
// 1.Queue Reversal:
// 2.First negative integer in every window of size K:
// 3.Reverse first K element of Queue: 
// 4.First Non-Repeating character in stream:
// 5.Circular tour: 
// 6.K Queue in Single Array:
// 7.Sum of min & max elements of all subarray of size K:

// ###########################################################################################################
///////////////////////////////////////////////////////////////////////////////////////////////////////////
// 6.Queue Reversal
///////////////////////////////////////////////////////////////////////////////////////////////////////////

queue<int> rev(queue<int> q)
{
    stack<int> s;
    
    while(!q.empty()){
        int x =q.front();
        s.push(x);
        q.pop();
    }
    
    while(!s.empty()) {
        int x = s.top();
        q.push(x);
        s.pop();
    }
    return q;
}



///////////////////////////////////////////////////////////////////////////////////////////////////////////
// 7.First negative integer in every window of size K
///////////////////////////////////////////////////////////////////////////////////////////////////////////

vector<long long> printFirstNegativeInteger(long long int A[],long long int N, long long int K) {
    
    queue<long long int> q;
    vector<long long> ans;
    
    for(int i =0; i < K ;i++) {
        if(A[i] < 0) q.push(i);
    }
    
    if(q.size() > 0) ans.push_back(A[q.front()]);
    else ans.push_back(0);
    
    for(int i =K; i < N ; i++) {
        //remove
        if(!q.empty() && i - q.front() >= K) q.pop();
        // add next
        if(A[i] < 0) q.push(i);
        
        
        // storing answer
        if(q.size() > 0) {
        ans.push_back(A[q.front()]);
        }
        else ans.push_back(0);
        
    }
     return ans;                           
                                                 
                        
                                                 
 }

///////////////////////////////////////////////////////////////////////////////////////////////////////////
// 7.Reverse first k elements of a queue
///////////////////////////////////////////////////////////////////////////////////////////////////////////

queue<int> ReverseFirstKElementofQueue(queue<int> q, int k) {
    stack<int> s;
    for(int i = 0; i < k; i++) {
        int value = q.front();
        s.push(value);
        q.pop();
    }
    
    while(!s.empty()){
        int val = s.top();
        q.push(val);
        s.pop();
    }
    
    for(int i=0 ; i < q.size()-k; i++) {
        int val = q.front();
        q.push(val);
        q.pop();
    }
    
    return q;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////
// 8.First Non-Repeating character in stream
///////////////////////////////////////////////////////////////////////////////////////////////////////////

string FirstNonRepeating(string A){
    unordered_map<char,int> count;
    queue<int> q;
    string ans = "";
    
    for(int i =0 ; i < A.length(); i++) {
        char ch  = A[i];
        //inccrease count
        count[ch]++;
        
        //push in queue
        q.push(ch);
        
        
        while(!q.empty()) {
            
            if(count[q.front()] > 1) {
                q.pop();
            }
            else {
                ans.push_back(q.front());
                break;
            }
        }
        
        if(q.empty()){
            ans.push_back('#');
        }
        
    }
    
    return ans;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////
// 9.Circular tour
///////////////////////////////////////////////////////////////////////////////////////////////////////////

int truckTourCircular(vector<vector<int>> petrolpumps) {
    int petrol_ki_kami = 0;
    int balance = 0;
    int should_start_index = 0;
    // int size = petrolpumps.size();
    // cout<<"==="<<size;
    for(int i =0 ; i < petrolpumps.size(); i++) {
        balance += petrolpumps[i][0] - petrolpumps[i][1];
        
        if(balance < 0) {
            petrol_ki_kami = petrol_ki_kami + balance;
            should_start_index = i + 1;
            balance =0;
        }
    }
     if(petrol_ki_kami + balance >= 0) {
            return should_start_index;
        }
    else {
        return -1;
    }
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////
// 10.K Queue in Single Array
///////////////////////////////////////////////////////////////////////////////////////////////////////////

class kQueue {

    public:
        int n;
        int k;
        int *front;
        int *rear;
        int *arr;
        int freeSpot;
        int *next;

    public:
        kQueue(int n, int k) {
            this -> n = n;
            this -> k = k;
            front = new int[k];
            rear = new int[k];
            for(int i=0; i<k; i++) {
                front[i] = -1;
                rear[i] = -1;
            }

            next = new int[n];
            for(int i=0; i<n; i++) {
                next[i] = i+1;
            }
            next[n-1] = -1;
            arr = new int[n];
            freeSpot = 0;
        }    

        void enqueue(int data, int qn) {

            //overflow
            if( freeSpot == -1) {
                cout << "No Empty space is present" << endl;
                return;
            }

            //find first free index
            int index = freeSpot;

            //update freespot
            freeSpot = next[index];

            //check whther first element
            if(front[qn-1] == -1){
                front[qn-1] = index;
            }
            else{
                //link new element to the prev element
                next[rear[qn-1]] = index;
            }

            //update next
            next[index] = -1;

            //update rear
            rear[qn-1] = index;

            //push element
            arr[index] = data;
        }

        int dequeue(int qn) {
            //underflow 
            if(front[qn-1] == -1)
            {
                cout << "Queue UnderFlow " << endl;
                return -1;
            }

            //find index to pop
            int index = front[qn-1];

            //front ko aage badhao
            front[qn-1] = next[index];

            //freeSlots ko manage karo
            next[index] = freeSpot;
            freeSpot = index;
            return arr[index];
        }

};

///////////////////////////////////////////////////////////////////////////////////////////////////////////
// 10.Sum of min & max elements of all subarray of size K
///////////////////////////////////////////////////////////////////////////////////////////////////////////


int minMaxfromsubArraySizeK(int *arr, int n, int k) {

    deque<int> maxi(k);
    deque<int> mini(k);

    //Addition of first k size window

    for(int i=0; i<k; i++) {

        while(!maxi.empty() && arr[maxi.back()] <= arr[i])
            maxi.pop_back();

        while(!mini.empty() && arr[mini.back()] >= arr[i])
            mini.pop_back();

        maxi.push_back(i);
        mini.push_back(i);
    }
    int ans = 0;

    ans += arr[maxi.front()] + arr[mini.front()];

    //remaining windows ko process karlo
    for(int i=k; i<n; i++) {

        

        //next window

        //removal
        while(!maxi.empty() && i - maxi.front() >=k) {
            maxi.pop_front();
        }

        while(!mini.empty() && i - mini.front() >=k) {
            mini.pop_front();
        }

        //addition

        while(!maxi.empty() && arr[maxi.back()] <= arr[i])
            maxi.pop_back();

        while(!mini.empty() && arr[mini.back()] >= arr[i])
            mini.pop_back();

        maxi.push_back(i);
        mini.push_back(i);    

        ans += arr[maxi.front()] + arr[mini.front()];
    }
    return ans;
}

int main() {
	queue<int> result;
	string answer;
	queueSTLTesting();
	cout<<"Queue Implemented :"<<endl;
    Queue q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    cout<<"\nDeque : "<<q.dequeue();
    cout<<"\nDeque : "<<q.dequeue();
    cout<<"\nDeque : "<<q.dequeue();
    cout<<"\nDeque : "<<q.dequeue();
    cout<<"\nDeque : "<<q.dequeue();
    cout<<"\nCircular queue Implemented";
    CircularQueue cq(5);
    cout<<"\nCenque:"<<cq.cenqueue(1);
    cout<<"\nCenque:"<<cq.cenqueue(2);
    cout<<"\nCenque:"<<cq.cenqueue(3);
    cout<<"\nCenque:"<<cq.cenqueue(4);
    cout<<"\nCenque:"<<cq.cenqueue(5);
    cout<<"\nCenque:"<<cq.cenqueue(6);
    cout<<"\nC deque :"<<cq.cdequeue();
    cout<<"\nC deque :"<<cq.cdequeue();
    cout<<"\nC deque :"<<cq.cdequeue();
    cq.cenqueue(10);
    cout<<"\nC deque :"<<cq.cdequeue();
    cout<<"\nC deque :"<<cq.cdequeue();
    cout<<"\nSTl doubly ended Queue ";
    doublyEndedQueueSTL();
    cout<<"\nDoubly Ended Queue Implemented ";
    Deque dq_impl(5);
    cout<<"\nIs Empty :"<<dq_impl.isEmpty();
    cout<<"\npop rear :"<<dq_impl.popRear();
    cout<<"\npop front :"<<dq_impl.popFront();
    cout<<"\npush front :"<<dq_impl.pushFront(5);
    cout<<"\npush rear :"<<dq_impl.pushRear(6);
    cout<<"\npush rear :"<<dq_impl.pushRear(7);
    cout<<"\npush rear :"<<dq_impl.pushRear(8);
    cout<<"\npush rear :"<<dq_impl.pushRear(9);
    cout<<"\npop front :"<<dq_impl.popFront();
    cout<<"\npop Rear :"<<dq_impl.popRear();
    cout<<"\nget Front :"<<dq_impl.getFront();
    cout<<"\nget Rear :"<<dq_impl.getRear();
    
    cout<<"\nqueue reversal ";
    queue<int> q1;
    q1.push(1);
    q1.push(2);
    q1.push(3);
    q1.push(4);
    q1.push(5);
    q1.push(6);
    q1.push(7);
    cout<<"\nqueue before reversal front "<<q1.front();
    result = rev(q1);
    cout<<"\nqueue after reversal front "<<result.front();
    
    cout<<"\nFirst negative Number ";
    long long int N = 10;
    long long int arr[N]= {1,3,-3,5,5,-4,-5,2,5,7};
    long long int Window_size = 3;
    vector<long long> negative =  printFirstNegativeInteger(arr,N,Window_size);
    printVector(negative);
    
    cout<<"\nReverse of First K element of Queue";
    cout<<"\nBefore reverse: ";
    printQueue(q1);
    result = ReverseFirstKElementofQueue(q1,3);
    cout<<"\nAfetr reverse: ";
    printQueue(result);
    
    cout<<"\nFirst Non-Repeating character in stream: ";
    string u_input_string = "aabccb";
    answer = FirstNonRepeating(u_input_string);
    printString(answer);
    
    cout<<"\nCircular Tour : ";
    vector<vector<int>> petral_distance = {{4,6},{6,5},{7,3},{4,5}};
    cout<<"\nStartinf index should :"<<truckTourCircular(petral_distance);
    
    cout<<"\nKQueue in array"<<endl; 
    kQueue kq(10, 3);
    kq.enqueue(10, 1);
    kq.enqueue(15,1);
    kq.enqueue(20, 2);
    kq.enqueue(25,1);

    cout << kq.dequeue(1) << endl;
    cout << kq.dequeue(2) << endl;
    cout << kq.dequeue(1) << endl;
    cout << kq.dequeue(1) << endl;
    cout << kq.dequeue(1) << endl;
    
    cout<<"\nsum of Min Max from sub Array of Size K : ";
    int minmaxarr[] = {1,3,5,3,5,1,8,7,4,2};
    cout<<minMaxfromsubArraySizeK(minmaxarr,10,5);
    
	return 0;
}