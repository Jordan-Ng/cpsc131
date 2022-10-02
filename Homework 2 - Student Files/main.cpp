#include <exception>
#include <iostream>
#include <sstream> // istringstream
#include <typeinfo>

#include "GroceryItem.hpp"
#include "GroceryList.hpp"

namespace
{
  void basicScenario()
  {
    // Let's start a grocery list
    GroceryList thingsToBuy = {{"milk"},
                               {"hot dogs"},
                               {"eggs"},
                               {"bread"}};

    // Changed my mind, I want to make sure I can get eggs before running out of money so I'm going to move that to the top of my list
    thingsToBuy.moveToTop({"eggs"});

    // Let's see what's on the list so far
    std::cout << "My Grocery List" << thingsToBuy << "\n\n";

    // Hmm ..., no.  Need to add a few more things
    thingsToBuy += {{"bananas"},
                    {"apples"}};

    // My roommate also has a grocery list
    GroceryList roommatesList = {{"potato chips", "Ruffles"},
                                 {"potato chips", "Frito Lays"},
                                 {"beer", "Bud Lite"},
                                 {"eggs"},
                                 {"pretzels"}};

    std::cout << "My roommate's Grocery List" << roommatesList << "\n\n";

    // Let's combine the lists (if different) and go shopping
    if (thingsToBuy != roommatesList)
      thingsToBuy += roommatesList;

    // Oops, forgot butter.  Let's add that right before bread.
    thingsToBuy.insert({"butter", "Lakes 'Ole"}, thingsToBuy.find({"bread"}));

    // And beer, really?  You should be studying!
    thingsToBuy.remove({"beer", "Bud Lite"});

    // Now let's see what's on the list
    std::cout << "Combined Grocery Lists" << thingsToBuy << "\n\n";

    // Did you get it right?
    //
    // I could construct "expectedResults" with the list of grocery items as above, but I want to exercise GroceryList's extraction
    // operator.  To do that, I could:
    //   1) read the list of grocery items from standard input and type the data at the keyboard, but that is time consuming and
    //      error prone.  That's easily handled by creating a text file with grocery item data then redirecting that text file to
    //      standard input at the command line when launching the program.  But then I would have to separately maintain that file
    //      and include it in the set of student files.  More importantly, that would prevent you from doing that in the TO-DO
    //      section below.
    //   2) open a text file directly using either command line arguments that supply the file's path and name, or hard coding the
    //      file's path and name.  But that would require using (and understanding) the standard's ifstream interface, which is easy
    //      enough given sufficient time, but I don't want to go down that rabbit hole in this course.
    //   3) create an in-memory text file (well, more accurately, an in-memory input stream) and read from there.  This allows me to
    //      exercise the extraction operator while avoiding the perils described in options 1) and 2) above.
    // So, as a design decision, let's chose option 3), create an in-memory input stream and read from there.
    //
    //                                            UPC | Brand Name   | Product Name   | Price
    //                                            ----+--------------+----------------+--------
    std::istringstream expectedResultsStream(R"( "",   "",            "eggs",          0.0
                                                  "",   "",            "milk",          0.0
                                                  "",   "",            "hot dogs",      0.0
                                                  "",   "Lakes 'Ole",  "butter",        0.0
                                                  "",   "",            "bread",         0.0
                                                  "",   "",            "bananas",       0.0
                                                  "",   "",            "apples",        0.0
                                                  "",   "Ruffles",     "potato chips",  0.0
                                                  "",   "Frito Lays",  "potato chips",  0.0
                                                  "",   "",            "pretzels",      0.0 )" // multi-line raw string literal of grocery items
    );

    GroceryList expectedResults;
    expectedResultsStream >> expectedResults;

    std::cout << "\nExpected results:" << expectedResults << "\n\n"
              << "\nActual results:  " << thingsToBuy << "\n\n"
              << "\nTest results:    " << (thingsToBuy == expectedResults ? "PASS" : "FAIL") << '\n';
  }
}

