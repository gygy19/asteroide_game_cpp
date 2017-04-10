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

/*
**Set all keys to released
*/
void				Game::initkeys(void) {
	for (int i = 0; i < 262; i++)
		this->keys[i] = false;
}

/*
**Get Microsecond time
*/
unsigned long int	Game::getTime(void) {
	struct timeval tv;
	gettimeofday(&tv, 0);
	return (tv.tv_usec);
}

/*
**get random value between min and max
*/
int					Game::getRandom_value(size_t min, size_t max)
{
	int random = ((Game::getTime()) % (max + min));

	if (random < (int)min)
		random = min;
	return (random);
}


bool			Game::_checkSpecialCommand(void) const{

	if (this->keys[27] == true)
	{
		clear();
		delwin(this->_window);
		return true;
	}
	return false;
}



void				Game::init(void)
{
	WINDOW *w;
    char list[3][10] = {"Easy", "Average", "Hard"};
    //char item[7];
    int ch, i = 1;
 	

    w = newwin( 10, 40, 1, 1 ); // create a new window
    box( w, 0, 0 ); // sets default borders for the window     
// now print all the menu items and highlight the first one
    mvwprintw(w, 0, 2, "FT_RETRO, Choose a difficulty:");
    for( i=0; i<3; i++ ) {
        if( i == 1 ) 
            wattron( w, A_STANDOUT ); // highlights the first item.
        else
            wattroff( w, A_STANDOUT );
        // sprintf(item, "%-7s",  list[i]);
        mvwprintw( w, i+1, 2, "%s", list[i] );
    }
 
    wrefresh( w ); // update the terminal screen
 
    i = 1;
    noecho(); // disable echoing of characters on the screen
    keypad( w, TRUE ); // enable keyboard input for the window.
    curs_set( 0 ); // hide the default screen cursor.  
       // get the input
    while(1){ 
         	ch = wgetch(w);
                // right pad with spaces to make the items appear with even width.
            // sprintf(item, "%-7s",  list[i]); 
            mvwprintw( w, i+1, 2, "%s", list[i] ); 
              // use a variable to increment or decrement the value based on the input.
            switch( ch ) {
                case KEY_UP:
                            i--;
                            i = ( i<0 ) ? 2 : i;
                            break;
                case KEY_DOWN:
                            i++;
                            i = ( i>2 ) ? 0 : i;
                            break;
                case 27:
                	wrefresh(w);
    				delwin( w );
    				endwin();
    				exit(0);         	
                case 10:
                	wrefresh(w);
                	delwin(w);
                	this->difficulty = i;
                	this->start();

            }
            // now highlight the next item in the list.
            wattron( w, A_STANDOUT );
             
            // sprintf(item, "%-7s",  list[i]);
            mvwprintw( w, i+1, 2, "%s", list[i]);
            wattroff( w, A_STANDOUT );
    }
    delwin( w );
}

/*
** set all started variable and run game
*/
void				Game::start() {
	this->_start_time		= time(NULL);
	this->_playerScore		= 0;
	this->_x				= 0;
	this->_y				= 0;
	int lives = 5;
	switch (this->difficulty) {
		case 0:
			lives = 5;
			this->_fps = 1000000 / 30;
			break ;
		case 1:
			lives = 3;
			this->_fps = 1000000 / 60;
			break ;
		case 2:
			lives = 1;
			this->_fps = 1000000 / 100;
			break ;
	}
	cbreak();
	clear();
	
	start_color();

	// get window x and window y
	getmaxyx(stdscr, this->_y, this->_x);

	//create ncurses window
	this->_window			= newwin(this->_y - 1, this->_x - 1, 0, 0);
	//create player ship
	this->_player			= new Spaceship(BLUE_TEAM, PLAYER, this->_x / 2, this->_y - 1, "<~^~>", lives, COLOR_YELLOW);

	//unlock wgetch
	nodelay(this->_window, true);
	//read special characters
	keypad(this->_window, true);

	//add player on entity list
	this->addEntity(this->_player);
	//launch game
	this->run();
}

/*
**Hook keys entry
*/
void				Game::hookEntryKeys(void)
{
	int key = 0;

	//Hook entry key
	key = wgetch(this->_window);

	//add key hooked to true
	if (key > 0 && key < 262)
		this->keys[key] = true;
}

/*
**Runnable member methods
*/
void				Game::run(void) {

	int start_while = 0;
	int i = 0;
	int size = 0;
	this->_playerScore = 0;


	while (true)
	{
		this->initkeys();
		while (1)
		{
			this->hookEntryKeys();
			if (this->_checkSpecialCommand() == true)
			{
				this->gameOver();
			}	
			if ((Game::getTime() - start_while) > (unsigned long int)(this->_fps))
				break ;
		}
		
		start_while = Game::getTime();
		//clear screen
		clear();
		
		//print header
		mvprintw(0, 0, "score : %d", this->_playerScore);
		mvprintw(0, this->_x - 8, "pdv : %d", this->_player->getHitPoint());


		//Colission before move enemy
		this->checkColision();
		//move enemy
		if (i > 3)
		{
			this->moveEntity(ENEMY, 0, 1);
			this->enemyShoot();
			i = 0;
		}
		//Colission after enemy moved
		this->checkColision();
		//move enemy projectil
		this->moveEntity(ENEMY_PROJECTIL, 0, 1);
		//move player projectil
		this->moveEntity(PLAYER_PROJECTIL, 0, -1);
		//check player keys entry
		this->pressKeyShip(this->keys);
		//add Enemy
		this->addEnemy();
		//remove all outOfRanged projectil
		this->deleteOutOfRangedProjectil();
		//remove all outed entity
		this->deleteOutOfMapEntity();
		//print all output
		this->update();
		//refresh output
		refresh();
		if (this->_player->getHitPoint() <= 0)
		{
			this->gameOver();
			return ;
		}
		// check screen resize
		if (size == 60)
		{
			int x, y;

			getmaxyx(stdscr, y, x);
			this->_y = y;
			this->_x = x;
			size = 0;
		}
		// this->_playerScore += 1;
		size++;
		i++;
	}
}

