/**
 * @file kth_from_tail.cpp
 * @brief This program finds the K-th element from the end of a singly linked list.
 * 
 * The algorithm implemented uses the two-pointer (fast-slow) technique to achieve this
 * in a single traversal of the list, making it efficient with O(n) time complexity.
 */

#include <iostream>

/**
 * @brief Definition of a node in a singly linked list.
 */
struct Node {
    int data;       ///< Data value stored in the node
    Node* next;     ///< Pointer to the next node in the list
};

/**
 * @brief Inserts a new node at the end of the linked list.
 * 
 * @param head Pointer to the pointer of the head of the list.
 * @param value The data value to be added to the new node.
 */
void insert(Node** head, int value) {
    // Create a new node
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = nullptr;

    // If the list is empty, the new node becomes the head
    if (*head == nullptr) {
        *head = newNode;
    } else {
        // Traverse to the end of the list
        Node* temp = *head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        // Add the new node at the end
        temp->next = newNode;
    }
}

/**
 * @brief Finds the K-th element from the end of the list.
 * 
 * The algorithm uses two pointers: fast and slow. The fast pointer is advanced by K nodes first,
 * and then both pointers move one step at a time. When the fast pointer reaches the end, 
 * the slow pointer is at the K-th node from the end.
 * 
 * @param head Pointer to the head of the list.
 * @param k The position from the end to be found (1-based index).
 * @return The data value of the K-th node from the end. If the list is shorter than K, returns -1.
 */
int findKthFromTail(Node* head, int k) {
    // Initialize two pointers, both starting at the head
    Node* fast = head;
    Node* slow = head;

    // Move the 'fast' pointer k steps ahead
    for (int i = 0; i < k; i++) {
        if (fast == nullptr) {
            // If k is larger than the number of nodes, return -1
            return -1;
        }
        fast = fast->next;
    }

    // Move both pointers one step at a time
    while (fast != nullptr) {
        fast = fast->next;
        slow = slow->next;
    }

    // At this point, 'slow' is pointing at the K-th node from the end
    return slow->data;
}

/**
 * @brief Main function to test the findKthFromTail function.
 */
int main() {
    // Create an empty linked list
    Node* head = nullptr;

    // Insert some elements into the list
    insert(&head, 10);
    insert(&head, 20);
    insert(&head, 30);
    insert(&head, 40);
    insert(&head, 50);

    // Find the 2nd element from the tail (should be 40)
    int k = 2;
    int result = findKthFromTail(head, k);

    if (result != -1) {
        std::cout << "The " << k << "-th element from the tail is: " << result << std::endl;
    } else {
        std::cout << "The list is shorter than " << k << " elements." << std::endl;
    }

    return 0;
}
