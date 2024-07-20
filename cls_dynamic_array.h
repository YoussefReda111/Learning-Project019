#pragma once
#include <vector>

template <class class_type> class cls_dynamic_array
{
protected:
	int _size;
	class_type* original_array;

public:
	cls_dynamic_array(int size = 0)
	{
		if (size < 0) _size = 0;
		else _size = size;
		original_array = new class_type[_size];
	}

	~cls_dynamic_array()
	{
		delete[] original_array;
	}

	void set_item(int index, class_type item_data)
	{
		if (index >= _size) return;
		original_array[index] = item_data;
	}

	bool is_empty()
	{
		return (_size == 0);
	}

	int size()
	{
		return _size;
	}

	void resize(int new_size)
	{
		if (new_size < 0) new_size = 0;
		if (_size != new_size)
		{
			int size = (new_size < _size) ? new_size : _size;
			vector <class_type> temp_vec;
			for (int i = 0; i < size; i++) temp_vec.push_back(original_array[i]);
			delete[] original_array;
			original_array = new class_type[new_size];
			for (int i = 0; i < size; i++) original_array[i] = temp_vec[i];
			_size = new_size;
		}
	}

	void reverse()
	{
		for (int i = 0; i < _size / 2; i++)
		{
			class_type temp = original_array[i];
			original_array[i] = original_array[_size - 1 - i];
			original_array[_size - 1 - i] = temp;
		}
	}

	class_type at(int index)
	{
		return original_array[index];
	}

	void clear()
	{
		delete[] original_array;
		_size = 0;
		original_array = new class_type[_size];
	}

	void delete_item_at(int index)
	{
		if (index >= 0 && index < _size)
		{
			_size--;
			class_type* temp_arr = new class_type[_size];
			for (int i = 0, j = 0; i <= _size; i++)
			{
				if (i == index) continue;
				temp_arr[j++] = original_array[i];
			}
			delete[] original_array;
			original_array = new class_type[_size];
			original_array = temp_arr;
		}
	}

	void delete_first_item()
	{
		delete_item_at(0);
	}

	void delete_last_item()
	{
		delete_item_at(_size - 1);
	}

	int find(class_type search_data)
	{
		for (int index = 0; index < _size; index++) if (original_array[index] == search_data) return index;
		return -1;
	}

	void delete_item(class_type deleted_data)
	{
		delete_item_at(find(deleted_data));
	}

	void insert_at(int index, class_type inserted_data)
	{
		if (index >= 0 && index <= _size)
		{
			_size++;
			class_type* temp_arr = new class_type[_size];
			for (int i = 0, j = 0; i < _size; i++)
			{
				if (i == index) temp_arr[index] = inserted_data;
				else temp_arr[i] = original_array[j++];
			}
			delete[] original_array;
			original_array = new class_type[_size];
			original_array = temp_arr;
		}
	}

	void insert_at_beginning(class_type inserted_data)
	{
		insert_at(0, inserted_data);
	}

	void insert_at_end(class_type inserted_data)
	{
		insert_at(_size, inserted_data);
	}

	void insert_before(int index, class_type inserted_data)
	{
		if (index != _size + 1) insert_at(index - 1, inserted_data);
	}

	void insert_after(int index, class_type inserted_data)
	{
		if (index != -1) insert_at(index + 1, inserted_data);
	}

	void print_array()
	{
		for (int i = 0; i < _size; i++) cout << original_array[i] << ' ';
		cout << '\n';
	}
};