#include "./BitcoinExchange.hpp"

/* OCCF: constructor */
BitcoinExchange::BitcoinExchange()
{
    this->_checkDatabase();
}

/* OCCF: destructor */
BitcoinExchange::~BitcoinExchange()
{}

/* member function: public */
void BitcoinExchange::calculate_bitcoin(const char* input)
{
    std::ifstream   ifs(input);
    std::string     buffer;

    if (ifs.is_open() == false)
        throw std::logic_error("Error: could not open file.");
    while (std::getline(ifs, buffer)) {
        try {
            if (buffer == "date | value")
                continue;
            size_t pos = 0;
            pos = buffer.find(" | ", pos);
            if (pos == std::string::npos || buffer.size() < 14)
                throw std::logic_error("Error: bad input form => " + buffer);
            std::string date = this->_checkDate(buffer.substr(0, pos));
            double value = this->_checkPrice(buffer.substr(pos + 3), true);
            std::map<std::string, double>::iterator iter = this->_database.upper_bound(date);
            if (iter == this->_database.begin())
                throw std::logic_error("Error: no data in database");
            std::cout << date << " => " << value << " = " << value * (--iter)->second << std::endl;
        } catch(const std::exception& e) {
            std::cerr << e.what() << std::endl;
        }
    }
    ifs.close();
}

/* member function: private */
void BitcoinExchange::_checkDatabase(void)
{
    std::ifstream   ifs(DATABASE);
    std::string     buffer;

    if (ifs.is_open() == false)
        throw std::logic_error("Error: database could not open file.");
    while (std::getline(ifs, buffer)) {
        if (buffer == "date,exchange_rate")
            continue;
        size_t pos = 0;
        pos = buffer.find(',', pos);
        if (pos == std::string::npos || buffer.size() < 12)
            throw std::logic_error("Error: bad data form");
        std::string date = this->_checkDate(buffer.substr(0, pos));
        double price = this->_checkPrice(buffer.substr(pos + 1), false);
        this->_database.insert(std::make_pair(date, price));
    }
    ifs.close();
}

std::string BitcoinExchange::_checkDate(const std::string& date)
{
    if (this->_checkDateForm(date) == false)
        throw std::logic_error("Error: bad date form => " + date);
    /**
     < 유효성 검사 >
     * year: 2009 ~ 2024(must 4자리)
     * month: 1 ~ 12
     * day: 1 ~ 31(그레고리력, 달별 날짜 적용)
       - month(1, 3, 5, 7, 8, 10, 12) -> 31
       - month(2) -> 28 (윤년: 29)
       - 나머지 -> 30
    */
    char*   pos = NULL;
    int     year = strtod(date.substr(0, 4).c_str(), &pos);
    int     month = strtod(date.substr(FIRSTBAR + 1, 2).c_str(), &pos);
    int     day = strtod(date.substr(SECONDBAR + 1, 2).c_str(), &pos);

    if (month < 1 || month > 12 || day < 1 || day > 31)
        throw std::logic_error("Error: bad date => " + date);
    if ((month < 8 && month % 2 == 1) || (month > 7 && month % 2 == 0)) {
        if (day > 31)
            throw std::logic_error("Error: bad date => " + date);
    } else if (month == 2) {
        if (this->_checkGregorian(year, day) == false)
            throw std::logic_error("Error: bad date(Gregorian) => " + date);
    } else {
        if (day > 30)
            throw std::logic_error("Error: bad date => " + date);
    }
    if ((year < F_YEAR) || (year == F_YEAR && month < F_MONTH) ||
        (year == F_YEAR && month == F_MONTH && day < F_DAY))
        throw std::logic_error("Error: bad date(past) => " + date);
    if ((year > L_YEAR) || (year == L_YEAR && month > L_MONTH) ||
        (year == L_YEAR && month == L_MONTH && day > L_DAY))
        throw std::logic_error("Error: bad date(future) => " + date);
    return date;
}

bool BitcoinExchange::_checkDateForm(const std::string& date)
{
    if (date.length() != 10)
        return false;
    for (int i = 0; i < 10; ++i) {
        if (i == FIRSTBAR || i == SECONDBAR) {
            if (date[i] != '-')
                return false;
        } else {
            if (date[i] < '0' || date[i] > '9')
                return false;
        }
    }
    return true;
}

bool BitcoinExchange::_checkGregorian(int year, int day)
{
    if (year % 400 == 0) {
        if (day > 29)
            return false;
    } else if (year % 100 != 0 && year % 4 == 0) {
        if (day > 29)
            return false;
    } else {
        if (day > 28)
            return false;
    }
    return true;
}

double BitcoinExchange::_checkPrice(const std::string& price, bool input)
{
    double  realPrice;
    char*   pos;

    realPrice = strtod(price.c_str(), &pos);
    if (*pos != '\0')
        throw std::logic_error("Error: not a number.");
    if (realPrice < 0.0 || (input == true && realPrice == 0.0))
        throw std::logic_error("Error: not a positive number.");
    if (input == true && realPrice > 1000.0) // between 0 and 1000
        throw std::logic_error("Error: too large a number.");
    return realPrice;
}