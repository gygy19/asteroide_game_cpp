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

public:
	Game();
	~Game(void);

	Game(Game const& src);
	Game& 	operator=(Game const & rhs);

};


#endif