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

class Game {

private:

	long int			_start_time;
	int					_score;

public:
	Game();
	~Game(void);

						Game(Game const& src);
	Game				&operator=(Game const & rhs);

	unsigned long int	getTime(void);
	int					getRandom_value(size_t min, size_t max);
	void				run(void);
	void				start(void);

};


#endif