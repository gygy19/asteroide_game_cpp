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

Game& Game::operator=(Game const & rhs) {

	

	return *this;
}