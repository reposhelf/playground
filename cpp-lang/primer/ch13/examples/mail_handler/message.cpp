#include "message.h"
#include "folder.h"

inline void swap(Message &lhs, Message &rhs)
{
    using std::swap;
    for (Folder *f : lhs._folders)
        f->remove_message(&lhs);
    for (Folder *f : rhs._folders)
        f->remove_message(&rhs);
    swap(lhs._contents, rhs._contents);
    swap(lhs._folders, rhs._folders);
    for (Folder *f : lhs._folders)
        f->add_message(&lhs);
    for (Folder *f : rhs._folders)
        f->add_message(&rhs);
}

Message::Message(const std::string &s)
    : _contents(s)
{
}

Message::Message(const Message &m)
    : _contents(m._contents),
      _folders(m._folders)
{
    add_to_folders(m);
}

Message::Message(Message &&other)
    : _contents(std::move(other._contents))
{
    move_folders(&other);
}

Message &Message::operator=(const Message &rhs)
{
    remove_from_folders();
    _contents = rhs._contents;
    _folders = rhs._folders;
    add_to_folders(rhs);
    return *this;
}

Message &Message::operator=(Message &&rhs)
{
    if (this != &rhs) {
        remove_from_folders();
        _contents = std::move(rhs._contents);
        move_folders(&rhs);
    }
    return *this;
}

Message::~Message()
{
    remove_from_folders();
}

void Message::save(Folder &f)
{
    _folders.insert(&f);
    f.add_message(this);
}

void Message::remove(Folder &f)
{
    _folders.erase(&f);
    f.remove_message(this);
}

void Message::add_to_folders(const Message &m)
{
    for (Folder *f : m._folders)
        f->add_message(this);
}

void Message::remove_from_folders()
{
    for (Folder *f : _folders)
        f->remove_message(this);
}

void Message::add_folder(Folder *f)
{
    _folders.insert(f);
}

void Message::remove_folder(Folder *f)
{
    _folders.erase(f);
}

void Message::move_folders(Message *m)
{
    _folders = std::move(m->_folders);

    for (auto f : _folders) {
        f->remove_message(m);
        f->add_message(m);
    }
    m->_folders.clear();
}
