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
	this->_fps = 1000000 / 60;
}

Game::~Game() {

 }

Game::Game( Game const& src) {
	
	*this = src;
	return;
}

Game				&Game::operator=(Game const & rhs) {
	(void)rhs;
	return *this;
}

void				Game::initkeys(void) {
	for (int i = 0; i < 262; i++)
		this->keys[i] = false;
}

unsigned long int	Game::getTime(void) {
	struct timeval tv;
	gettimeofday(&tv, 0);
	return (tv.tv_usec);
}

int					Game::getRandom_value(size_t min, size_t max)
{
	return (((Game::getTime()) % (max + min)) - min);
}

void				Game::start(void) {
	this->_start_time		= time(NULL);
	this->_score			= 0;
	this->_x				= 0;
	this->_y				= 0;

	getmaxyx(stdscr, this->_y, this->_x);
	this->_window			= newwin(this->_y - 1, this->_x - 1, 0, 0);
	nodelay(this->_window, true);
	keypad(this->_window, true);

	this->_player = new Spaceship(1, this->_x / 2, this->_y - 1, COLOR_YELLOW);

	this->addEntity(this->_player);
	this->run();
}

void				Game::hookEntryKeys(void)
{
	int key = 0;

	/*if (GetAsyncKeyState(VK_DOWN))
		this->keys[KEY_DOWN] = true;
	if (GetAsyncKeyState(VK_RIGHT))
		this->keys[KEY_RIGHT] = true;
	if (GetAsyncKeyState(VK_UP))
		this->keys[KEY_UP] = true;
	if (GetAsyncKeyState(VK_LEFT))
		this->keys[KEY_RIGHT] = true;*/
	key = wgetch(this->_window);
	this->keys[key] = true;
}

void				Game::run(void) {

	int start_while = 0;
	int i = 0;
	int size = 0;
	int score = 0;
	while (true)
	{
		this->initkeys();
		while (1)
		{
			this->hookEntryKeys();
			if ((Game::getTime() - start_while) > (unsigned long int)(this->_fps))
				break ;
		}
		start_while = Game::getTime();
		clear();

		mvprintw(0, 0, "score : %d", score);
		mvprintw(0, this->_x - 8, "pdv : %d", this->_player->getHitPoint());
		//Colission
		this->checkColision();
		//enemy
		if (i > 3)
		{
			this->moveEntity(2, 0, 1);
			i = 0;
		}
		//Colission
		this->checkColision();
		//projectil enemy
		this->moveEntity(3, 0, 1);
		//projectil
		this->moveEntity(4, 0, -1);
		//WORK
		this->pressKeyShip(this->keys);
		//add Enemy
		this->addEnemy();

		this->update();
		this->deleteOutOfMapEntity();
		refresh();
		if (size == 60)
		{
			int x, y;

			getmaxyx(stdscr, y, x);
			this->_y = y;
			this->_x = x;
			size = 0;
		}
		score++;
		size++;
		i++;
	}
}

void				Game::addEnemy(void) {
	int random = Game::getRandom_value(1,10);

	if (random == 2)
	{
		Enemy *enemy = new Enemy(2, Game::getRandom_value(3,this->_x - 4),1, COLOR_RED);
		this->addEntity(enemy);
	}
}

void				Game::gameOver(void) {
	t_entity *tmp;
	t_entity *next;

	tmp = this->entity;
	while (tmp != NULL)
	{
		if (tmp->entity->getType() != 1)
		{
			next = tmp->right;
			removeEntity(tmp->entity);
			tmp = next;
			continue ;
		}
		tmp = tmp->right;
	}
	clear();
	for (int i = 0; i < this->_x; i++)
	{
		mvprintw((this->_y / 2) - 1, i, "#");
		mvprintw((this->_y / 2) + 1, i, "#");
	}
	mvprintw((this->_y / 2), (this->_x / 2) - 6, "Restart : Enter");
	if (getch() == 10)
	{
		this->start();
	}
	else
	{
		endwin();
		exit(0);
	}
}

