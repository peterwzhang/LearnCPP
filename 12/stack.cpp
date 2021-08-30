#include <array>
#include <cassert>
#include <iostream>

class Stack{
private:
	using container_type = std::array<int, 10>;
	using size_type = container_type::size_type;
    container_type m_arr{};
    size_type m_size{ 0 };
public:
    void reset(){
        m_size = 0;
    }
    bool push(int value){
        if (m_size == m_arr.size()) return false;
        m_arr[m_size++] = value;
        return true;
    }
    int pop(){
        assert (m_size > 0 && "Can not pop empty stack");
        return m_arr[--m_size];
    }
    void print(){
        std::cout << "( ";
        for (size_t cur{ 0 }; cur < m_size; ++cur){
            std::cout << m_arr[cur] << ' ';
        }
        std::cout << ")\n";
    }
};

int main(){
    Stack stack;
	stack.reset();
 
	stack.print();
 
	stack.push(5);
	stack.push(3);
	stack.push(8);
	stack.print();
 
	stack.pop();
	stack.print();
 
	stack.pop();
	stack.pop();
 
	stack.print();
    return 0;
}