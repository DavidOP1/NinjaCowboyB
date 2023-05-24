#include <stdio.h>
#include <string>

using namespace std;
namespace ariel{
    class Point{
    public:
        Point();
        Point(double,double);
        Point(const Point&);
        double distance(Point) const;
        string print();
        static  Point moveTowards(Point , Point , double ); // returning copy , because we just need its cordinates.
        double getXcord() const;
        double getYcord() const;
    private:
        double xCord , yCord;
    };
}