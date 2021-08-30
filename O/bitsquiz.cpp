#include <bitset>
#include <cstdint>
#include <iostream>
 
int main()
{
    constexpr std::uint_fast8_t option_viewed{ 0x01 };      // 0000 0001
    constexpr std::uint_fast8_t option_edited{ 0x02 };      // 0000 0010
    constexpr std::uint_fast8_t option_favorited{ 0x04 };   // 0000 0100
    constexpr std::uint_fast8_t option_shared{ 0x08 };      // 0000 1000
    constexpr std::uint_fast8_t option_deleted{ 0x10 };     // 0001 0000
 
    std::uint_fast8_t myArticleFlags{ option_favorited };
 
    myArticleFlags |= option_viewed;        // add option viewed
    if (myArticleFlags & option_deleted){   // check option deleted
        std::cout << "Deleted\n";
    }
    else{
        std::cout << "Not deleted\n";
    }

    myArticleFlags &= ~(option_favorited); // clear favorite
 
    std::cout << std::bitset<8>{ myArticleFlags } << '\n';
 
    return 0;
}