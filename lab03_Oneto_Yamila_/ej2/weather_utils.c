#include <stdio.h>
#include <limits.h>
#include "array_helpers.h"
#include "weather_utils.h"
#include "weather.h"

int min_tempe(WeatherTable array)
{
    int minimiest = INT_MAX;
    int temp = 0;

    for (int year = 0; year < YEARS; year++)
    {
        for (month_t month = january; month < december; month++)
        {
            for (int day = 0; day < DAYS; day++)
            {
                temp = array[year][month][day]._min_temp;

                if (temp < minimiest)
                {
                    minimiest = temp;
                }
            }
        }
    }

    return minimiest;
}

void max_temp(WeatherTable array, int output[YEARS])
{
    int temp = 0;

    for (int year = 0; year < YEARS; year++)
    {
        int maxtemp = INT_MIN;
        for (month_t month = january; month < december; month++)
        {
            for (int day = 0; day < DAYS; day++)
            {
                temp = array[year][month][day]._max_temp;

                if (temp > maxtemp)
                {
                    maxtemp = temp;
                }
            }
        }
        output[year] = maxtemp;
    }
}

void max_rainfall(WeatherTable array, int output[YEARS])
{

    for (int year = 0; year < YEARS; year++)
    {

        int max_rainfall = INT_MIN;

        for (month_t month = january; month < december; month++)
        {

            month_t max_month;

            for (int day = 0; day < DAYS; day++)
            {

                int monthly_precipitacion = array[year][month][day]._rainfall;

                if (monthly_precipitacion > max_rainfall)
                {

                    max_rainfall = monthly_precipitacion;
                    max_month = month;
                }
            }

            output[year] = max_month + 1;
        }
    }
}