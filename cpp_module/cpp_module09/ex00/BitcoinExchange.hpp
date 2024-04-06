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

# define F_YEAR     2009
# define F_MONTH    1
# define F_DAY      2
# define L_YEAR     2024
# define L_MONTH    3
# define L_DAY      25

class BitcoinExchange
{
    private:
        /* OCCF */
        BitcoinExchange(const BitcoinExchange& origin);
        BitcoinExchange& operator=(const BitcoinExchange& origin);

        /* member variable */
        std::map<std::string, double> _database;

        /* member function */
        void        _checkDatabase(void);
        std::string _checkDate(const std::string& date);
        bool        _checkDateForm(const std::string& date);
        bool        _checkGregorian(int year, int day);
        double      _checkPrice(const std::string& price, bool input);

    public:
        /* OCCF */
        BitcoinExchange();
        ~BitcoinExchange();

        /* member function */
        void calculate_bitcoin(const char* input);
};

#endif