#ifndef FOLDER_H
#define FOLDER_H

#include <string>
#include <set>

class Message;
class Folder
{
public:
    Folder() = default;
    Folder(const Folder &);
    Folder &operator=(const Folder &);
    ~Folder();

    void save(Message &);
    void remove(Message &);

private:
    void clear_messages();
    void fill_messages(const Folder &);
    void add_message(Message *);
    void remove_message(Message *);

    std::set<Message *> _messages;

    friend void swap(Message &, Message &);
    friend class Message;
};

#endif // FOLDER_H
