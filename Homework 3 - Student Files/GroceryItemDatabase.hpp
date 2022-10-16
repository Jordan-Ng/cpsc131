#pragma once

///////////////////////// TO-DO (1) //////////////////////////////
  /// Include necessary header files
  /// Hint:  Include what you use, use what you include
  ///
  /// Do not put anything else in this section, i.e. comments, classes, functions, etc.  Only #include directives
#include <vector>
#include <iterator>
#include <iomanip>
#include <cstddef>
#include "GroceryItem.hpp"
/////////////////////// END-TO-DO (1) ////////////////////////////


// Singleton Design Pattern
class GroceryItemDatabase
{
  public:
    // Get a reference to the one and only instance of the database
    static GroceryItemDatabase & instance();

    // Locate and return a reference to a particular record
    GroceryItem * find( const std::string & isbn );                             // Returns a pointer to the item in the database if
                                                                                // found, nullptr otherwise
    // Queries
    std::size_t size() const;                                                   // Returns the number of items in the database

  private:
    GroceryItemDatabase            ( const std::string & filename );

    GroceryItemDatabase            ( const GroceryItemDatabase & ) = delete;    // intentionally prohibit making copies
    GroceryItemDatabase & operator=( const GroceryItemDatabase & ) = delete;    // intentionally prohibit copy assignments

    ///////////////////////// TO-DO (2) //////////////////////////////
      /// Private implementation details
      /// Add any necessary private helper functions, member attributes, etc.

    // move and copy constructor not really needed for this assignment
    // GroceryItemDatabase (GroceryItemDatabase const & other) = delete;
    // GroceryItemDatabase (GroceryItemDatabase  && other) = delete;

    // destructor to deallocate memory
    // ~ GroceryItemDatabase() noexcept;  

    // private helper function for recursive find
    GroceryItem * find(const std::string & isbn, auto current);

    bool isEmpty() const noexcept;

    // std::forward_list<GroceryItem *> _collection;
    std::vector<GroceryItem> _collection;
    // std::size_t _size = 0;
    /////////////////////// END-TO-DO (2) ////////////////////////////
};
