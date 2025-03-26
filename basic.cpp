#include<iostream>

using namespace std;

int main() {
    int age1;
    int age2;
    int sumAge;

    cout << "Please enter the 1st person age: ";
    cin >> age1;

    cout << "Please enter the 2nd person age: ";
    cin >> age2;

    sumAge = age1 + age2;

    cout << "The sum of age is " << sumAge << endl;

    return 0;
}
