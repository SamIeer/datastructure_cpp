// #include <iostream>
// using namespace std;

// //SOLUTION 1 : heap sort
// void Insert(int A[],int n){
//     int i=n,temp;
//     temp=A[i];
//     while(i>1 && temp>A[i/2]){
//         A[i]=A[i/2];
//         i=i/2;
//     }
//     A[i]=temp;
// }

// int Delete(int A[],int n){
//     int i,j,x,temp,val;
//     val=A[1];
//     x=A[n];
//     A[1]=A[n];
//     A[n]=val;
//     i=1;j=i*2;
//     while(j<=n-1){
//         if(j<n-1 && A[j+1]>A[j])
//            j=j+1;
//         if(A[i]<A[j]){
//             temp=A[i];
//             A[i]=A[j];
//             A[j]=temp;
//             i=j;
//             j=2*j;
//         }
//         else
//         break;
//     }
//     return val;
// }

// int main(){
//     int H[]={0,14,15,5,20,30,8,40};
//     int i;
//     for(i=2;i<=7;i++)
//      Insert(H,i);

//     for(i=7;i>1;i--)
//         Delete(H,i);

//     for(i=1;i<=7;i++)
//         cout<<H[i]<<" ";
//     cout<<endl;
//     return 0;
// }


#include <iostream>
#include <vector>
using namespace std;

//SOLUTION 2 : HEAP using priotiry queue
class PriorityQueue {
private:
    vector<int> heap;

    // Helper function to maintain heap property by performing heapify-up operation
    void heapifyUp(int index) {
        int parent = (index - 1) / 2;
        while (index > 0 && heap[index] > heap[parent]) {
            swap(heap[index], heap[parent]);
            index = parent;
            parent = (index - 1) / 2;
        }
    }

    // Helper function to maintain heap property by performing heapify-down operation
    void heapifyDown(int index) {
        int leftChild = 2 * index + 1;
        int rightChild = 2 * index + 2;
        int largest = index;

        if (leftChild < heap.size() && heap[leftChild] > heap[largest])
            largest = leftChild;
        if (rightChild < heap.size() && heap[rightChild] > heap[largest])
            largest = rightChild;

        if (largest != index) {
            swap(heap[index], heap[largest]);
            heapifyDown(largest);
        }
    }

public:
    // Function to insert an element into the priority queue
    void enqueue(int value) {
        heap.push_back(value);
        heapifyUp(heap.size() - 1);
    }

    // Function to extract the maximum element from the priority queue
    int dequeue() {
        if (heap.empty()) {
            cerr << "Error: Priority queue is empty." << endl;
            return -1;
        }
        int maxElement = heap[0];
        heap[0] = heap.back();
        heap.pop_back();
        heapifyDown(0);
        return maxElement;
    }

    // Function to check if the priority queue is empty
    bool isEmpty() {
        return heap.empty();
    }
};

int main() {
    PriorityQueue pq;

    // Insert elements into the priority queue
    pq.enqueue(10);
    pq.enqueue(20);
    pq.enqueue(15);
    pq.enqueue(25);
    pq.enqueue(5);

    // Extract maximum elements from the priority queue
    cout << "Dequeued elements: ";
    while (!pq.isEmpty()) {
        cout << pq.dequeue() << " ";
    }
    cout << endl;

    return 0;
}

