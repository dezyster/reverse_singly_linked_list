#include <iostream>

using std::cout;
using std::endl;

class OneSideList
{
    int m_key;
    OneSideList *m_next;

    void reverseImpl(OneSideList *prev)
    {
        OneSideList *temp = m_next;
        m_next = prev;
        if(temp)
        {
            temp->reverseImpl(this);
        }
    }

public:
    OneSideList(int key): m_key{key}, m_next{nullptr}{};

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
        reverseImpl(nullptr);
    }

};

int main()
{
    OneSideList first{5};
    OneSideList second{7};
    OneSideList third{3};
    OneSideList fourth{9};

    first.SetNext(&second);
    second.SetNext(&third);
    third.SetNext(&fourth);

    first.print();

    first.reverse();

    cout << endl;

    fourth.print();

    return 0;
}


