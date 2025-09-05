#include <iostream>
#include <vector>

using namespace std;

void vectorOperations()
{
  // Initialize vectors in different ways
  std::vector<int> vec1;                   // Empty vector of integers
  std::vector<int> vec2 = {1, 2, 3, 4, 5}; // Initialized with values
  std::vector<int> vec3(5, 10);            // Vector of size 5, initialized to 10 [10, 10, 10, 10, 10]

  // size คือ จำนวน element ที่มีอยู่ใน vector
  // capacity คือ ขนาดพื้นที่จัดเก็บข้อมูลที่ vector สามารถเก็บได้โดยไม่ต้องจัดสรรหน่วยความจำใหม่
  // ถ้าเพิ่ม element เกิน capacity vector จะทำการจัดสรรหน่วยความจำใหม่โดยอัตโนมัติ

  // Adding elements
  vec1.push_back(6); // Adds an element to the end
  for (int i = 0; i < vec1.size(); i++)
  {
    cout << vec1[i] << " "; // Accessing elements using array indexing
  }
  cout << endl;

  int firstElement = vec2[0];     // Accessing first element
  int secondElement = vec2.at(1); // Accessing second element with bounds checking
  cout << "First element: " << firstElement << endl;
  cout << "Second element: " << secondElement << endl;

  // Modifying elements
  vec2[0] = 10;    // Change first element to 10
  vec2.at(1) = 20; // Change second element to 20 with bounds checking
  cout << "Modified vec2: ";
  for (int i = 0; i < vec2.size(); i++)
  {
    cout << vec2[i] << " ";
  }
  cout << endl;

  // Removing elements
  vec2.pop_back(); // Removes the last element
  cout << "After pop_back, vec2: ";
  for (int i = 0; i < vec2.size(); i++)
  {
    cout << vec2[i] << " ";
  }
  cout << endl;

  // Size and capacity
  size_t numElements = vec2.size();  // Get number of elements
  size_t capacity = vec2.capacity(); // Get current capacity

  cout << "Number of elements in vec2: " << numElements << endl;
  cout << "Capacity of vec2: " << capacity << endl;

  // Check if vector is empty
  bool isEmpty = vec1.empty(); // Return true if the vector is empty
  cout << "Is vec1 empty? " << (isEmpty ? "Yes" : "No") << endl;

  // Clear all elements
  vec2.clear(); // Removes all elements from the vector

  // Iterators
  auto it = vec2.begin(); // Iterator to the beginning
  vec2.insert(it, 15);    // Insert 15 at the beginning
  cout << "After inserting 15 at the beginning, vec2: ";
  for (auto iter = vec2.begin(); iter != vec2.end(); ++iter)
  {
    cout << *iter << " "; // Dereferencing iterator to access elements
  }
  cout << endl;

  vec2.erase(it); // Erase the first element
  cout << "After erasing the first element, vec2: ";
  for (auto iter = vec2.begin(); iter != vec2.end(); ++iter)
  {
    cout << *iter << " "; // Dereferencing iterator to access elements
  }
  cout << endl;

  // Resize / Reserve
  vec3.resize(10); // Resize vec3 to contain 10 elements
  cout << "After resizing, vec3: ";
  for (int i = 0; i < vec3.size(); i++)
  {
    cout << vec3[i] << " "; // Accessing elements using array indexing
  }
  cout << endl;

  cout << "Size of vec3: " << vec3.size() << endl;
  cout << "Capacity of vec3: " << vec3.capacity() << endl;

  vec1.reserve(100); // Reserve space for at least 100 elements
  cout << "Size of vec1 after reserve: " << vec1.size() << endl;
  cout << "Capacity of vec1 after reserve: " << vec1.capacity() << endl;

  // Accessing the first and last elements
  int first = vec2.front(); // Access the first element
  int last = vec2.back();   // Access the last element

  cout << "First element of vec2: " << first << endl;
  cout << "Last element of vec2: " << last << endl;

  std::vector<int> vec4;
  cout << "Size of vec4: " << vec4.size() << " Capacity of vec4: " << vec4.capacity() << endl;
  vec4.push_back(1);
  cout << "Size of vec4: " << vec4.size() << " Capacity of vec4: " << vec4.capacity() << endl;
  vec4.push_back(2);
  cout << "Size of vec4: " << vec4.size() << " Capacity of vec4: " << vec4.capacity() << endl;
  vec4.push_back(3);
  cout << "Size of vec4: " << vec4.size() << " Capacity of vec4: " << vec4.capacity() << endl;

  std::vector<int> vec5(2, 5); // Vector of size 2, initialized to 5 [5, 5]
  cout << "Size of vec5: " << vec5.size() << " Capacity of vec5: " << vec5.capacity() << endl;
  vec5.push_back(10);
  cout << "Size of vec5: " << vec5.size() << " Capacity of vec5: " << vec5.capacity() << endl;
  vec5.push_back(15);
  cout << "Size of vec5: " << vec5.size() << " Capacity of vec5: " << vec5.capacity() << endl;
  vec5.push_back(20);
  cout << "Size of vec5: " << vec5.size() << " Capacity of vec5: " << vec5.capacity() << endl;

  vec5.reserve(20); // Reserve space for at least 20 elements
  cout << "Size of vec5 after reserve: " << vec5.size() << " Capacity of vec5 after reserve: " << vec5.capacity() << endl;
}

