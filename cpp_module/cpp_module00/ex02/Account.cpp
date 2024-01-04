#include "./Account.hpp"
#include <iostream>
#include <ctime>

/* static variables */
int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

/* static member functions */
int	Account::getNbAccounts(void)
{
	return Account::_nbAccounts;
}

int	Account::getTotalAmount(void)
{
	return Account::_totalAmount;
}

int	Account::getNbDeposits(void)
{
	return Account::_totalNbDeposits;
}

int	Account::getNbWithdrawals(void)
{
	return Account::_totalNbWithdrawals;
}

void	Account::displayAccountsInfos(void)
{
	Account::_displayTimestamp();
	std::cout << "accounts:" << Account::getNbAccounts() << ";" \
			  << "total:" << Account::getTotalAmount() << ";" \
			  << "deposits:" << Account::getNbDeposits() << ";" \
			  << "withdrawals:" << Account::getNbWithdrawals() \
			  << std::endl;
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

/* ********************************************************************* */
/* constructor */
Account::Account()
	: _accountIndex(Account::_nbAccounts), _amount(0)
	, _nbDeposits(0), _nbWithdrawals(0)
{
	/* default concstructor */
	Account::_nbAccounts++;
}

Account::Account(int initial_deposit)
	: _accountIndex(Account::_nbAccounts), _amount(initial_deposit)
	, _nbDeposits(0), _nbWithdrawals(0)
{
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";" \
			  << "amount:" << this->_amount << ";" \
			  << "created" \
			  << std::endl;

	Account::_nbAccounts++;
	Account::_totalAmount += initial_deposit;
}

/* destructor */
Account::~Account()
{
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";" \
			  << "amount:" << this->_amount << ";" \
			  << "closed" \
			  << std::endl;
}

/* member functions */
void	Account::makeDeposit(int deposit)
{
	int	prev_amount = this->_amount;

	this->_amount += deposit;
	this->_nbDeposits++;
	Account::_totalAmount += deposit;
	Account::_totalNbDeposits++;

	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";" \
			  << "p_amount:" << prev_amount << ";" \
			  << "deposit:" << deposit << ";" \
			  << "amount:" << this->_amount << ";" \
			  << "nb_deposits:" << this->_nbDeposits \
			  << std::endl;
}

bool	Account::makeWithdrawal(int withdrawal)
{
	bool	if_withdrawal = true;
	int		prev_amount = this->_amount;

	if (withdrawal > checkAmount())
		if_withdrawal = false;
	else
	{
		this->_amount -= withdrawal;
		this->_nbWithdrawals++;
		Account::_totalAmount -= withdrawal;
		Account::_totalNbWithdrawals++;
	}

	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";" \
			  << "p_amount:" << prev_amount << ";" \
			  << "withdrawal:";
	if (if_withdrawal == false)
		std::cout << "refused" << std::endl;
	else
	{
		std::cout << withdrawal << ";" \
				  << "amount:" << this->_amount << ";" \
				  <<  "nb_withdrawals:" << this->_nbDeposits \
				  << std::endl;
	}

	return if_withdrawal;
}

int	Account::checkAmount(void) const
{
	return this->_amount;
}

void	Account::displayStatus(void) const
{
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";" \
			  << "amount:" << this->_amount << ";" \
			  << "deposits:" << this->_nbDeposits << ";" \
			  << "withdrawals:" << this->_nbWithdrawals \
			  << std::endl;
}
