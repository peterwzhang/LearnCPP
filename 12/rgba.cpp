#include <cstdint>
#include <iostream>

class RGBA{
    private:
    using component_type = std::uint_fast8_t;
    component_type m_red{};
    component_type m_green{};
    component_type m_blue{};
    component_type m_alpha{};
public:
    //RGBA() : m_red(0), m_green(0), m_blue(0), m_alpha(255){};
    RGBA(component_type r = 0, component_type g = 0, component_type b = 0, component_type alpha = 255)
        : m_red(r), m_green(g), m_blue(b), m_alpha(alpha){};
    void print(){
        std::cout << "r=" << static_cast<int>(m_red) << " g=" << static_cast<int>(m_green) 
                  << " b=" << static_cast<int>(m_blue) << " a=" <<static_cast<int>(m_alpha) << '\n'; 
    }
};

int main()
{
	RGBA teal{ 0, 127, 127 };
	teal.print();
 
	return 0;
}