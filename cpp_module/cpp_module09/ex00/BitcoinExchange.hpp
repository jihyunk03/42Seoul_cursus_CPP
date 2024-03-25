#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <fstream>
# include <map>
# include <algorithm>

# define DATABASE   "./data.csv"

# define FIRSTBAR   4
# define SECONDBAR  7
# define LIMITER    10

# define YEAR   2024
# define MONTH  3
# define DAY    25

class BitcoinExchange
{
    private:
        /* member variable */
        std::map<std::string, double> _database;

        /* member function */
        void        _checkDatabase(void);
        std::string _checkDate(const std::string& date);
        bool        _checkDateForm(const std::string& date);
        bool        _checkGregorian(int year, int day);
        double      _checkPrice(const std::string& price);
        void        _checkInputdata(const std::string& data);

    public:
        /* OCCF */
        BitcoinExchange();
        ~BitcoinExchange();

        /* member function */
        void calculate_bitcoin(const char* input);
};

#endif