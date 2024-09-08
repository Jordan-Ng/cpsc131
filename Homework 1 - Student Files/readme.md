# CPSC131 assignment pointers (no pun intended!)

## To-Do items
- (items 2,4,6) I am unsure if it is good practice to have std::move for _price since, for double type, std::move does not actually move (copies instead). 
- (item 7) additional destructor logic is not required here since there are no attributes in the class that is a pointer. So default destructor is sufficient.
- (item 19) logic can be simplified more if the == operator logic (item 20) was defined before this function.
