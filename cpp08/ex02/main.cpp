#include "MutantStack.hpp"

int main()
{
    MutantStack<int> mstack;

    std::cout << "\n📥 Pushing elements onto the stack..." << std::endl;
    mstack.push(5);
    mstack.push(17);

    std::cout << "🔝 Top element: " << mstack.top() << std::endl;

    std::cout << "🗑️ Popping top element..." << std::endl;
    mstack.pop();

    std::cout << "📏 Stack size after pop: " << mstack.size() << std::endl;

    std::cout << "\n📥 Adding more elements..." << std::endl;
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);

    std::cout << "\n🔁 Iterating through the stack (forward):" << std::endl;
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    for (; it != ite; ++it)
    {
        std::cout << *it << std::endl;
    }

    std::cout << "\n🔁 Iterating through the stack (reverse):" << std::endl;
    MutantStack<int>::reverse_iterator rit = mstack.rbegin();
    MutantStack<int>::reverse_iterator rite = mstack.rend();
    for (; rit != rite; ++rit)
    {
        std::cout << *rit << std::endl;
    }

    std::cout << "\n📋 Creating a std::stack from MutantStack..." << std::endl;
    std::stack<int> s(mstack);
    std::cout << "📦 std::stack top: " << s.top() << std::endl;


    return 0;
}
