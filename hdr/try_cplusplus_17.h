#ifndef TRY_CPLUSPLUS_17_H
#define TRY_CPLUSPLUS_17_H

#include "command.h"
#include <iostream>

#include <boost/fusion/adapted.hpp>
#include <boost/fusion/sequence.hpp>
#include <boost/mpl/int.hpp>
#include <iostream>

// C++ program to calculate Distance
// Between Two Points on Earth
#include <bits/stdc++.h>
using namespace std;

// Utility function for
// converting degrees to radians
long double toRadians(const long double degree)
{
    // cmath library in C++
    // defines the constant
    // M_PI as the value of
    // pi accurate to 1e-30
    long double one_deg = (M_PI) / 180;
    return (one_deg * degree);
}

long double distance(long double lat1, long double long1,
                    long double lat2, long double long2)
{
    // Convert the latitudes
    // and longitudes
    // from degree to radians.
    lat1 = toRadians(lat1);
    long1 = toRadians(long1);
    lat2 = toRadians(lat2);
    long2 = toRadians(long2);

    // Haversine Formula
    long double dlong = long2 - long1;
    long double dlat = lat2 - lat1;

    long double ans = pow(sin(dlat / 2), 2) +
                        cos(lat1) * cos(lat2) *
                        pow(sin(dlong / 2), 2);

    ans = 2 * asin(sqrt(ans));

    // Radius of Earth in
    // Kilometers, R = 6371
    // Use R = 3956 for miles
    long double R = 6371;

    // Calculate the result
    ans = ans * R;

    return ans;
}


bool isWithinCityLimits(std::string &city){

    static std::map<std::string,std::pair<std::size_t,std::size_t>> Cities_LatLong= {

        {"coimbatore",std::make_pair(11.0421454,77.040375)}
    };

    std::size_t lat,lng;
//    if(std::binary_search(Cities_LatLong.cbegin(),Cities_LatLong.cend(),city)){

//        lat = Cities_LatLong[city].first;
//        lng = Cities_LatLong[city].second;
//    }
}

struct strct
{
  int i;
  double d;
};

BOOST_FUSION_ADAPT_STRUCT(strct,
  (int, i)
  (double, d)
)

class try_cplusplus_17 : public Command{

    void execute()
    {
//        //http://www.ookingdom.com/metric/diameter
//        constexpr std::size_t radius_of_cbe = (28.5932260590746 / 2.0);
//        std::size_t earth_centre_lat = 11.018333;
//        std::size_t earth_centre_long = 76.9725;

//        long double lat2 = 11.0421454;
//        long double long2 = 77.040375;

//        // call the distance function
//        cout << setprecision(15) << fixed;

//        long double d = distance(centre_lat, centre_long,lat2, long2);

//        cout << d << " K.M" << std::endl;

//        std::cout << "Is he in Coimbatore: " << std::boolalpha << (d <= radius_of_cbe) <<std::endl;

        strct s = {10, 3.14};
        std::cout << boost::fusion::at<boost::mpl::int_<0>>(s) << '\n';
        std::cout << boost::fusion::back(s) << '\n';
        boost::fusion::for_each(s , [](auto i){
                                            std::cout << i << std::endl;
                                        });
    }
};
#endif // TRY_CPLUSPLUS_17_H
