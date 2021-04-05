#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED

#include <TXLib.h>
#include "list_info.h"


using data_type = double;
#define POISON NAN

class list_element
{
private:

	data_type data_ = 0;
	list_element* next_ = nullptr;
	list_element* prev_ = nullptr;

public:

	list_element(data_type data = 0, list_element* next = nullptr, list_element* prev = nullptr);
	~list_element();

//! SETTERS

	void set_data(data_type new_data) {data_ = new_data;};
	void set_next(list_element* new_next) {next_ = new_next;};
	void set_prev(list_element* new_prev) {prev_ = new_prev;};


//! GETTERS

	data_type get_data() const {return data_;};
	list_element* get_next() {assert(this && "nullptr list_element in get_next()"); return next_;};
	list_element* get_prev() {assert(this && "nullptr list_element in get_prev()"); return prev_;};

};




class list:list_element
{
private:

	size_t cur_size_ = 0;
	size_t error_state_ = 0;
	const char* name_ = nullptr;

	list_element* start_ = nullptr;
	list_element* end_ 	= nullptr;

public:

	list(const char* name);
	~list();

//! SETTERS


//! GETTERS

	size_t get_cur_size() const {return cur_size_;};
	size_t get_error_state() const {return error_state_;};
	const char* get_name() const {return name_;};

};

#define CONSTRUCT(name)	\
	list name(#name);


#endif // LIST_H_INCLUDED
