///////////////////////// TO-DO (1) //////////////////////////////
  /// Include necessary header files
  /// Hint:  Include what you use, use what you include
  ///
  /// Do not put anything else in this section, i.e. comments, classes, functions, etc.  Only #include directives
#include <string>
#include <locale>
#include <iostream>
#include <cstddef>
#include <algorithm>
#include "WordFrequency.hpp"
/////////////////////// END-TO-DO (1) ////////////////////////////







// unnamed, anonymous namespace providing non-member private working area
namespace
{
  std::string sanitize( const std::string & word )
  {
    constexpr char bad_char[] = " \t\n\b\v_-\"'(){}+/*,=.!?:;";            // leading and trailing characters to be removed
    static std::locale locality;

    auto startIndex = word.find_first_not_of( bad_char );                  // start with the first non-bad character
    if( startIndex == std::string::npos ) startIndex = word.size();        // if the word contains only bad characters ...

    std::size_t count    = 0;                                              // assume the word contains only bad characters ...
    auto        endIndex = word.find_last_not_of( bad_char );              // end with the first non-bad character

    if( endIndex != std::string::npos ) count = endIndex - startIndex + 1; // number of characters to use in results

    auto result = word.substr( startIndex, count );                        // strip the leading and trailing bad characters
    for( auto & c : result ) c = std::tolower( c, locality );              // convert to lower case

    return result;
  }
}  // unnamed, anonymous namespace







// Implement WordFrequency::WordFrequency( std::istream ) - See requirements
///////////////////////// TO-DO (2) //////////////////////////////
WordFrequency::WordFrequency(std::istream & iStream){
  std::string word;
  while (iStream >> word){
    word = sanitize(word);
    auto result = _repository.find(word);
  
    if (result == _repository.end()){
      _repository.insert({word, 1});
    }
    else {
      ++result->second;
    }
  }
}
/////////////////////// END-TO-DO (2) ////////////////////////////







// Implement WordFrequency::numberOfWords() const - See requirements
///////////////////////// TO-DO (3) //////////////////////////////
std::size_t WordFrequency::numberOfWords() const {
  return _repository.size();
}
/////////////////////// END-TO-DO (3) ////////////////////////////







// Implement WordFrequency::wordCount( const std::string & ) const - See requirements
///////////////////////// TO-DO (4) //////////////////////////////
std::size_t WordFrequency::wordCount(const std::string & word) const {
  auto result = _repository.find(sanitize(word));
  return result == _repository.end() ? 0 : result->second;
}
/////////////////////// END-TO-DO (4) ////////////////////////////







// Implement WordFrequency::mostFrequentWord() const - See requirements
///////////////////////// TO-DO (5) //////////////////////////////
std::string WordFrequency::mostFrequentWord() const {
  if (_repository.empty()) return "";

  auto mostFrequentWord = _repository.begin();

  for (auto i= _repository.begin(); i!= _repository.end(); ++i){
    mostFrequentWord = (mostFrequentWord->second > i->second ? mostFrequentWord : i);
  }
  return mostFrequentWord->first;
}
/////////////////////// END-TO-DO (5) ////////////////////////////







// Implement WordFrequency::maxBucketSize() const - See requirements
///////////////////////// TO-DO (6) //////////////////////////////
  /// Hint: see the unordered_map's bucket interface at https://en.cppreference.com/w/cpp/container/unordered_map
std::size_t WordFrequency::maxBucketSize () const {
  unsigned long maxBucketSize = 0;

  for (unsigned long i=0; i < _repository.bucket_count(); ++i){
    maxBucketSize = (maxBucketSize > _repository.bucket_size(i) ? maxBucketSize : _repository.bucket_size(i));
  }

  return maxBucketSize;
}
/////////////////////// END-TO-DO (6) ////////////////////////////
