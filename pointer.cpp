#include <iostream>

using namespace std;

void foo();
void pointerAndOperator();
void operatorInPointer();
void pointerAndArray();
void pointerAndFunction();
void increment(int *value);
void addNumbers(int a, int b);
void addNumbers2(int &a, int &b);
int *createArray(int size);
void greeting();
void square(int n);
void doubleNumber(int n);
void processArray(int *array, int size, void (*callback)(int));

int main()
{
  foo();
  pointerAndOperator();
  operatorInPointer();
  pointerAndArray();
  pointerAndFunction();
  return 0;
}

void foo()
{

  int number = 10;
  int *ptrNum = &number;

  cout << *ptrNum << endl;

  *ptrNum = 20;
  cout << number << endl;
}

void pointerAndOperator()
{
  int var = 10;
  int *ptr = &var; // Pointer to an integer variable
  cout << "Value of var: " << var << endl;
  cout << "Address of var: " << &var << endl;
  cout << "Value of ptr: " << ptr << endl;
  cout << "Value pointed to by ptr: " << *ptr << endl;

  int **ptrToPtr = &ptr; // Pointer to a pointer
  cout << "Value of ptrToPtr: " << ptrToPtr << endl;
  cout << "Value pointed to by ptrToPtr: " << *ptrToPtr << endl;
  cout << "Value pointed to by the pointer pointed to by ptrToPtr: " << **ptrToPtr << endl;

  int arr[5] = {1, 2, 3, 4, 5};
  int *arrPtr = arr; // Pointer to the first element of the array
  cout << "Array elements using pointer arithmetic:" << endl;
  for (int i = 0; i < 5; i++)
  {
    cout << *(arrPtr + i) << " ";
  }
  cout << endl;
}

void myFunction(int a)
{
  // Function implementation
}
void (*functionPtr)(int) = myFunction; // Pointer to a function

void operatorInPointer()
{
  int var = 10;
  int *ptr = &var; // & address-of operator ใช้สำหรับรับ memory address จากตัวแปร

  *ptr = 20; // * dereference operator ใช้สำหรับเข้าถึงค่าหรือแก้ไขค่าที่อยู่ใน memory address นั้น

  // Pointer arithmetic operators
  int arr[5] = {1, 2, 3, 4, 5};
  int *arrPtr = arr; // Pointer to the first element of the array

  // addition, increment ชี้ไปยัง address ถัดไป
  arrPtr + 1; // Points to the next memory location of the type arrPtr is pointing to
  cout << *arrPtr << endl;
  arrPtr++; // Move the pointer to the next memory location
  cout << *arrPtr << endl;

  // subtraction, decrement ถอยไปยัง address ก่อนหน้า
  arrPtr - 1; // Points to the previous memory location of the type ptr is pointing to
  cout << *arrPtr << endl;
  arrPtr--; // Move the pointer to the previous memory location
  cout << *arrPtr << endl;

  // comparison operators (==, !=, <, >, <=, >=) ใช้เปรียบเทียบ address ที่อยุ่ใน pointer
  if (arrPtr < (arr + 5))
  {
    cout << "arrPtr is less than the address of arr[5]" << endl;
  }

  // assignment operator (=) ใช้สำหรับกำหนดค่า address ให้กับ pointer เพื่อใช้สำหรับ copy address จากตัวแปรหนึ่งไปยังอีกตัวแปรหนึ่ง
  int anotherVar = 30;
  int *ptr1 = &anotherVar; // ptr1 now points to anotherVar
  int *ptr2 = ptr1;        // ptr2 now also points to anotherVar

  // nullptr (C++11 and later) ใช้สำหรับกำหนด pointer ให้ชี้ไปที่ address ว่าง
  int *nullPtr = nullptr; // nullPtr is a null pointer

  // arrow operator (->) ใช้สำหรับเข้าถึงสมาชิกของโครงสร้างหรือคลาสผ่าน pointer
  struct MyStruct
  {
    int member;
  };
  MyStruct *structPtr = new MyStruct();
  structPtr->member = 42; // Accessing member using arrow operator
  cout << "Member value: " << structPtr->member << endl;

  delete structPtr; // delete คือ operator ใช้สำหรับคืนหน่วยความจำที่ถูกจัดสรรด้วย new
}

