# Homework 2

## main.cpp
- designed driver code to interact with the public member functions of the GroceryList interface.
- comments shown above blocks of code should be removed. However, for this assignment, it is intentionally left to show the pseudocode and thought process while implementing the code.
- outputs are piped into output.txt.

## GroceryList.cpp
- (to do: 1) gList_vector.size() can be user here, but it's one extra nested operation. Since we keep track of _gList_array_size, we can just return a copy of that instead.

- (to do: 2) vector, SLL, or DLL can be used here, but not array (has same size and capacity).

- (to do: 4) I have included a condition to check if the client is inserting before/middle of the array. This is done because, if the client is inserting to the back of the array, or when the array is empty, there is no need to shift the items one index back. 

- (to do: 8) using a ternary operator to evaluate the starting position for the std::move operation, since the starting position is different when removing within the array, or the "last" item in the array 

- (to do: 15) the code can be refactored a little more (to save on space), by having the comparison between grocery items evaluated in the if statement (r-value), instead of assigning it to the comparison variable. However, since it probably won't make too much of a difference, and the comparison variable will get destructed when it goes out of scope in a few lines of code, I have separated them for better readability. 
