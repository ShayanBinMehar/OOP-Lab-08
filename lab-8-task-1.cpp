#include <iostream>

class Humidity;

class Temperature {
private:
    double celsius;

public:
    Temperature(double c) : celsius(c) {}

    double getCelsius() const {
        return celsius;
    }

    friend double calculateHeatIndex(const Temperature& temp, const Humidity& humid);
};

class Humidity {
private:
    int percentage;

public:
    Humidity(int p) : percentage(p) {}

    int getPercentage() const {
        return percentage;
    }

    friend double calculateHeatIndex(const Temperature& temp, const Humidity& humid);
};

double calculateHeatIndex(const Temperature& temp, const Humidity& humid) {

    double heatIndex = temp.getCelsius() + (0.1 * humid.getPercentage());
    return heatIndex;
}

int main() {
    Temperature currentTemp(32.0);
    Humidity currentHumidity(70);

    double heatIndex = calculateHeatIndex(currentTemp, currentHumidity);

    std::cout << "Current Temperature: " << currentTemp.getCelsius() << " °C" << std::endl;
    std::cout << "Current Humidity: " << currentHumidity.getPercentage() << " %" << std::endl;
    std::cout << "Simplified Heat Index: " << heatIndex << std::endl;

    return 0;
}