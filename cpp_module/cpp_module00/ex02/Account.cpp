#include "./Account.hpp"
#include <iostream>
#include <ctime>

int	_nbAccounts = 0;
int	_totalAmount = 0;
int	_totalNbDeposits = 0;
int	_totalNbWithdrawals = 0;

Account::Account(int initial_deposit)
{
	/* Constructor */
}

Account::~Account()
{
	/* Destructor */
}







void	Account::_displayTimestamp(void)
{
	/* print current-time */
	char		buffer[18];
	time_t		currtime;
	struct tm	*timeinfo;

	time(&currtime);
	timeinfo = localtime(&currtime);
	strftime(buffer, 18, "[%Y%m%d_%H%M%S]", timeinfo);
	std::cout << buffer << " ";
}
