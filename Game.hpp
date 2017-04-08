/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Game.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjensen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/08 16:51:34 by gjensen           #+#    #+#             */
/*   Updated: 2017/04/08 16:51:38 by gjensen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_CLASS_H
# define GAME_CLASS_H

#include <iostream>
#include <curses.h>
#include <ncurses.h>
#include <unistd.h>
#include <sys/time.h>

#include "Spaceship.hpp"

class Game {

private:

	long int			_start_time;
	int					_score;
	bool				keys[261];
	int					_x;
	int					_y;
	int					_fps;
	WINDOW				*_window;
	Spaceship			*_player;

	void				initkeys(void);
	void				hookEntryKeys(void);

public:
	Game();
	~Game(void);

								Game(Game const& src);
	Game						&operator=(Game const & rhs);

	unsigned long int			getTime(void);
	int							getRandom_value(size_t min, size_t max);
	void						run(void);
	void						start(void);

	static unsigned long int	getCurrentTime(void);

};


#endif