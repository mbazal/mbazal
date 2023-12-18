
/*
#include <iostream>
using std::cin;
using std::cout;
using std::endl;
#include <getopt.h> // to parse long arguments.
#include <string>
using std::string;

/* doubly linked list node:
struct node {
    string data;
    node* prev;
    node* next;
    node(string s="", node* p=NULL, node* n=NULL) : data(s),prev(p),next(n) {}
};

void sortList(node* head) {
  bool swapped;
  node* ptr1;
  node* lptr = nullptr;

  
  if (head == nullptr) {
    return;
  }

  do {
    swapped = false;
    ptr1 = head;

    
    while (ptr1->next != lptr) {
      if (ptr1->data > ptr1->next->data) {
        std::swap(ptr1->data, ptr1->next->data);
        swapped = true;
      }
      ptr1 = ptr1->next;
    }
    lptr = ptr1;
  } while (swapped);
}

void reverse1(node*& head)
{
    node* current = head;
    node* temp;
    while (current != nullptr)
    {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        head = current;
        current = current->prev;
    }
}

void removeDup(node*& head)
{
    node* current = head;
    while (current != nullptr)
    {
        node* runner = current;
        while (runner->next != nullptr)
        {
            if (runner->next->data == current->data)
            {
                node* temp = runner->next;
                runner->next = runner->next->next;
                if (runner->next != nullptr)
                {
                    runner->next->prev = runner;
                }
                delete temp;
            }
            else
            {
                runner = runner->next;
            }
        }
        current = current->next;
    }
}

int main(int argc, char *argv[]) {
    /* define long options /
    static int unique=0, reverse=0;
    static struct option long_opts[] = {
        {"unique",   no_argument,       &unique,   'u'},
        {"reverse",  no_argument,       &reverse,  'r'},
        {0,0,0,0} // this denotes the end of our options.
    };
    /* process options /
    char c; /* holds an option /
    int opt_index = 0;
    while ((c = getopt_long(argc, argv, "ur", long_opts, &opt_index)) != -1) {
        switch (c) {
            case 'u':
                unique = 1;
                break;
            case 'r':
                reverse = 1;
                break;
            case '?': /* this will catch unknown options. */
                return 1;
        }
    }
    /* NOTE: at this point, variables 'reverse' and 'unique' have been set
     * according to the command line.  /
    /* TODO: finish writing this.  Maybe use while(getline(cin,line)) or
     * similar to read all the lines from stdin. /

    node* head = nullptr;
    node* current = nullptr;
    std::string line;
    while (std::getline(std::cin, line)) {
    // Allocate memory for a new node
    node* newnode = new node;
    newnode->data = line;
    newnode->next = nullptr;
    newnode->prev = current;

    // Add the new node to the end of the list
    if (current) {
      current->next = newnode;
    }
    current = newnode;

    // Set the head of the list if it is not set yet
    if (!head) {
      head = current;
    }
  }

  // Sort the list
  sortList(head);

  

  // Output the sorted list using cout
  node* ptr = head;
  
  if(reverse) reverse1(ptr);
    if(unique) removeDup(ptr);

  while (ptr != nullptr) {
    std::cout << ptr->data << std::endl;
    ptr = ptr->next;
  }

    return 0;
}
*/


     #include <iostream>
     #include <sstream>
     #include <iomanip>

     // Node structure for the linked list
     struct Node {
         int data;
         Node* next;

         // Constructor
         Node(int val) : data(val), next(nullptr) {}
     };

     // Function to insert a new node into the sorted linked list
     void insertNode(Node*& head, int val) {
         Node* newNode = new Node(val);

         // If the list is empty or the new node should be inserted at the beginning
         if (!head || val < head->data) {
             newNode->next = head;
             head = newNode;
         } else {
             // Traverse the list to find the insertion point
             Node* current = head;
             while (current->next && current->next->data < val) {
                 current = current->next;
             }

             // Insert the new node after the current node
             newNode->next = current->next;
             current->next = newNode;
         }
     }

     // Function to print the linked list
     void printList(Node* head, bool reverseOrder) {
         if (!head) {
             std::cout << "List is empty." << std::endl;
             return;
         }

         Node* current = head;

         // Print in normal or reverse order based on the flag
         if (reverseOrder) {
             while (current) {
                 std::cout << current->data << " ";
                 current = current->next;
             }
         } else {
             while (current) {
                 std::cout << current->data << " ";
                 current = current->next;
             }
         }

         std::cout << std::endl;
     }

     int main() {
         Node* head = nullptr;
         std::string line;

         // Read lines from stdin until exhausted
         while (std::getline(std::cin, line)) {
             std::istringstream iss(line);
             int value;
             if (iss >> value) {
                 // Insert the value into the sorted linked list
                 insertNode(head, value);
             } else {
                 std::cerr << "Invalid input: " << line << std::endl;
                 break;
             }
         }

         // Print the sorted linked list in ascending order
         std::cout << "Sorted Linked List (Ascending Order): ";
         printList(head, false);

         // Optionally, print the list in descending order
         // std::cout << "Sorted Linked List (Descending Order): ";
         // printList(head, true);

         // Clean up the allocated memory
         Node* current = head;
         while (current) {
             Node* temp = current;
             current = current->next;
             delete temp;
         }

         return 0;
     }

