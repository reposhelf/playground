#include <iostream>
using std::cout;
using std::endl;
using std::cerr;

#include <string>
using std::string;

#include "deque.h"

void error(const char *msg) {
     cerr << msg << endl;
     exit(1);
}

void push_to_deque(char c, Deque<char> &buff) {
    if (isupper(c)) {
        buff.push_front(c);
    } else {
        buff.push_back(c);
    }
}

int main(int argc, char **argv) {
    if (argc < 3)
        error("Usage: <PROG_NAME> <SEQ_SRC> <SEQ_DST>");

    string seq_src = argv[1];
    string seq_dst = argv[2];

    if (seq_src.size() != seq_dst.size())
        error("First sequence cann't produce the second: Sizes are different");

    string::const_iterator seq_src_it = seq_src.cbegin();
    string::const_iterator seq_dst_it = seq_dst.cbegin();

    Deque<char> buff;
    string result;

    for (; seq_src_it != seq_src.cend(); ++seq_src_it) {
        push_to_deque(*seq_src_it, buff);
        result.push_back(*seq_src_it);

        while (!buff.empty()) {
            if (buff.front() == *seq_dst_it) {
                ++seq_dst_it;
                buff.pop_front();
                result.push_back('+');
            } else if (buff.back() == *seq_dst_it) {
                ++seq_dst_it;
                buff.pop_back();
                result.push_back('*');
            } else {
                break;
            }
        }
    }

    if (buff.empty())
        cout << result << endl;
    else
        error("First sequence cann't produce the second");

    return 0;
}
