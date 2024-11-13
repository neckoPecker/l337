#include <iostream>

template <typename T>
class LinkedList {
  
  struct Node {
    T value;
    Node* nextNode;
  };

private:
  Node* current;
  int count = 0;

public:
  void push(T value) {
    // Make a new node
    Node* node = new Node();
    // Add the value and the current address (null if this is the first node)
    node->value = value;
    node->nextNode = current;
    // Set the current node to be equal to the new node. Information is not
    // lost since the new node already points to the "old current" node
    current = node;

    count++;
  }

  void remove() {
    // Need to hold on to the next node while we delete the current node.
    // Important for freeing up memory
    Node* tmp = current->nextNode;
    delete(current);
    // Now, we get tmp to give that next node back to current
    current = tmp;

    count--;
  }

  T peek() {
    return current->value;
  }

  T pop() {
    T value = this->peek();
    this->remove();
    return value;
  }

  int size() {
    return this->count;
  }
};

int main(void) {
  // A simple example
  LinkedList<char> ll;

  // Push in the alphabet from A to Z
  std::cout << "The alphabets!!!" << std::endl;
  for (int i = 0; i < 26; i++) {
    ll.push(65 + i);
    
    std::cout << char(65 + i) << " ";
    if ((i+1) % 5 == 0) {
      std::cout << std::endl;
    }
  }

  std::cout << "The size of the linked list is: " << ll.size() << std::endl;

  //  Now pop all the values
  std::cout << std::endl << "The alphabets!!! (reversed)" << std::endl;
  for (int i = 0; i < 26; i++) {
    std::cout << ll.pop() << " ";
    if ((i+1) % 5 == 0) {
      std::cout << std::endl;
    }
  }

  // confirm that the linked list is empty
  std::cout << "The size of the linked list is: " << ll.size() << std::endl;

  return 0;
}
