#include "list.h"

list::list(const char* name) :
	cur_size_(0),
	error_state_(0),
	name_(name),
	start_((printf("start_\n"), nullptr)),
	end_((printf("end_\n"), nullptr))
{
	assert(this && "You passed nullptr list to construct");
	assert(name && "You passed nullptr name to construct");
	printf("in %s\n", __PRETTY_FUNCTION__);

}

list::~list()
{
	assert(this && "You passed nullptr to destruct");
	printf("in %s\n", __PRETTY_FUNCTION__);


// * May be make all free, but class must call ~list_element

	list_element* tmp = nullptr;
	for (tmp = end_; (end_ != nullptr) && (tmp->get_prev() != nullptr); )
    {
        printf("free memory in ~list\n", tmp->get_prev());
        tmp = tmp->get_prev();

        free(tmp->get_next());
        tmp->set_next(nullptr);
    }

    free(tmp); 		// free start element


	cur_size_    = -1;
	error_state_ = -1;

	//free(name_);
	name_ = nullptr;

	start_ = nullptr;
	end_ = nullptr;
}

list_element::list_element(data_type data, list_element* next, list_element* prev) :
	data_(data),
	next_(next),
	prev_(prev)
{
	printf("in %s\n", __PRETTY_FUNCTION__);
	assert(this && "You passed nullptr to list_elem construct");
}

list_element::~list_element()
{
	assert(this && "You passed nullptr to ~list_element");
	printf("in %s\n", __PRETTY_FUNCTION__);
	free(next_);
	next_ = nullptr;
	free(prev_);
	prev_ = nullptr;
	data_ = POISON;
}

list_element* list::set_element_from_end(data_type number)
{
	assert(!isnan(number) && "number is nan");
	assert(this && "You passed nullptr to set_element_from_end");

	list_element* tmp = (list_element*) calloc (1, sizeof(list_element));

	if((start_ == nullptr) && (end_ == nullptr))  // cur_size_ == 0
	{
		tmp->set_data(number);
		tmp->set_next(nullptr);
		tmp->set_prev(nullptr);

		set_start(tmp);
		set_end(tmp);
	}
	else
	{
		tmp->set_data(number);
		tmp->set_prev(get_end());
		tmp->set_next(nullptr);

		(get_end())->set_next(tmp);

		set_end(tmp);
	}

	cur_size_++;

	return tmp;
}

list_element* list::set_element_from_start(data_type number)
{
	assert(!isnan(number) && "number is nan");
	assert(this && "You passed nullptr to set_element_from_start");

	list_element* tmp = (list_element*) calloc (1, sizeof(list_element));

	if((start_ == nullptr) && (end_ == nullptr))  // cur_size_ == 0
	{
		tmp->set_data(number);
		tmp->set_next(nullptr);
		tmp->set_prev(nullptr);

		set_start(tmp);
		set_end(tmp);
	}
	else
	{
		tmp->set_data(number);
		tmp->set_prev(nullptr);
		tmp->set_next(get_start());

		(get_start())->set_prev(tmp);

		set_start(tmp);
	}

	cur_size_++;

	return tmp;
}
