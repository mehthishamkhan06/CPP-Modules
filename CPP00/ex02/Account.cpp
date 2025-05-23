#include "Account.hpp"
#include <iostream>
#include <ctime>
#include <iomanip>  // for std::setfill and std::setw


// Static member initialization
int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit) : _accountIndex(_nbAccounts), _amount(initial_deposit), _nbDeposits(0), _nbWithdrawals(0) {
    this->_totalAmount += initial_deposit;
    this->_nbAccounts++;
    this->_displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";amount:" << this->_amount << ";created" << std::endl;
}

Account::~Account() {
    this->_displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";amount:" << this->_amount << ";closed" << std::endl;
}


void Account::makeDeposit(int deposit){
    this->_displayTimestamp();

    int prev_amount = _amount;
    this->_amount += deposit;
    this->_totalAmount += deposit;
    this->_nbDeposits++;
    this->_totalNbDeposits++;
    
    std::cout <<"index: " << this->_accountIndex << ";p_amount:" << prev_amount <<";deposit:" << deposit << ";amount:" << this->_amount << ";nb_deposits:" << this->_nbDeposits << std::endl;
}

bool	Account::makeWithdrawal( int withdrawal ){
    this->_displayTimestamp();
    int prev_amount = this->_amount;
    if (this->_amount < withdrawal)
    {
        std::cout << "index:" << this->_accountIndex << ";p_amount:" << prev_amount << ";withdrawal:refused" << std::endl;
        return (false);
    }
    this->_amount -= withdrawal;
    this->_totalAmount -= withdrawal;
    this->_nbWithdrawals++;
    this->_totalNbWithdrawals++;
    std::cout << "index:" << this->_accountIndex << ";p_amount:" << prev_amount << ";withdrawal:" << withdrawal << ";amount:" << this->_amount << ";nb_withdrawals:" << this->_nbWithdrawals << std::endl;
    
    return (true);
}

void	Account::displayStatus( void ) const{
    this->_displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";amount:" << this->_amount << ";nb_deposits:" << this->_nbDeposits << ";nb_withdrawals:" << this->_nbWithdrawals << std::endl;
}

int		Account::checkAmount( void ) const{
    return (_amount);
}

//static functions
void	Account::displayAccountsInfos( void ){
    _displayTimestamp();
    std::cout << "accounts:" << _nbAccounts << ";total:" << _totalAmount << ";deposits:" << _totalNbDeposits << ";withdrawals:" << _totalNbWithdrawals << std::endl;
}

int	Account::getNbAccounts( void )
{
    return (_nbAccounts);
}

int	Account::getTotalAmount( void )
{
    return (_totalAmount);
}

int	Account::getNbDeposits( void )
{
    return (_totalNbDeposits);
}
int	Account::getNbWithdrawals( void ){
    return (_totalNbWithdrawals);
}

void	Account::_displayTimestamp(void)
{
	std::time_t currentTime = std::time(NULL);
	std::tm *localTime = std::localtime(&currentTime);

	std::cout << "["
		<< localTime->tm_year + 1900
		<< std::setfill('0') << std::setw(2) << localTime->tm_mon + 1
		<< std::setfill('0') << std::setw(2) << localTime->tm_mday << "_"
		<< std::setfill('0') << std::setw(2) << localTime->tm_hour
		<< std::setfill('0') << std::setw(2) << localTime->tm_min
		<< std::setfill('0') << std::setw(2) << localTime->tm_sec
		<< "] ";
}
