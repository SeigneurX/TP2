#include <iostream>
#include <set>
#include <fstream>

#include "datapoint.h"

void afficherData(std::set<datapoint> data);
int main()
{
    std::set<datapoint> les_donnees;
    double lattitude;
    double longitude;
    std::string stationMeterologique;
    int temperature;
    std::string timestamp;

    std::ifstream rawdata("rawdata.txt");
    //rawdata.close();
    if (rawdata.is_open())
    {

        while (rawdata >> lattitude >> longitude >> stationMeterologique >> temperature >> timestamp)
        {
            datapoint datas(lattitude, longitude, stationMeterologique, temperature, timestamp);
            les_donnees.insert(datas);
        }
        rawdata.close();
    }


    std::ofstream candata("candata.txt");
    for (const auto &e : les_donnees)
    {
        candata << e.getTimestamp() << " " << e.getLattitude() << " " << e.getLongitude() << " " << e.getTemperatureCelcius() << std::endl;
    }
    candata.close();
}
