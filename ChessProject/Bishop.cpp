//#include "Bishop.h"
//
//Bishop::Bishop(SDL_Renderer * renderer, SDL_Point coord, NAME name, TEAM team)
//	: Unit(renderer, coord, name, team)
//{
//}
//
//Bishop * Bishop::create(SDL_Renderer * renderer, SDL_Point coord, NAME name, TEAM team)
//{
//	Bishop * bishop = new Bishop(renderer, coord, name, team);
//
//	if (bishop && bishop->init())
//	{
//		return bishop;
//	}
//	else
//	{
//		delete bishop;
//		bishop = nullptr;
//		return bishop;
//	}
//}
//
//bool Bishop::init()
//{
//	if (!Unit::init())
//	{
//		return false;
//	}
//
//	switch (_team)
//	{
//	case Unit::TEAM::BLACK:
//		_unit = Button::create("assets/images/BlackBishop.png");
//		break;
//	case Unit::TEAM::WHITE:
//		_unit = Button::create(_renderer, "assets/images/WhiteBishop.png");
//		break;
//	}
//
//	dispose();
//
//	return true;
//}
//
//void Bishop::update()
//{
//	Unit::update();
//}
//
//void Bishop::render()
//{
//	Unit::render();
//}
