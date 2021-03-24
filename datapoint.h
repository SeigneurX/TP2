#ifndef __DATAPOINT_H__
#define __DATAPOINT_H__

class datapoint
{
private:
    double lattitude;
    double longitude;
    std::string stationMeterologique;
    int temperature;
    std::string timestamp;

public:
    datapoint(double la_lattitude, double la_longitude, std::string la_stationMeterologique, int la_temperature, std::string timestamp)
    {
        this->lattitude = la_lattitude;
        this->longitude = la_longitude;
        this->stationMeterologique = la_stationMeterologique;
        this->temperature = la_temperature;
        this->timestamp = timestamp;
    }

    datapoint(std::string timestamp, double la_lattitude, double la_longitude, int temperature_celcius)
    {
        this->timestamp = timestamp;
        this->lattitude = la_lattitude;
        this->longitude = la_longitude;
        this->temperature = temperature_celcius;
    }

    ~datapoint(){};

    double getLattitude() const { return this->lattitude; }
    double getLongitude() const { return this->longitude; }
    std::string getStationMeterologique() const { return this->stationMeterologique; }
    int getTemperature() const { return this->temperature; }
    double getTemperatureCelcius() const { return (this->temperature - 32) * 5.0 / 9.0; }
    std::string getTimestamp() const { return this->timestamp; }

    bool operator<(const datapoint &autre_data) const
    {
        if (lattitude == autre_data.getLattitude())
        {
            return longitude < autre_data.getLongitude();
        }
        return lattitude > autre_data.getLattitude();
    }
};

#endif