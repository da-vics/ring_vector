#include <iostream>
#include "ring.h"
///#include<typeinfo>

using namespace std;

/*
template<class T>
auto show(T a)  -> decltype(a)
{
	return a + a;

}*/


int main()
{
	ring<int> ri(5);
	ri.add(4);
	ri.add(1);
	ri.add(2);
	ri.add(45);

	ring<int>::iterator iterate = ri.begin();

	iterate[2] = 4;

	for (; iterate != ri.end();++iterate) {
		cout << *iterate << endl;
	}


}