void				Game::addEnemy(void) {
	std::string symbols[3]	= {BIG_SHIP, MEDIUM_SHIP, LITTLE_SHIP};
	std::string	ship		= symbols[Game::getRandom_value(1, 2)];
	int	hit					= 1;


	if (Game::getRandom_value(1,20) < 3)
	{
		if (Game::getRandom_value(1,10) == 9)
		{
			ship = symbols[0];
			hit = 2;
		}
		int x = Game::getRandom_value(4,this->_x - 5);

		if (x < (int)(strlen(ship.c_str()) / 2) || x >= (int)(this->_x - strlen(ship.c_str())))
		{
			this->addEnemy();
			return ;
		}
		Spaceship *enemy = new Spaceship(RED_TEAM, ENEMY, x, 1, ship, hit, COLOR_RED);
		this->addEntity(enemy);
	
	}
}

void				Game::enemyShoot(void) {
	t_entity *tmp;

	tmp = this->entity;
	while (tmp != NULL)
	{
		if (tmp->entity->getType() == ENEMY && Game::getRandom_value(1,10) > 8)
		{
			Projectil *projectil = new Projectil(RED_TEAM, ENEMY_PROJECTIL, tmp->entity->getX() + 2, tmp->entity->getY() + 1, 10, COLOR_RED);
			this->addEntity(projectil);
		}
		tmp = tmp->right;
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
	removeEntity(this->_player);
	clear();
	for (int i = 0; i < this->_x; i++)
	{
		mvprintw((this->_y / 2) - 1, i, "#");
		mvprintw((this->_y / 2) + 1, i, "#");
	}
	mvprintw((this->_y / 2), (this->_x / 2 - 25), "Your score is %d !! Touch enter to restart..", this->_playerScore);
	char k = getch();
	if (k == 10)
		this->init();
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

			bool explode = false;
			int entity_height = tmp->entity->getHeight() - 1;

			while (entity_height >= 0 && explode == false)//check in all entity Height
			{
				int entity_width = tmp->entity->getWidth() + 1;

				while (entity_width >= 0 && explode == false)//check in all entity Width
				{
					AEntity *colled = this->getEntityByPos((tmp->entity->getX() + entity_width), tmp->entity->getY());

					if (colled != NULL && colled->getTeam() != tmp->entity->getTeam())//if collision OK
					{
						explode = true;
						colled->takeDamage(1);//take damage for target
						tmp->entity->takeDamage(1);//take damage for caster
						if (tmp->entity->getType() == PLAYER_PROJECTIL)
						{
							if (colled->getShipType().compare(BIG_SHIP) == 0)
								this->_playerScore += 30;
							else if (colled->getShipType().compare(LITTLE_SHIP) == 0)
								this->_playerScore += 10;
							else if (colled->getShipType().compare(MEDIUM_SHIP) == 0)
								this->_playerScore += 20;
						}
						if (colled->getHitPoint() <= 0 && colled->getType() != PLAYER)//if target is dead
							removeEntity(colled);
						if (tmp->entity->getType() == PLAYER_PROJECTIL\
							|| tmp->entity->getType() == ENEMY_PROJECTIL
							|| tmp->entity->getType() == ENEMY)
						{
							tmp->entity->explode();//projectil explode
							removeEntity(tmp->entity);//remove projectil
						}
						this->checkColision();
						return ;
					}
					entity_width--;
				}
				entity_height--;
			}
		}
		tmp = next;
	}
}

/*
**Search Entity in entity list
**Params :
**int x
**int y
*/
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

/*
**Check all entity out of map and remove it
**Params :
**(void) 
*/
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

void				Game::deleteOutOfRangedProjectil(void) {
	t_entity *tmp;
	t_entity *next;

	tmp = this->entity;
	while (tmp != NULL)
	{
		next = tmp->right;
		if (tmp->entity->getType() == ENEMY_PROJECTIL)
		{
			if (((dynamic_cast<Projectil*>(tmp->entity))->getY() - (dynamic_cast<Projectil*>(tmp->entity))->getStartY()) > (dynamic_cast<Projectil*>(tmp->entity))->getRange()) 
				removeEntity(tmp->entity);
		}
		tmp = next;
	}
}

/*
**Print all entity pixels
*/
void				Game::update(void) {
	t_entity *tmp;

	tmp = this->entity;
	while (tmp != NULL)
	{
		tmp->entity->update();
		tmp = tmp->right;
	}
}

/*
**Move entity by type to entity->y + (y arg) and entity->x + (x arg)
**Params:
**int type
**int x
**int y
*/
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

/*
**check all entry to effet and launch effect if good condition.
*/
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
		Projectil *projectil = new Projectil(BLUE_TEAM, PLAYER_PROJECTIL, this->_player->getX() + 2, this->_player->getY() - 1, -1, COLOR_YELLOW);
		this->addEntity(projectil);
	}
}

/*
**Add entity in list of Game::entity
*/
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

/*
**Remove Entity if contained
*/
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
	if (tmp == NULL)
		return ;
	delete tmp->entity;
	delete tmp;
}