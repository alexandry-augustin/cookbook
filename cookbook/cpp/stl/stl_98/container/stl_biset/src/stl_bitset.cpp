#include <iostream>
#include <bitset>
#include <cassert>

int binary_to_dec(const std::string& bin)
{
	std::bitset<8> bit(std::string(bin.rbegin(), bin.rend()));
	return bit.to_ulong();
}

int main()
{
	{
		std::bitset<8> bs_00;
	}
	return 0;
}
