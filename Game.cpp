/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Game.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjensen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/08 17:11:50 by gjensen           #+#    #+#             */
/*   Updated: 2017/04/08 17:11:52 by gjensen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Game.hpp"

Game::Game() : {
	
}

Game::~Game() {

 }

Game::Game( Game const& src) {
	
	*this = src;
	return;
}

unsigned long int	Game::getTime(void) {
	return (time(NULL) - this->_start_time);
}

int					Game::getRandom_value(size_t min, size_t max)
{
	return (((time(NULL) + rand()) % (max + min)) - min);
}

void				Game::start(void) {
	this->_start_time		= time(NULL);
	this->_score			= 0;
	
	this->run();
}

void				Game::run(void) {
	
}

Game				&Game::operator=(Game const & rhs) {

	

	return *this;
}