int main()
{
  try
  {
    basicScenario();

    ///////////////////////// TO-DO (1) //////////////////////////////
    /// Create, manipulate, and display your own GroceryList object here.  Not looking for anything specific but don't just repeat
    /// what I've already done above.  Be imaginative and create your own story.  Maybe you're restocking a depleted food bank, or
    /// preparing for a holiday meal, or catering a banquette, or planning an all night study session, or ...  You *must* use all
    /// the functions of the GroceryList interface, including the insertion, extraction, and relational operators.  Try inserting
    /// grocery items from both the top and the bottom of the lists using the enumerated position values TOP and BOTTOM as well as
    /// indexed offsets.  Remove grocery items from the top, middle, and bottom.  Create, concatenate, rearrange, and compare
    /// several (more than two) lists. Have some fun with it!  The purpose is to show me you, as a GroceryList class consumer
    /// (i.e., the client) understand how to *use* the GroceryList.

    // me: my grocery list and print
    GroceryList myGroceryList = {{"eggs"}, {"coffee"}, {"apples"}, {"oranges"}, {"ice-cream"}};
    std::cout<< "---- my list ---- \n" << myGroceryList << "---- end of list ---- \n\n";
    // roommate1: grocery list and print
    GroceryList roommateOneGroceryList = {{"coffee"}, {"eggs"}, {"apples"}, {"oranges"}, {"ice-cream"}};
    std::cout<< "---- roommate 1's list ---- \n" << roommateOneGroceryList << "---- end of list ---- \n\n";
    // roommate2: grocery list and print
    GroceryList roommateTwoGroceryList = {{"potato chips"}, {"soda"}, {"ice-cream"}};
    std::cout<< "---- roommate 2's list ---- \n" << roommateTwoGroceryList << "---- end of list ---- \n\n";
    // roommate1 -> me: think we have different lists
    if (roommateOneGroceryList != myGroceryList) std::cout<<"roommate1 -> me: I think we have different lists..\n";
    // roommate2 -> me: think we have different lists
    if (roommateTwoGroceryList <=> myGroceryList != 0) 
    std::cout<< "roommate2 -> me: I think we have different lists too..\n"
    // roommate2: let's go grocery shopping together!
            << "roommate2: Let's go grocery shopping together!\n";
    // me: wait, hold on, the order's just off
    std::cout << "me -> roommate1: wait, hold on.. our order's just off!\n";
    // me: I'll just go with roommate2 and do the shopping for you, roommate1
    myGroceryList.moveToTop({"coffee"});
    if (myGroceryList <=> roommateOneGroceryList == 0) std::cout<< "me: I'll just go with roommate2 and do the shopping for you, roommate1.\n";
    // roommate1: awesome, I just have a couple more things to add to the list
    std::cout << "roommate1 -> me: awesome, I just have a couple more things to add to the list\n";
    myGroceryList += {{"bread"}, {"tomatoes"}};
    // me: sure, gotcha!
    if(myGroceryList.size() == 7) 
    std::cout << "me: sure, gotcha!\n"
     << "me -> roommate2: let's combine our lists so we can find everything quicker\n\n";

    myGroceryList += roommateTwoGroceryList;
    std::cout << "---- combined list ----\n" << myGroceryList << "---- end of list ----\n\n";
    
    myGroceryList.remove(myGroceryList.find({"coffee"}));
    std::cout << "me: found cofee!\n";
    
    myGroceryList.remove(7);
    std::cout << "roommate2: found soda!\n";
    
    myGroceryList.remove(myGroceryList.find({"ice-cream"}));
    std::cout << "me: found ice-cream!\n";

    myGroceryList.remove(myGroceryList.find({"apples"}));
    std::cout << "me: found apples!\n";

    myGroceryList.remove(myGroceryList.find({"oranges"}));
    std::cout << "me: found oranges!\n";

    myGroceryList.remove(0);
    std::cout << "roommate2: found eggs!\n";

    myGroceryList.remove(myGroceryList.find({"tomatoes"}));
    std::cout << "roommate2: found tomatoes!\n";

    myGroceryList.remove(myGroceryList.size()-1);
    std::cout << "roommate2: found chips!\n";

    myGroceryList.remove(0);
    std::cout << "me: found bread!\n";

    // roommate2,me: looks like we got everything, let's head back
    if(myGroceryList.size() == 0) std::cout << "roommate2, me: Well, looks like we got everything, let's head back!\n\n";
    /////////////////////// END-TO-DO (1) ////////////////////////////
  }

  catch (const std::exception &ex)
  {
    std::cerr << "Fatal Error:  unhanded exception \"" << typeid(ex).name() << "\"\n"
              << ex.what() << '\n';
  }
}
