#include <vector>
using std::vector;

class A {
public:
    void add(int val) { m_buf.push_back(val); }
    void shrinkBuf(int newSize)
    { m_buf.resize(newSize); m_buf.shrink_to_fit(); }
    void shrinkBuf() { m_buf.shrink_to_fit(); }
//    void shrinkBuf() { vector<unsigned char>(m_buf).swap(m_buf); }

private:
    vector<unsigned char> m_buf;
};

int main() {
    return 0;
}
