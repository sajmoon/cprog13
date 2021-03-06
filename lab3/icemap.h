#ifndef ICEMAP_H
#define ICEMAP_H

#include "player.h"
#include "map.h"

namespace lab3{
	class Icemap : public Map{
	private:
		virtual void load_terrain();
	public: 
		Icemap();
		~Icemap();
		virtual std::string player_move_up();
      	virtual std::string player_move_down();
      	virtual std::string player_move_right();
      	virtual std::string player_move_left();
      	std::string possible_move(int, int, int, int);
	};
}
#endif