/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aternero <aternero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 20:40:16 by aternero          #+#    #+#             */
/*   Updated: 2025/11/13 19:14:58 by aternero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <ctime>
#include <iostream>
#include <iomanip>

int			Account::_nbAccounts = 0;
int			Account::_totalAmount = 0;
int			Account::_totalNbDeposits = 0;
int			Account::_totalNbWithdrawals = 0;

void	Account::_displayTimestamp( void )
{
	std::time_t currentTime;
	std::tm* timeInfo;

	currentTime = std::time(0);
	timeInfo = std::localtime(&currentTime);
	std::cout << "[" << std::setfill('0')
		<< std::setw(4) << timeInfo->tm_year + 1900 << std::setw(2) << timeInfo->tm_mon + 1
		<< std::setw(2) << timeInfo->tm_mday << "_"
		<< std::setw(2) << timeInfo->tm_hour << std::setw(2) << timeInfo->tm_min
		<< std::setw(2) << timeInfo->tm_sec << "] ";
}

// Destructor ~Account()
/*	Esta función destruye una cuenta bancaria, actualizando los contadores
	globales e imprimiendo un mensaje "closed"*/

Account::~Account( void )
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";" << "amount:" << _amount << ";" << "closed" << std::endl;
}

// makeWithdrawal( int withdrawal )
/*	Esta función realiza un retiro en la cuenta bancaria, actualizando los
	valores correspondientes e imprimiendo un mensaje con los detalles del
	retiro*/

bool	Account::makeWithdrawal(int withdrawal)
{
	int	before;

	before = _amount;
	_displayTimestamp();
	if (withdrawal <= _amount)
	{
		_amount -= withdrawal;
		_totalAmount -= withdrawal;
		_nbWithdrawals++;
		_totalNbWithdrawals++;
		std::cout << "index:" << _accountIndex << ";p_amount:" << before << ";withdrawal:" << withdrawal << ";amount:" << _amount << ";nb_withdrawals:" << _nbWithdrawals << std::endl;
		return true;
	}
	else
	{
		std::cout << "index:" << _accountIndex << ";p_amount:" << before << ";withdrawal:refused" << std::endl;
		return false;
	}
}

// displayStatus( void ) const
/*	Esta función muestra el estado actual de la cuenta bancaria, incluyendo
	el saldo y otros detalles relevantes*/

void	Account::displayStatus(void) const
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";deposits:" << _nbDeposits << ";withdrawals:" << _nbWithdrawals << std::endl;
}

// checkAmount( void ) const
/*	Esta función devuelve la cantidad actual en la cuenta bancaria*/

int	Account::checkAmount(void) const
{
	return _amount;
}

// makeDeposit( int deposit )
/*	Esta función realiza un depósito en la cuenta bancaria, actualizando los
	valores correspondientes e imprimiendo un mensaje con los detalles del
	depósito*/

void	Account::makeDeposit(int deposit)
{
	int	before;

	before = _amount;
	_amount += deposit;
	_totalAmount += deposit;
	_nbDeposits++;
	_totalNbDeposits++;
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";p_amount:" << before << ";deposit:" << deposit << ";amount:" << _amount << ";nb_deposits:" << _nbDeposits << std::endl;
}

// displayAccountsInfos( void )
/*	Esta función muestra la información global de todas las cuentas bancarias,
	incluyendo el número total de cuentas, el monto total, el número total de
	depósitos y el número total de retiros*/

void	Account::displayAccountsInfos(void)
{
	_displayTimestamp();
	std::cout << "accounts:" << _nbAccounts << ";total:" << _totalAmount << ";deposits:" << _totalNbDeposits << ";withdrawals:" << _totalNbWithdrawals << std::endl;
}

// getNbWithdrawals( void )
/*	Esta función devuelve el número total de retiros realizados en todas las
	cuentas bancarias*/

int	Account::getNbWithdrawals(void)
{
	return _totalNbWithdrawals;
}

// getNbDeposits( void )
/*	Esta función devuelve el número total de depósitos realizados en todas las
	cuentas bancarias*/

int	Account::getNbDeposits(void)
{
	return _totalNbDeposits;
}

// getTotalAmount( void )
/*	Esta función devuelve la cantidad total de dinero en todas las cuentas bancarias*/

int	Account::getTotalAmount(void)
{
	return _totalAmount;
}

// getNbAccounts( void )
/*	Esta función devuelve el número total de cuentas bancarias*/

int Account::getNbAccounts(void)
{
	return _nbAccounts;
}

// Constructor Account( int initial_deposit )
/*	Esta función crea una nueva cuenta bancaria con dinero inicial asignando un
	índice único a la cuenta, actualizando los contadores globales e imprimiento
	un mensaje "created"*/

Account::Account(int initial_deposit)
{
	_accountIndex = _nbAccounts;
	_nbAccounts++;
	_amount = initial_deposit;
	_totalAmount += initial_deposit;
	_nbDeposits = 0;
	_nbWithdrawals = 0;
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";" << "amount:" << initial_deposit << ";" << "created" << std::endl;
}

