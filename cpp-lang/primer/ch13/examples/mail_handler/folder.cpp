#include "folder.h"
#include "message.h"

Folder::Folder(const Folder &other)
    : _messages(other._messages)
{
    fill_messages(other);
}

Folder &Folder::operator=(const Folder &other)
{
    clear_messages();
    _messages = other._messages;
    fill_messages(other);
    return *this;
}

Folder::~Folder()
{
    clear_messages();
}

void Folder::save(Message &m)
{
    _messages.insert(&m);
    m.add_folder(this);
}

void Folder::remove(Message &m)
{
    _messages.erase(&m);
    m.remove_folder(this);
}

void Folder::add_message(Message *m)
{
    _messages.insert(m);
}

void Folder::remove_message(Message *m)
{
    _messages.erase(m);
}

void Folder::clear_messages()
{
    while (!_messages.empty())
        (*_messages.begin())->remove(*this);
}

void Folder::fill_messages(const Folder &other)
{
    for (Message *m : other._messages)
        m->add_folder(this);
}
