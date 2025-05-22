#include "Account.hpp"
#include <iostream>
#include <ctime>


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
    std::cout <<"index: " << this->_accountIndex << ";amount" << this->_amount << std::endl;
    this->_amount = this->_nbDeposits;
}