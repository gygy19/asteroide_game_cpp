/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjensen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/08 16:53:50 by gjensen           #+#    #+#             */
/*   Updated: 2017/04/08 16:53:53 by gjensen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Game.hpp"

int		main(void)
{
	Game	*game = new Game();

	initscr();
	clear();
	noecho();
	cbreak();
	curs_set(FALSE);

	game->start();

	endwin();
	delete game;
	return 0;
}