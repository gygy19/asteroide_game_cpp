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

Game::Game() {
	this->_fps = 1000 / 200;
}

Game::~Game() {

 }

Game::Game( Game const& src) {
	
	*this = src;
	return;
}

void				Game::initkeys(void) {
	for (int i = 0; i < 262; i++)
		this->keys[i] = false;
}

unsigned long int	Game::getTime(void) {
	return (time(NULL) - this->_start_time);
}

unsigned long int	Game::getCurrentTime(void) {
	struct timeval tv;
	gettimeofday(&tv, 0);
	return (tv.tv_usec);
}

int					Game::getRandom_value(size_t min, size_t max)
{
	return (((time(NULL) + rand()) % (max + min)) - min);
}

void				Game::start(void) {
	this->_start_time		= time(NULL);
	this->_score			= 0;
	this->_x				= 0;
	this->_y				= 0;

	getmaxyx(stdscr, this->_y, this->_x);
	this->_window			= newwin(this->_y - 1, this->_x - 1, 0, 0);
	nodelay(this->_window, true);
	this->_player = new Spaceship(this->_x / 2, this->_y - 1);
	this->run();
}

void				Game::hookEntryKeys(void)
{
	int key = 0;

	key = wgetch(this->_window);
	this->keys[key] = true;
}

void				Game::run(void) {

	int start_while = 0;
	while (true)
	{
		this->initkeys();
		while (true)
		{
			this->hookEntryKeys();
			if ((Game::getCurrentTime() - start_while) > (unsigned long int)(this->_fps))
				break ;
		}
		start_while = Game::getCurrentTime();
		clear();
		//WORK
		this->_player->update(this->keys);
		mvprintw(2, 2, "TEST, time:%d, fps:%d\n", (Game::getCurrentTime() - start_while), this->_fps);
		refresh();
	}
}

Game				&Game::operator=(Game const & rhs) {
	(void)rhs;
	return *this;
}