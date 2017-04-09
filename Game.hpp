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

#include "AEntity.hpp"
#include "Spaceship.hpp"
#include "Enemy.hpp"
#include "Projectil.hpp"

class Game {

private:

	long int				_start_time;
	int						_score;
	bool					keys[261];
	int						_x;
	int						_y;
	int						_fps;
	WINDOW					*_window;
	Spaceship				*_player;

	typedef struct			s_entity
	{
		AEntity				*entity;
		struct s_entity		*left;
		struct s_entity		*right;
	}						t_entity;

	t_entity				*entity;

	void					initkeys(void);
	void					hookEntryKeys(void);

public:
	Game();
	~Game(void);

								Game(Game const& src);
	Game						&operator=(Game const & rhs);

	void						run(void);
	void						start(void);

	void						addEntity(AEntity *entity);
	void						removeEntity(AEntity *entity);

	void						update(void);
	void						moveEntity(int type, int x, int y);
	void						pressKeyShip(bool *keys);

	void						addEnemy(void);

	void						checkColision(void);
	void						deleteOutOfMapEntity(void);

	AEntity						*getEntityByPos(int x, int y);

	void						gameOver(void);

	static unsigned long int	getTime(void);
	static int					getRandom_value(size_t min, size_t max);
};


#endif