void				Game::checkColision(void) {
	t_entity *tmp;
	t_entity *next;

	tmp = this->entity;
	while (tmp != NULL)
	{
		next = tmp->right;
		if (tmp->entity->getType() != 1)
		{
			int entity_width = tmp->entity->getWidth() + 1;
			while (entity_width >= 0)
			{
				AEntity *colled = this->getEntityByPos((tmp->entity->getX() + entity_width), tmp->entity->getY());

				if (colled != NULL && colled->getType() != tmp->entity->getType())
				{
					colled->takeDamage(1);
					tmp->entity->takeDamage(1);
					if (colled->getHitPoint() <= 0)
					{
						removeEntity(colled);
						if (colled->getType() == 1)
						{
							this->gameOver();
							return ;
						}
						//Evite pointer NULL
						this->checkColision();
					}
					if (tmp->entity->getHitPoint() <= 0)
							removeEntity(tmp->entity);
					break ;
				}
				entity_width--;
			} 
		}
		tmp = next;
	}
}

AEntity				*Game::getEntityByPos(int x, int y) {
	t_entity *tmp;

	tmp = this->entity;
	while (tmp != NULL)
	{
		int entity_width = tmp->entity->getWidth();
		while (entity_width > 0)
		{
			if ((tmp->entity->getX() + entity_width) == x && tmp->entity->getY() == y)
				return (tmp->entity);
			entity_width--;
		}
		tmp = tmp->right;
	}
	return (NULL);
}

void				Game::deleteOutOfMapEntity(void) {
	t_entity *tmp;
	t_entity *next;

	tmp = this->entity;
	while (tmp != NULL)
	{
		next = tmp->right;
		if (tmp->entity->getType() != 1)
		{
			if (tmp->entity->getY() < 0 || tmp->entity->getY() > this->_y)
				removeEntity(tmp->entity);
		}
		tmp = next;
	}
}

void				Game::update(void) {
	t_entity *tmp;

	tmp = this->entity;
	while (tmp != NULL)
	{
		tmp->entity->update();
		tmp = tmp->right;
	}
}

void				Game::moveEntity(int type, int x, int y) {
	t_entity *tmp;

	tmp = this->entity;
	while (tmp != NULL)
	{
		if (tmp->entity->getType() == type)
		{
			tmp->entity->move(x, y);
		}
		tmp = tmp->right;
	}
}

void				Game::pressKeyShip(bool *keys) {
	if ((this->_player->getX() + this->_player->getWidth()) > this->_x)
		this->moveEntity(1, -((this->_player->getX() + this->_player->getWidth()) - this->_x), 0);
	if (this->_player->getY() > this->_y)
		this->moveEntity(1, 0, -(this->_player->getY() - (this->_y - 1)));
	if (keys[KEY_LEFT] && this->_player->getX() > 0)
		this->moveEntity(1, -1, 0);
	if (keys[KEY_RIGHT] && (this->_player->getX() + this->_player->getWidth()) < this->_x)
		this->moveEntity(1, 1, 0);
	if (keys[KEY_UP] && this->_player->getY() > 1)
		this->moveEntity(1, 0, -1);
	if (keys[KEY_DOWN] && this->_player->getY() < (this->_y - 1))
		this->moveEntity(1, 0, 1);
	if (keys[32] == true)
	{
		Projectil *projectil = new Projectil(4, this->_player->getX() + 2, this->_player->getY() - 1, COLOR_YELLOW);
		this->addEntity(projectil);
	}
}

void				Game::addEntity(AEntity *entity) {
	t_entity *tmp;
	t_entity *current = new t_entity;

	current->entity = entity;
	current->right = NULL;
	current->left = NULL;
	tmp = this->entity;
	if (tmp == NULL)
	{
		this->entity = current;
		return ;
	}
	while (tmp->right)
		tmp = tmp->right;
	tmp->right = current;
	current->left = tmp;
}


void				Game::removeEntity(AEntity *entity)
{
	t_entity *tmp;

	tmp = this->entity;
	while (tmp != NULL)
	{
		if (tmp->entity == entity)
		{
			if (tmp->left != NULL && tmp->right != NULL)
			{
				tmp->right->left = tmp->left;
				tmp->left->right = tmp->right;
			}
			else if (tmp->left != NULL)
			{
				tmp->left->right = NULL;
			}
			else if (tmp->right != NULL)
			{
				tmp->right->left = NULL;
			}
			if (this->entity->entity == entity)
			{
				if (tmp->left != NULL)
					this->entity = tmp->left;
				else
					this->entity = NULL;
			}
			break ;
		}
		tmp = tmp->right;
	}
	delete tmp;
	//delete entity;
}