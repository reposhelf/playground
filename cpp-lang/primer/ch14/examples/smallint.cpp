#include <stdexcept>

class SmallInt
{
public:
    SmallInt(int i = 0) : m_val(i) {
        if (i < 0 || i > 255)
            throw std::out_of_range("Bad SmallInt value");
    }
    explicit operator int() const { return m_val; }

private:
    std::size_t m_val;
};

int main()
{
    SmallInt si = 31;
    static_cast<int>(si) + 31;
    return 0;
}
