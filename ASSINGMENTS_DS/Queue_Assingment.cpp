// #include <iostream>
// #include <vector>

// class PriorityQueue {
// private:
//     std::vector<int> arr;

//     // Helper function to maintain the heap property
//     void heapifyUp(int index) {
//         while (index > 0) {
//             int parentIndex = (index - 1) / 2;
//             if (arr[index] > arr[parentIndex]) {
//                 std::swap(arr[index], arr[parentIndex]);
//                 index = parentIndex;
//             } else {
//                 break;
//             }
//         }
//     }

//     // Helper function to maintain the heap property
//     void heapifyDown(int index) {
//         int leftChild = 2 * index + 1;
//         int rightChild = 2 * index + 2;
//         int largest = index;

//         if (leftChild < arr.size() && arr[leftChild] > arr[largest]) {
//             largest = leftChild;
//         }

//         if (rightChild < arr.size() && arr[rightChild] > arr[largest]) {
//             largest = rightChild;
//         }

//         if (largest != index) {
//             std::swap(arr[index], arr[largest]);
//             heapifyDown(largest);
//         }
//     }

// public:
//     // Function to insert an element into the priority queue
//     void push(int value) {
//         arr.push_back(value);
//         heapifyUp(arr.size() - 1);
//     }

//     // Function to remove and return the maximum element from the priority queue
//     int pop() {
//         if (arr.empty()) {
//             throw std::out_of_range("Priority queue is empty");
//         }

//         int maxValue = arr[0];
//         arr[0] = arr.back();
//         arr.pop_back();
//         heapifyDown(0);

//         return maxValue;
//     }

//     // Function to check if the priority queue is empty
//     bool empty() const {
//         return arr.empty();
//     }

//     // Function to get the size of the priority queue
//     size_t size() const {
//         return arr.size();
//     }
// };

// int main() {
//     PriorityQueue pq;

//     // Insert elements into the priority queue
//     pq.push(10);
//     pq.push(5);
//     pq.push(20);
//     pq.push(15);

//     // Print and remove elements from the priority queue
//     while (!pq.empty()) {
//         std::cout << pq.pop() << " ";
//     }

//     return 0;
// }

#include <iostream>

// Node structure for the binary tree
struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

// Function to insert a node into a binary tree
void insertBinaryTree(TreeNode*& root, int value) {
    if (root == nullptr) {
        root = new TreeNode(value);
        return;
    }

    // Simple insertion: alternating between left and right subtrees
    if (root->left == nullptr) {
        insertBinaryTree(root->left, value);
    } else if (root->right == nullptr) {
        insertBinaryTree(root->right, value);
    } else {
        // If both left and right are already occupied, go to the left subtree
        insertBinaryTree(root->left, value);
    }
}

// Function to insert a node into a binary search tree (BST)
void insertBST(TreeNode*& root, int value) {
    if (root == nullptr) {
        root = new TreeNode(value);
        return;
    }

    // Insert into the left subtree if the value is smaller
    if (value < root->data) {
        insertBST(root->left, value);
    }
    // Insert into the right subtree if the value is larger
    else {
        insertBST(root->right, value);
    }
}

// Function to traverse a binary tree in-order
void inOrderTraversal(TreeNode* root) {
    if (root != nullptr) {
        inOrderTraversal(root->left);
        std::cout << root->data << " ";
        inOrderTraversal(root->right);
    }
}

int main() {
    TreeNode* binaryTreeRoot = nullptr;
    TreeNode* bstRoot = nullptr;
    int A[]={14,16,17,29,34,36,10};
    for(int i=0;i<sizeof(A)/sizeof(A[0]);i++){
        insertBinaryTree(binaryTreeRoot, A[i]);
    };


    int B[]={10,16,26,45,6,7};
    for(int i=0;i<sizeof(A)/sizeof(A[0]);i++){
        insertBST(bstRoot, B[i]);
    };

    // Traverse and print the elements of the binary tree in-order
    std::cout << "Binary Tree In-Order Traversal: ";
    inOrderTraversal(binaryTreeRoot);
    std::cout << std::endl;

    // Traverse and print the elements of the BST in-order
    std::cout << "BST In-Order Traversal: ";
    inOrderTraversal(bstRoot);
    std::cout << std::endl;

    return 0;
}



