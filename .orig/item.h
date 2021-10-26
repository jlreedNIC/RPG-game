#include <iomanip>
#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

class Itemclass
{
    public:
        void create(string, int, int);
        void destroy();
        void set_sellprice();
        void print();

        int price;
        int sell_price;
        string name;
        string type;
        int attack;
        int defence;
        int proficiency;
        int prof_level;
        int healing;

    protected:
    private:
};
