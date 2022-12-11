#include <assert.h>

enum base_00
{
    BASE00_ONE  = 1,
    BASE00_TWO  = 2,
    BASE00_THREE
};

enum base_01
{
    BASE01_ONE   = 1,
    BASE01_THREE = 3,
    BASE01_FOUR
};

enum base_02
{
    BASE02_THREE     = 3,
    BASE02_FOUR,     //=prev value +1
    BASE02_ONE       = 1,
    BASE02_TWO,      //=prev value +1
    BASE02_ONE_AGAIN = 1 //duplicate is ok
};

int main()
{
    {
        assert(BASE00_THREE==3);
        assert(BASE01_FOUR==4);

        assert(BASE02_ONE==1);
        assert(BASE02_ONE_AGAIN==1);
        assert(BASE02_TWO==2);
        assert(BASE02_THREE==3);
        assert(BASE02_FOUR==4);
    }
    
    return 0;
}
