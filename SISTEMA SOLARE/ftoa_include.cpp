#include <iostream>
#include <cstdlib>
#include "ftoa.cpp"

using namespace std;

int main(int argc, char** argv) {
	
    float a = 12.70400;
    int cifre = 5;
    string str;
    
    str = ftoa(a);

    cout << "Numero convertito: " << str << endl;	
		
	return 0;	
}

