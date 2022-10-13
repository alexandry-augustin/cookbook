#include <cstring>
#include <iostream>

int main()
{
	int n=4;
	//int arr[n]; impossible (static memory allocation)
	int arr[4]={0,1,2,3};
	memset(arr, 0, sizeof(int)*4); //C style memory filling
	std::cout<<arr[3]<<std::endl;

	int* arr_;
	try
	{
		arr_=new int[n]; //dynamic memory allocation
	}
	catch(...)
	{
	}

	arr_[0]=5;
	arr_[1]=10;

	int (*a)[20] = new int[5][20];

	std::cout<<arr_[0]<<std::endl;
	std::cout<<*(arr_+1)<<std::endl;

	delete[] arr_;

	return 0;
}
