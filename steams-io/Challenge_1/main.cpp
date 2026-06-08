// Section 19
// Challenge 1
// Formatting output
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>

struct City
{
    std::string name;
    long population;
    double cost;
};

// Assume each country has at least 1 city
struct Country
{
    std::string name;
    std::vector<City> cities;
};

struct Tours
{
    std::string title;
    std::vector<Country> countries;
};

int main()
{
    Tours tours{"Tour Ticket Prices from Miami",
                {
                    {
                        "Colombia",
                        {{"Bogota", 8778000, 400.98},
                         {"Cali", 2401000, 424.12},
                         {"Medellin", 2464000, 350.98},
                         {"Cartagena", 972000, 345.34}},
                    },
                    {
                        "Brazil",
                        {{"Rio De Janiero", 13500000, 567.45},
                         {"Sao Paulo", 11310000, 975.45},
                         {"Salvador", 18234000, 855.99}},
                    },
                    {
                        "Chile",
                        {{"Valdivia", 260000, 569.12},
                         {"Santiago", 7040000, 520.00}},
                    },
                    {"Argentina", {{"Buenos Aires", 3010000, 723.77}}},
                }};

    constexpr int countryWidth = 20;
    constexpr int cityWidth = 25;
    constexpr int populationWidth = 15;
    constexpr int priceWidth = 12;

    std::cout << std::setw(70) << tours.title << std::endl;
    std::cout << std::endl;
    std::cout << std::left << std::setw(countryWidth) << "Country"
              << std::left << std::setw(cityWidth) << "City"
              << std::right << std::setw(populationWidth) << "Population"
              << std::right << std::setw(priceWidth) << "Price"
              << std::endl;

    for (auto const country : tours.countries)
    {
        for (int i = 0; i < country.cities.size(); i++)
        {
            if (i == 0)
            {
                std::cout << std::left << std::setw(countryWidth) << country.name;
            }
            else
            {
                std::cout << std::left << std::setw(countryWidth) << "";
            }
            std::cout << std::left << std::setw(cityWidth) << country.cities[i].name
                      << std::right << std::setw(populationWidth) << country.cities[i].population
                      << std::right << std::setw(priceWidth) << country.cities[i].cost;
            std::cout<<std::endl;
        }
        std::cout<<std::endl;
    }
    return 0;
}