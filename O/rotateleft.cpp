#include <bitset>
#include <iostream>
 
// "rotl" stands for "rotate left"
std::bitset<4> rotl(std::bitset<4> bits)
{
    const bool saved_bit {bits.test(3)};
    bits <<= 1;
    if (saved_bit) bits.set(0);
    return bits;
    
}

std::bitset<4> rotlTwo(std::bitset<4> bits)
{
    return (bits << 1) | (bits >> 3);
}
// 1001
// 0010
// 0001
// 0011

// 0001
// 0010
// 0000
// 0010
int main()
{
	std::bitset<4> bits1{ 0b0001 };
	std::cout << rotl(bits1) << '\n';
 
	std::bitset<4> bits2{ 0b1001 };
	std::cout << rotl(bits2) << '\n';
 
	return 0;
}