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
        printf("tmp->get_prev() = %d\n", tmp->get_prev());
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

