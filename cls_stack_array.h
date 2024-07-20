#pragma once
#include "cls_dynamic_array.h"

template <class class_type> class cls_stack_array
{
protected:
	cls_dynamic_array <class_type> stack;

public:
	void push(class_type data)
	{
		stack.insert_at_beginning(data);
	}

	void print()
	{
		stack.print_array();
	}

	int size()
	{
		return stack.size();
	}

	bool is_empty()
	{
		return stack.is_empty();
	}

	class_type top()
	{
		return stack.at(0);
	}

	class_type bottom()
	{
		return stack.at(size() - 1);
	}

	void pop()
	{
		stack.delete_first_item();
	}

	class_type at(int index)
	{
		return stack.at(index);
	}

	void reverse()
	{
		stack.reverse();
	}

	void update(int index, class_type update_data)
	{
		stack.set_item(index, update_data);
	}

	void insert_after(int prev_index, class_type inserted_data)
	{
		stack.insert_after(prev_index, inserted_data);
	}

	void insert_at_top(class_type inserted_data)
	{
		stack.insert_at_beginning(inserted_data);
	}

	void insert_at_bottom(class_type inserted_data)
	{
		stack.insert_at_end(inserted_data);
	}

	void clear()
	{
		stack.clear();
	}
};