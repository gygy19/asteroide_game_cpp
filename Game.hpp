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
#include "Projectil.hpp"
#include "Boss.hpp"

#define RED_TEAM 1
#define BLUE_TEAM 0

#define EASY 0
#define	AVERAGE 1
#define	HARD 2

#define PLAYER 1
#define ENEMY 2
#define ENEMY_PROJECTIL 3
#define PLAYER_PROJECTIL 4
#define BOSS 5

#define BIG_SHIP "{/\\/|\\/\\}"
#define LITTLE_SHIP "<--->"
#define MEDIUM_SHIP "<-.->"

class Game {

private:

	long int				_start_time;
	unsigned int			_playerScore;
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
	bool					_checkSpecialCommand(void) const;



	

public:
	Game();
	~Game(void);


								Game(Game const& src);
	Game						&operator=(Game const & rhs);

	void						init(void);
	void						run(void);
	void						start(void);

	void						addEntity(AEntity *entity);
	void						removeEntity(AEntity *entity);

	void						update(void);
	void						moveEntity(int type, int x, int y);
	void						pressKeyShip(bool *keys);

	void						addEnemy(void);
	void						enemyShoot(void);

	void						checkColision(void);
	void						deleteOutOfRangedProjectil(void);
	void						deleteOutOfMapEntity(void);

	AEntity						*getEntityByPos(int x, int y);

	void						gameOver(void);

	static unsigned long int	getTime(void);
	static int					getRandom_value(size_t min, size_t max);
	int 						difficulty;
};


#endif