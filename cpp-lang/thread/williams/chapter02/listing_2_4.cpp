#include <string>
#include <thread>

struct user_command
{
    enum Type {open_new_document, close_document};

    Type type;
};

void open_document_and_display_gui(const std::string &filename)
{
    // do nothing
}

bool done_editing()
{
    return true;
}

user_command get_user_input()
{
    return user_command{user_command::open_new_document};
}

std::string get_file_name_from_user()
{
    return "file.doc";
}

void process_user_input(const user_command &cmd)
{
    // do nothing
}

void edit_document(const std::string &filename)
{
    open_document_and_display_gui(filename);
    while (!done_editing())
    {
        user_command cmd = get_user_input();
        if (cmd.type == user_command::open_new_document)
        {
            const std::string new_name = get_file_name_from_user();
            std::thread t(edit_document, new_name);
            t.detach();
        }
        else
        {
            process_user_input(cmd);
        }
    }
}

int main()
{
    edit_document("new.doc");

    return 0;
}