void pointerAndArray()
{
  int arr[5] = {1, 2, 3, 4, 5};
  int *ptr = arr;       // Pointer to the first element of the array
  cout << *ptr << endl; // Outputs 1

  // loop array using pointer
  int length = sizeof(arr) / sizeof(arr[0]); // Calculate the length of the array

  cout << "Array elements: ";
  for (int i = 0; i < length; ++i)
  {
    cout << *(ptr + i) << " "; // Accessing array elements using pointer arithmetic
  }
  cout << endl;

  for (int i = 0; i < length; ++i)
  {
    cout << i << ": " << *(ptr + i) << endl; // Accessing array elements using pointer as an array
  }
  cout << endl;

  // sizeof ใช้สำหรับหาขนาดของตัวแปรที่ใช้ในหน่วยความจำ (ออกมาเป็นหน่วย byte)
  // sizeof(arr) จะได้ขนาดของ array ทั้งหมด (5 * 4 = 20 bytes)
  // sizeof(arr[0]) จะได้ขนาดของ element แรกของ array (4 bytes)
  // ดังนั้น length = sizeof(arr) / sizeof(arr[0]) จะได้จำนวน element ใน array (20 / 4 = 5)

  // subtraction
  // การลบ pointer สองตัวที่ชี้ไปยัง element เดียวกันของ array จะได้ผลลัพธ์เป็นจำนวน element ที่อยู่ระหว่าง pointer สองตัวนั้น
  int arr2[] = {10, 20, 30, 40, 50};
  int *startPtr = &arr2[1]; // Pointer to the second element (20)
  int *endPtr = &arr2[4];   // Pointer to the last element (50)

  int distance = endPtr - startPtr;                          // distance will be 3 (number of elements between the two pointers)
  cout << "Distance between pointers: " << distance << endl; // Outputs 3

  int arr3[] = {10, 20, 30, 40, 50};
  int *p = &arr[4]; // Pointer to the last element (50)

  cout << "Traversing backwards: ";
  for (int i = 4; i >= 0; --i)
  {
    cout << *p << " "; // Accessing array elements in reverse order
    p--;               // Move the pointer to the previous memory location
  }

  cout << endl;
}

void pointerAndFunction()
{
  // function taking pointer as parameter
  // function สามารถรับ pointer เป็น parameter ได้ ทำให้สามารถแก้ไขค่าของตัวแปรที่ถูกส่งเข้ามาได้โดยตรง
  int a = 5;
  cout << "Value of a before increment: " << a << endl; // Outputs 5
  increment(&a);                                        // ส่ง address ของ a ไปยังฟังก์ชัน
  cout << "Value of a after increment: " << a << endl;  // Outputs 6

  // passing by value
  int num1 = 10, num2 = 20;
  addNumbers(num1, num2);
  cout << num1 << endl; // Outputs 10, num1 ไม่ได้ถูกแก้ไข
  cout << num2 << endl; // Outputs 20, num2 ไม่ได้ถูกแก้ไข

  // passing by reference
  // C++ มีการส่ง parameter แบบ passing by reference โดยใช้ & ในการประกาศ
  // แต่ในที่นี้เราจะใช้ pointer แทนการส่งแบบ reference
  addNumbers2(num1, num2);
  cout << num1 << endl; // Outputs 30, num1 ถูกแก้ไข
  cout << num2 << endl; // Outputs 20, num2 ไม่ได้ถูกแก้ไข

  // function returning pointer
  // ฟังก์ชันสามารถคืนค่าเป็น pointer ได้
  int size = 5;
  int *myArray = createArray(size);

  cout << "Array elements from createArray function: ";
  for (int i = 0; i < size; i++)
  {
    cout << myArray[i] << " "; // Accessing array elements
  }
  cout << endl;

  delete[] myArray; // Free the dynamically allocated memory to avoid memory leaks

  // function pointer
  // Function pointer คือตัวแปรชนิดพิเศษที่สามารถเก็บ address ของฟังก์ชันได้
  // ประโยชน์คือทำให้สามารถเรียกใช้ฟังก์ชันได้แบบไดนามิก
  // หรือจะส่งฟังก์ชันเป็น parameter ให้กับฟังก์ชันอื่นก็ได้
  // หรือจะเก็บฟังก์ชันหลายๆ ตัวใน array แล้วเลือกเรียกใช้ก็ได้
  void (*funcPtr)() = greeting; // ประกาศ function pointer และกำหนดให้ชี้ไปที่ฟังก์ชัน greeting
  (*funcPtr)();                 // เรียกใช้ฟังก์ชันผ่าน function pointer

  int myArray2[] = {1, 2, 3, 4, 5};
  int size2 = sizeof(myArray2) / sizeof(myArray2[0]);

  cout << "Squaring array elements: ";
  processArray(myArray2, size2, square); // Passing the square function as a callback

  cout << "Doubling array elements: ";
  processArray(myArray2, size2, doubleNumber); // Passing the doubleNumber function as a callback
}

void increment(int *value)
{
  (*value)++; // Increment the value at the address pointed to by value
}

void addNumbers(int a, int b)
{
  a = a + b;
}

void addNumbers2(int &a, int &b)
{
  a = a + b;
}

int *createArray(int size)
{
  int *arr = new int[size]; // Dynamically allocate an array of integers

  // Initialize the array
  for (int i = 0; i < size; i++)
  {
    arr[i] = i * 1; // Initialize with some values
  }

  return arr; // Return the pointer to the dynamically allocated array
}

void greeting()
{
  cout << "Hello, World!" << endl;
}

// Callback function that squares a number
void square(int n) { cout << n * n << " "; }

// Callback function that doubles a number
void doubleNumber(int n) { cout << n * 2 << " "; }

// Function that takes an array, its size, and a callback function as parameters
// It applies the callback function to each element of the array
void processArray(int *array, int size, void (*callback)(int))
{
  for (int i = 0; i < size; i++)
  {
    callback(array[i]); // Call the callback function for each element
  }
  cout << endl;
}