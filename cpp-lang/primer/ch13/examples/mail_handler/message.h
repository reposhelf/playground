#ifndef MESSAGE_H
#define MESSAGE_H

#include <string>
#include <set>

class Folder;
class Message
{
public:
    explicit Message(const std::string &s = "");
    Message(const Message &);
    Message(Message &&);
    Message &operator=(const Message &);
    Message &operator=(Message &&);
    ~Message();

    void save(Folder &);
    void remove(Folder &);

private:
    void add_to_folders(const Message &);
    void remove_from_folders();
    void add_folder(Folder *);
    void remove_folder(Folder *);
    void move_folders(Message *);

    std::string _contents;
    std::set<Folder *> _folders;

    friend void swap(Message &, Message &);
    friend class Folder;
};

#endif // MESSAGE_H
