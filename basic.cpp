#include<iostream>

using namespace std;

int main() {
    int age;

    cout << "Please enter your age: ";
    cin >> age;

    cout << "You are " << age << " years old.\n";

    int newAge;

    cout << "Please enter your age again: ";
    cin >> newAge;

    age = newAge;

    cout << "You are " << age << " years old.\n";

    char favorite;
    cout << "What's your favorite character: ";
    cin >> favorite;
    cout << "Your favorite character is " << favorite << endl;

    return 0;
}
