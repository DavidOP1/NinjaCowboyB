#include "Point.hpp"
#include <cmath>
#include <iostream>
#include <string>

using namespace std;
namespace ariel
{
    Point::Point(){};
    Point::Point(const Point &other)
    {
        this->xCord = other.getXcord();
        this->yCord = other.getYcord();
    };
    Point::Point(double x, double y)
    {
        this->xCord = x;
        this->yCord = y;
    };
    double Point::distance(Point target) const 
    {
        double left = pow((this->xCord) - (target.getXcord()), 2);
        double right = pow((this->yCord) - (target.getYcord()), 2);
        double result = sqrt(left + right);
        //cout << result << endl;
        return result;
    };
    string Point::print()
    {
        return "("+to_string(xCord)+","+to_string(yCord)+")";
        //cout << "(" << this->xCord << "," << this->yCord << ")" << endl;
    };
    Point Point::moveTowards(Point src, Point dst, double distance)
    {
        if(distance < 0) throw invalid_argument("negative distance");
        // Create linear formula.
        double temp_distance = src.distance(dst);

        if (distance >= temp_distance)
        {
            return dst;
        }

        double m = (src.getYcord() - dst.getYcord()) / (src.getXcord() - dst.getXcord());
        double b = src.getYcord() - (m * src.getXcord());

        double d_ratio = distance / src.distance(dst);

        double x_closest = ((1 - d_ratio) * src.getXcord()) + d_ratio * dst.getXcord();
        double y_closest = ((1 - d_ratio) * src.getYcord()) + d_ratio * dst.getYcord();

        return Point(x_closest, y_closest);
    }; // returning copy , because we just need its cordinates.
    double Point::getXcord() const { return this->xCord; };
    double Point::getYcord() const { return this->yCord; };
}