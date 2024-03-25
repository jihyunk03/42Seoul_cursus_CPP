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

}







/* member function: private */
void BitcoinExchange::_checkDatabase(void)
{
    std::ifstream   ifs(DATABASE);
    std::string     buffer;

    if (ifs.is_open() == false)
        throw std::logic_error("Error: database could not open file.");
    while (std::getline(ifs, buffer))
    {
        if (buffer == "date, exchange_rate")
            continue;
        size_t pos = 0;
        pos = buffer.find(',', pos);
        if (pos != LIMITER)     // abort 주의
            throw std::logic_error("");
        std::string date = this->_checkDate(buffer.substr(0, pos));
        double price = this->_checkPrice(buffer.substr(pos + 1));
        this->_database.insert(std::make_pair(date, price));
    }
}

std::string BitcoinExchange::_checkDate(const std::string& date)
{
    if (this->_checkDateForm(date) == false)
        throw std::logic_error("Error: bad date form => " + date);
    /**
     < 유효성 검사 >
     * year: 2009 ~ (4자리)
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

    if (year < 2009 || month < 1 || month > 12 || day < 1 || day > 31)
        throw std::logic_error("Error: bad date => " + date);
    if (month < 8 && month % 2 == 1 || month > 7 && month % 2 == 0)
        if (day > 31)
            throw std::logic_error("Error: bad date => " + date);
    else if (month == 2)
        if (this->_checkGregorian(year, day) == false)
            throw std::logic_error("Error: bad date(Gregorian) => " + date);
    else
        if (day > 30)
            throw std::logic_error("Error: bad date => " + date);
    if ((year > YEAR) || (year == YEAR && month > MONTH) || (year == YEAR && month == MONTH && day > DAY))
        throw std::logic_error("Error: bad date(future) => " + date);
    return date;
}

bool BitcoinExchange::_checkDateForm(const std::string& date)
{
    if (date.length() != 10)
        return false;
    for (int i = 0; i < 10; ++i)
    {
        if (i == FIRSTBAR || i == SECONDBAR)
            if (date[i] != '-')
                return false;
        else
            if (date[i] < '0' || date[i] > '9')
                return false;
    }
    return true;
}

bool BitcoinExchange::_checkGregorian(int year, int day)
{
    if (year % 400 == 0)
        if (day > 29)
            return false;
    else if (year % 100 != 0 && year % 4 == 0)
        if (day > 29)
            return false;
    else
        if (day > 28)
            return false;
    return true;
}

double BitcoinExchange::_checkPrice(const std::string& price)
{
    double      realPrice;
    char*       pos;

    realPrice = strtod(price.c_str(), &pos);
    // pos == '\0'인지 검사
    // if (pos != std::string::npos)
    //     throw

}