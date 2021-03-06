#ifndef CALENDAR_H
#define CALENDAR_H

#include <iostream>
#include "date.h"

#include <stdexcept>

#include "kattistime.h"

#include <map>
// http://www.cplusplus.com/reference/map/multimap/

namespace lab2 {
	template<class T>
	class Calendar {
	public:
		std::multimap<T, std::string> calendar;
		T current_date;
		Calendar() : current_date( T() ) {
		}

		template< class Q>
		Calendar(const Calendar<Q> & d) : current_date( d.current_date ) {

			typename std::multimap<Q,std::string>::const_iterator start = d.calendar.begin();
			typename std::multimap<Q,std::string>::const_iterator end = d.calendar.end(); 
			
		    for (; start!=end; ++start) {

		    	T tmpDate = (*start).first;
		    	add_event( (*start).second, tmpDate );
		    }
		}

		bool set_date(int y, int m, int d) {
			try {
				current_date = T(y,m,d);
			} catch (std::out_of_range & e) {
				return false;
			}
			return true;
		};

		bool add_event(std::string s) {
			return add_event(s, current_date.day(), current_date.month(), current_date.year());
		}

		bool add_event(const std::string s, int i) {
			return add_event(s, i, current_date.month(), current_date.year());
		}

		bool add_event(std::string event, int d, int m) {
			return add_event(event, d, m, current_date.year());
		}

		bool add_event(std::string event, int d, int m, int y) {
			try {
				T date(y, m , d);
				return add_event(event, date);
				
			} catch ( std::out_of_range & e) {
				return false;	
			}

			return true;
		}

		bool add_event(std::string event, T date) {
			typename std::multimap<T,std::string>::iterator it;
				std::pair <typename std::multimap<T, std::string>::iterator, typename std::multimap<T,std::string>::iterator> ret;
				ret = calendar.equal_range(date);

			    for (it=ret.first; it!=ret.second; ++it) {

			    	if (event == (*it).second) { // second är samma som event namn
			    		// duplicate!
			    		return false;
			    	}
			    }
			    
				calendar.insert(std::pair<T, std::string>(date, event));
				return true;
		}

		bool remove_event(std::string s, int d, int m, int y) {
			try{
				T date = T(y, m, d);
				typename std::multimap<T,std::string>::iterator it;
				std::pair <typename std::multimap<T, std::string>::iterator, typename std::multimap<T,std::string>::iterator> ret;
				ret = calendar.equal_range(date);

			    for (it=ret.first; it!=ret.second; ++it) {

			    	if (s == (*it).second) {
			    		// remove it
			    		calendar.erase(it);
		    			return true;
		    		}
		    	}
		    	return false;
			} catch ( std::out_of_range & e){
				
			}
			return false;

		};

		bool remove_event(std::string s, int d, int m) {
			return remove_event(s, d, m, current_date.year());
		};

		bool remove_event(std::string s, int d) {
			return remove_event(s, d, current_date.month(), current_date.year());
		}

		bool remove_event(std::string s) {
			return remove_event(s, current_date.day(), current_date.month(), current_date.year());
		}

		int events_count() {
			return calendar.size();
		}

		T &get_current_date() { return current_date; }

		void print_events() const {
			typename std::multimap<T, std::string>::const_iterator it;
	        
	        for (it = calendar.begin(); it != calendar.end(); it++) {
	           if (it->first > current_date) {
	                std::cout << it->first << " : " << it->second << std::endl;
	            }
	        }
		}
	};

	template <typename T>
    std::ostream & operator<<(std::ostream & os, const Calendar<T> & c) {
    	c.print_events();
        
    }
}

#endif

