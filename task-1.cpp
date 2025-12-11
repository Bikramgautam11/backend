#include <iostream>
#include <vector>
#include <tuple>
using namespace std;

int main() {
    vector<string> days = {"Sunday","Monday","Tuesday","Wednesday","Thursday","Friday","Saturday"};
    vector<double> temperature = {21,19,15.2,10.4,11.4,8,8.6};

    cout << "Weekly Weather Report\n\n";

    for (size_t i = 0; i < days.size(); i++) {
        cout << days[i] << " = " << temperature[i] << "°C - Weather is";
// Classify the weather based on temperature
        if (temperature[i] < 10)
            cout << " COLD";
        else if (temperature[i] <= 20)
            cout << " OK";
        else
            cout << " WARM";

        cout << endl;
    }

    double max_temperature = temperature[0];
    string warmestDay = days[0];

    for (size_t i = 1; i < days.size(); i++) {
        if (temperature[i] > max_temperature) {
            max_temperature = temperature[i];
            warmestDay = days[i];
        }
    }

    tuple<string, double> warmest = make_tuple(warmestDay, max_temperature);

    cout << "\nWarmest Day = " << get<0>(warmest)
         << " (" << get<1>(warmest) << "°C)" << endl;

    return 0;
}
