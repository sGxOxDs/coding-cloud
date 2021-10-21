// the exercise for C++ Inheritance and Virtual function

#include <iostream>
#include "pet.h"

using namespace std;

void examinePet(Pet* p){
    cout << "My name is " << p->Name() << " and I make " << p->makeSound() << endl;
}

int main(){
    Pet* marry = new Cat("marry");
    Pet* tom = new Dog("tom");
    examinePet(marry); // output: My name is marry and I make miau
    examinePet(tom); // output: My name is tom and I make won
    return 0;
}

