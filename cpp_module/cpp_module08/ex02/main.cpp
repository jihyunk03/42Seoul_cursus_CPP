#include "./MutantStack.hpp"
#include <list>

int main(void)
{
    std::cout << "===============[MutantStack]===============" << std::endl;
    {
        MutantStack<int> mstack;

        mstack.push(5);
        mstack.push(17);

        std::cout << "pop before size: " << mstack.size() << std::endl;
        std::cout << "pop before top element: " << mstack.top() << std::endl;
        mstack.pop();
        std::cout << "-------------------------------------------" << std::endl;
        std::cout << "pop after size: " << mstack.size() << std::endl;
        std::cout << "pop after top element: " << mstack.top() << std::endl;

        mstack.push(3);
        mstack.push(5);
        mstack.push(737);
        mstack.push(0);

        std::cout << "-------------------------------------------" << std::endl;

        MutantStack<int>::iterator it = mstack.begin();
        MutantStack<int>::iterator ite = mstack.end();
        ++it;
        --it;
        std::cout << "[ ";
        while (it != ite)
        {
            std::cout << *it << " ";
            ++it;
        }
        std::cout << "]" << std::endl;

        std::cout << "-------------------------------------------" << std::endl;

        std::stack<int> realStack(mstack);
        std::cout << "real stack's top: " << realStack.top() << std::endl;
        std::cout << "mstack's top: " << mstack.top() << std::endl;
    }

    std::cout << std::endl;

    std::cout << "===============[ std::list ]===============" << std::endl;
    {
        std::list<int> stdList;

        stdList.push_back(5);
        stdList.push_back(17);

        std::cout << "pop before size: " << stdList.size() << std::endl;
        std::cout << "pop before front element: " << stdList.back() << std::endl;
        stdList.pop_back();
        std::cout << "-------------------------------------------" << std::endl;
        std::cout << "pop after size: " << stdList.size() << std::endl;
        std::cout << "pop after front element: " << stdList.back() << std::endl;

        stdList.push_back(3);
        stdList.push_back(5);
        stdList.push_back(737);
        stdList.push_back(0);

        std::cout << "-------------------------------------------" << std::endl;

        std::list<int>::iterator it = stdList.begin();
        std::list<int>::iterator ite = stdList.end();

        ++it;
        --it;
        std::cout << "[ ";
        while (it != ite)
        {
            std::cout << *it << " ";
            ++it;
        }
        std::cout << "]" << std::endl;

        std::cout << "-------------------------------------------" << std::endl;

        std::list<int> copyList(stdList);
        std::cout << "copy stack's top: " << copyList.back() << std::endl;
        std::cout << "stdList's top: " << stdList.back() << std::endl;
    }

    return 0;
}