#ifndef BOOK_H
#define BOOK_H

#include <string>

class Book
{
public:
    Book(const std::string &name,
	 const std::string &author,
	 const std::string &isbn,
	 unsigned pages,
	 const std::string &publisher,
	 const std::string &description = std::string())
	: _name(name),
	_author(author),
	_isbn(isbn),
	_pages(pages),
	_publisher(publisher),
	_description(description) {}

private:
    std::string _name;
    std::string _author;
    std::string _isbn;
    unsigned _pages = 0;
    std::string _publisher;
    std::string _description;
};

#endif
