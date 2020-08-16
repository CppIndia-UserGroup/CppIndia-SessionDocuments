#include <iostream>
using namespace std;

class test {
public:

	test() {
		cout << "Default: Test object created " << endl;
		NoIdea = -1;
		ptrNoIdea = nullptr;
	}
	
	test(int num) : NoIdea(num) {
        cout << "Parameterized: Test object created " << endl;
		ptrNoIdea = new int;
		*ptrNoIdea = num + 1;
		// cout << "Test object created \t" << NoIdea << "\t" << *ptrNoIdea << endl;
	}
	
	test(const test& obj) {
        cout<<"copy-constructor"<<endl;
		NoIdea = obj.NoIdea * 2;
		ptrNoIdea = new int;
		*ptrNoIdea = *obj.ptrNoIdea;
		// cout << "Test object created through copy-constructor\t" << NoIdea << "\t" << *ptrNoIdea << endl;
	}	
	
    test& operator=(const test& obj) {
        cout<<"assingment operator"<<endl;
		this->NoIdea = obj.NoIdea;
		this->ptrNoIdea = new int;
		*(this->ptrNoIdea) = *obj.ptrNoIdea;
		// cout << "Test object created through assingment operator.\t" << NoIdea << "\t" << *ptrNoIdea << endl;
		return *this;
	}
    //******************************************************
    // test(test&& obj) = delete;   //move-constructor


	test(test&& obj) noexcept {	//C.66: Make move operations noexcept       

        cout<<"move-constructor"<<endl;
		//If i don't use move() here, NoIdea = obj.NoIdea will not be moved, it will be copied.
		// because inside this function obj is lvalue.
		NoIdea = std::move(obj.NoIdea);		//We can do this in an initializer list. but so simplicity I am writing here.
        // NoIdea is an int so moving it will not give any performance benifit but it is good to have as if we cahange the type of NoIdea, 
        // we will not have to change here.

		ptrNoIdea = std::move(obj.ptrNoIdea);
		obj.ptrNoIdea = nullptr;	//If we miss to do this, it may break the application
		//we can use std::exchange(obj.ptrNoIdea, nullptr).
		//It replaces the value of obj with new_value and returns the old value of obj.
		//Ref: https://en.cppreference.com/w/cpp/utility/exchange
		
		obj.NoIdea = 0;	//this is opetional to set to default.

		//==>> go to main function.

		// cout << "Test object created through move-constructor\t" << NoIdea << "\t" << *ptrNoIdea << endl;
		//cout<<ptrNoIdea<<"\t"<<obj.ptrNoIdea<<endl;
	}

    test& operator=(test&& obj) noexcept {	//C.66: Make move operations noexcept
        cout<<"Move assingment operator"<<endl;
		delete this->ptrNoIdea;

		this->NoIdea = std::move(obj.NoIdea);
		this->ptrNoIdea = std::move(obj.ptrNoIdea);	//you can use std::exchange() also
		obj.ptrNoIdea = nullptr;
		obj.NoIdea = 0;	//optional
		//==>> go to main function.
		// cout << "Test object created through Move assingment operator.\t" << this->NoIdea << "\t" << *this->ptrNoIdea << endl;
		return *this;
	}

    //******************************************************
    void print(){
        cout << "Print NoIdea: " << NoIdea <<"\t" << ptrNoIdea << endl;
    }

	int NoIdea;
	int* ptrNoIdea;
};

test createTestObj(test a) {
    cout<<"createTestObj"<<endl;
	return a;
}

int main()
{
    test obj1 = createTestObj(test(30));
    obj1.print();
    test obj3 = obj1;
    test obj4(obj1);
    obj4.print();

    test obj5 = std::move(obj4);
    obj4.print();

    cout<<"=================\n\n"<<endl;
    //Move assingment operator
    test obj6;
    obj6 = createTestObj(test(80));
    obj6.print();
    test obj7;
    obj7 = std::move(obj6);
    obj7.print();
    obj6.print();
    cout<<"================="<<endl;
    return 0;
}