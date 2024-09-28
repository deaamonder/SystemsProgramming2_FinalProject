#include <iostream>
#include <vector>
#include "Property.hpp"

using namespace std;

class Board{
    private :
        vector<Property> Properties;

    public:
        Board(){
            //initialze many properties as needed
        }

        Property& getProperty(int postion);
};