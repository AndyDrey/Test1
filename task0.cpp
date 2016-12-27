#include <iostream>
#include <ostream>

using namespace std;

template<class T>
class ImmutableBuffer
{
    T* m_vlaue;
    int lenght;
    public:
    ImmutableBuffer(const T& arr[], int s): m_vlaue(arr), lenght(s)
    {
        m_vlaue = new T[s];

    }

//    ImmutableBuffer operator []()
//    {
//        return
//    }

    ImmutableBuffer operator ==(const ImmutableBuffer& rhs)
    {
        return *this == rhs.m_value;
    }

    ImmutableBuffer operator !=(const ImmutableBuffer& rhs)
    {
         return !(*this == rhs);
    }

    friend ostream& operator<<(ostream& stream, const ImmutableBuffer& rhs)
    {
       return stream << rhs.m_value;
    }
};

int main()
{

    return 0;
}
