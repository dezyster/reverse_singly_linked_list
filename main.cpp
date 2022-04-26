#include <iostream>
#include <stack>

using std::stack;
using std::cout;
using std::endl;

class OneSideList
{
    OneSideList *m_next;
    int m_key;

    void reverseImpl(std::stack <OneSideList*> &pointerStack)
    {
        if(m_next)
        {
            pointerStack.push(this);
            m_next->reverseImpl(pointerStack);
        }
        m_next = pointerStack.top();
        pointerStack.pop();
    }

public:
    OneSideList(int key): m_key{key}, m_next{nullptr}{};
    OneSideList(int key, OneSideList *next): m_key{key}, m_next{next}{};

    void SetNext(OneSideList *next)
    {
        m_next = next;
    };

    void print()
    {
        cout << m_key << " ";
        if(m_next)
        {
            m_next->print();
        }
    };

    void reverse()
    {
        std::stack<OneSideList*> pointerStack;

        pointerStack.push(nullptr);

        reverseImpl(pointerStack);
    }

};

int main()
{
    OneSideList first{5};

    OneSideList second{7};
    first.SetNext(&second);

    OneSideList third{3};
    second.SetNext(&third);

    first.print();

    first.reverse();

    cout << endl;

    third.print();

    return 0;
}