// Function to add elements to the vector starting from its current size
void addElements(vector<int> &vec, int numElementsToAdd)
{
  int initialSize = vec.size();

  vec.resize(initialSize + numElementsToAdd);

  int *ptr = vec.data() + initialSize;

  for (int i = 0; i < numElementsToAdd; ++i)
  {
    *(ptr + i) = initialSize + i; // Example value: start from the initial size
  }
}

// Function to print the elements of the vector
void printVector(const vector<int> &vec)
{
  for (int i = 0; i < vec.size(); ++i)
  {
    cout << vec[i] << " ";
  }
  cout << endl;
}

void vectorAndPointer()
{
  cout << "==================================================================" << endl;
  std::vector<int> vec = {1, 2, 3};
  int *ptr = vec.data(); // Get pointer to the underlying array
  ptr[0] = 10;           // Modify the first element through the pointer

  // Iterator initialization, similar to obtaining a pointer to the first element
  vector<int>::iterator it = vec.begin(); // Point to the first element

  cout << "First element using pointer: " << ptr[0] << endl; // Should print 10
  cout << "First element using iterator: " << *it << endl;   // Should

  // using iterators in a loop
  cout << "Elements in vec using iterator: ";
  for (vector<int>::iterator iter = vec.begin(); iter != vec.end(); ++iter)
  {
    cout << *iter << " "; // Dereferencing iterator to access elements
  }
  cout << endl;

  // using iterators to insert elements at a specific position
  it = vec.begin() + 2; // point to the third element
  vec.insert(it, 15);   // Insert '15' before the third element

  cout << "Elements in vec using iterator: ";
  for (vector<int>::iterator iter = vec.begin(); iter != vec.end(); ++iter)
  {
    cout << *iter << " "; // Dereferencing iterator to access elements
  }
  cout << endl;

  // using iterators to erase elements
  it = vec.begin(); // reset iterator to the first element
  vec.erase(it);    // Erase the first element

  cout << "Elements in vec after erasing first element: ";
  for (int elem : vec)
  {
    cout << elem << " "; // Using range-based for loop to access elements
  }
  cout << endl;

  vector<int> myVector;

  for (int i = 0; i < 5; ++i)
  {
    myVector.push_back(i); // Add elements to the vector
  }

  cout << "original vector: ";
  printVector(myVector);

  addElements(myVector, 5); // Add 5 more elements starting from current size

  cout << "after adding elements: ";
  printVector(myVector);
  cout << "==================================================================" << endl;
}

int main()
{
  // Create a vector of integers
  vector<int> vec;

  // Add some elements to the vector
  vec.push_back(10); // [] -> [10]
  vec.push_back(20); // [10] -> [10, 20]
  vec.push_back(30); // [10, 20] -> [10, 20, 30]

  // Access and print elements using pointer arithmetic
  for (int i = 0; i < vec.size(); i++)
  {
    cout << vec[i] << " "; // Using array indexing
  }
  cout << endl;

  // Remove the last element
  vec.pop_back(); // [10, 20, 30] -> [10, 20]

  // Access an element by index
  cout << "Element at index 1: " << vec[1] << endl;

  // Get the size of the vector
  cout << "Size of vector: " << vec.size() << endl;

  vectorOperations();
  vectorAndPointer();
  return 0;
}
