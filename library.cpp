#include <iostream>
#include <string>
#include <vector>
#include <limits>
#include <memory>

class Book{

private:
  std::string title;
  std::string author;
  int isbn;
public:
  Book(std::string title, std::string author, int isbn) : title(title), author(author), isbn(isbn){}
  
  //getter
  std::string getBookTitle() const{
    return title;
  }
  //getter
  std::string getAuthor() const{
    return author;
  }
  //getter
  int getBookIsbn() const{
    return isbn;
  }
};


class Library{
  
private:  
  std::vector<Book> book_list;
public: 
  Library(){
    book_list = {};
  }

  void add(){
    std::string title, author;
    int isbn;
    
    std::cout << "Enter title of book: ";
    std::getline(std::cin, title);

    std::cout << "Enter author name: ";
    std::getline(std::cin, author);

    std::cout << "Enter isbn: ";
    std::cin >> isbn;

    //clear input buffer
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    //create new book object and add to list
    book_list.push_back(Book(title, author,isbn));
  }

  void displayBooks() const{
    std::cout << "List of books in list:\n";
    for(const auto& book : book_list){
      std::cout << "Title: " << book.getBookTitle() << "\n"
                << "Author: " << book.getAuthor() << "\n"
                << "ISBN: " << book.getBookIsbn() << "\n\n";
    }
  } 

};


int main(void)
{

  /*
   * Test using unique_ptr
   * myBook is a unique_ptr to a Book object
   * that has been dynamically allocated using make_unique as params
   * When unique_ptr goes out of scope or is reset the Book object
   * will be automatically deleted.
   */

  std::unique_ptr<Book> myBook = std::make_unique<Book>("Test Title", "Test Author", 12345);

  std::cout << "Test using unique_ptr:\n";
  
  std::cout << "Title: " << myBook->getBookTitle() << std::endl
  << "Book: " << myBook->getAuthor() << std::endl 
  << "Isbn: " << myBook->getBookIsbn() << std::endl;
  

  Library my_lib;

  bool done = false;

  while(!done){
    my_lib.add();
  

    std::cout << "Add another book? (y/n): ";
    char choice;
    std::cin >> choice;

    if(choice != 'y' && choice != 'Y'){
      done = true;
    }
  
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  }
  my_lib.displayBooks();

  return 0;
}
