#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

// function prototypes
double getTotalRainfall(const double[], int);
double getAverageRainfall(const double[], int);
void getExtremes(const double[], int, double *, double *);
void sortRainfall(double[], std::string[], int);

// start point of the program
int main()
{
    const int TOTAL_MONTHS = 12;
    double rainfall[TOTAL_MONTHS];
    std::string months[TOTAL_MONTHS] = {"January", "February", "March", "April", "May", "June", "July", "August", "September",
                                        "October", "November", "December"};

    std::ifstream file("rainfall.txt");

    // read the data from the file into array
    for (int i = 0; i < TOTAL_MONTHS && file >> rainfall[i]; i++)
        ;

    double min, max;
    getExtremes(rainfall, TOTAL_MONTHS, &min, &max);
    std::cout << "The minimum rainfall is " << min << std::endl;
    std::cout << "The maximum rainfall is " << max << std::endl;

    sortRainfall(rainfall, months, TOTAL_MONTHS);
    std::cout << "Rainfall by lowest to highest:" << std::endl;
    for (int i = 0; i < TOTAL_MONTHS; i++)
        std::cout << months[i] << ": " << rainfall[i] << std::endl;
    return 0;
}

// function to get the total rainfall for the year from the array
double getTotalRainfall(const double rainfall[], int size)
{
    double total = 0;
    for (int i = 0; i < size; i++)
        total += rainfall[i];
    return total;
}

// function to get the average rainfall for the year from the array
double getAverageRainfall(const double rainfall[], int size)
{
    return getTotalRainfall(rainfall, size) / size;
}

// function to get the minimum and maximum rainfall for the year from the array
// uses pointers for min and max, doesnt return anything
void getExtremes(const double rainfall[], int size, double *min, double *max)
{
    *min = rainfall[0];
    *max = rainfall[0];
    for (int i = 1; i < size; i++)
    {
        if (rainfall[i] < *min)
            *min = rainfall[i];
        if (rainfall[i] > *max)
            *max = rainfall[i];
    }
}

// function to sort the rainfall array from lowest to highest
// uses selection sort
void sortRainfall(double rainfall[], std::string months[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        int minIndex = i;
        for (int j = i + 1; j < size; j++)
        {
            if (rainfall[j] < rainfall[minIndex])
                minIndex = j;
        }
        std::swap(rainfall[i], rainfall[minIndex]);
        std::swap(months[i], months[minIndex]);
    }
}
