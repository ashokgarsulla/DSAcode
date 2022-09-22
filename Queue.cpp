#include <bits/stdc++.h> 
using namespace std;


void printVector(vector<long long> A) {
    for(auto i: A) cout<<i<<" ";
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
// 5.First negative integer in every window of size K:https:
// 3.Reverse first K element of Queue: https:
// 4.First Non-Repeating character in stream:https:
// 5.Circular tour: https:
// 6.K Queue in Single Array:https:
// 7.Sum of min & max elements of all subarray of size K: https:

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
 
int main() {
	
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
    queue<int> result = rev(q1);
    cout<<"\nqueue after reversal front "<<result.front();
    
    cout<<"\nFirst negative Number ";
    long long int N = 10;
    long long int arr[N]= {1,3,-3,5,5,-4,-5,2,5,7};
    long long int Window_size = 3;
    vector<long long> negative =  printFirstNegativeInteger(arr,N,Window_size);
    printVector(negative);
    
	return 0;
}