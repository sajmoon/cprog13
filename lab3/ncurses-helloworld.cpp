#include <ncurses.h>
#include <map>
#include "map.h"
#include <cstring>

typedef void (*MenuActionPtrType) ( void );
typedef std::map<char, MenuActionPtrType> action_map;

int RUNNING = true;

class Player {
  int x, y;
  
  public:

    Player() {
      x = 10;
      y = 10;
    }

    void move_up() {
      x--;
    }

    void move_down() {
      x++;
    }

    void move_right() {
      y++;
    }

    void move_left() {
      y--;
    }

    int getX() {
      return x;
    }

    int getY() {
      return y;
    }
};

Player p;

void move_self_up( void ) {
  p.move_up();
}
void move_self_down( void ) {
  p.move_down();
}

void move_self_right( void ) {
  p.move_right();
}

void move_self_left( void ) {
  p.move_left();
}

void action_quit( void ) {
  start_color();
  init_pair(1, COLOR_RED, COLOR_BLACK);
	attron(COLOR_PAIR(1));
  printw("Shuttin down");
  getch();

  RUNNING = false;
}

void init_ncurses() {
  initscr();
  noecho();
  curs_set(0);
}

int main() {
  lab3::Map m;

  action_map actions;

  actions.insert(std::make_pair<char, MenuActionPtrType>('w', &move_self_up));
  actions.insert(std::make_pair<char, MenuActionPtrType>('d', &move_self_right));
  actions.insert(std::make_pair<char, MenuActionPtrType>('s', &move_self_down));
  actions.insert(std::make_pair<char, MenuActionPtrType>('a', &move_self_left));
  actions.insert(std::make_pair<char, MenuActionPtrType>('q', &action_quit));

  init_ncurses();
  // Require colour
  if(has_colors() == FALSE) {	
    endwin();
		printf("Your terminal does not support color\n");
    RUNNING = false;
	}

  int c;
  m.print_map();

  while(RUNNING) {
    
    c = getch();
    action_map::const_iterator start = actions.find(c);
    if (start != actions.end()){
      ((*start).second) ();
    }

    m.print_map();
  }
  endwin();
  return 0;
}
