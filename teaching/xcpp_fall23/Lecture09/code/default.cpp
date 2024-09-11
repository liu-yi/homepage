#include<iostream>
using namespace std;

class MyTime
{
public:
    MyTime()
    {
        cout << "this is MyTime()" << endl; 
    }
    MyTime(int n = 0){
        cout << "this is MyTime(int n = 0)" << endl;
    }
};

int main(){
    // MyTime mt;
}