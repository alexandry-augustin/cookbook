#include <cassert>
#include <cstring>
#include <iostream>

int main()
{
    {
	    int n=4;
	    //int arr[n]; //nok (static memory allocation)
    }
    {
        int a[4]={0,1,2,3};
        memset(a, 0, sizeof(int)*4); //C style memory filling
        assert(a[3]==0);
    }
    {
        int n=4;
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

        assert(arr_[0] == 5);
        assert(*(arr_+1) == 10);

        delete[] arr_;
    }
    {
        int (*a)[20] = new int[5][20];
    }
	return 0;
}
