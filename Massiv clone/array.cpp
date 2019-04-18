#include"array.h"


Array::Array()
{
	size = 12;
	els = new int[size];//при создании массива по умолчанию сразу выделяем память под 12 оценок
}

Array::Array(int value)
{
	size = 12;
	els = new int[size];
	for (int i = 0; i < size; i++)
		els[i] = value;
}

Array::Array(const Array & obj)
{
	this->size = obj.size;
	this->els = new int[size];
	for (int i = 0; i < size; i++)
		this->els[i] = obj.els[i];
}

Array::~Array()
{
	delete[] els;
}

int Array::arrsize()
{
	return size;
}

void Array::setSize(int size)
{
	this->size = size;
}

int Array::getSize()
{
	return size;
}

int Array::operator[](int index)
{
	return els[index];
}

bool Array::operator>(Array obj)
{
	return(average() > obj.average());
}

bool Array::operator<(Array obj)
{
	return(average() < obj.average());
}

bool Array::operator==(Array obj)
{
	return(average() == obj.average());
}

bool Array::operator!=(Array obj)
{
	return(average() != obj.average());
}



void Array::print()
{
	for (int i = 0; i < size; i++)
		cout << els[i] << " ";
	cout << endl;
}

int Array::max_el()
{
	int max = els[0];//or=-1; than > without=
	for (int i = 0; i < size; i++)
		if (els[i] >= max)
			max = els[i];

	return max;
}

int Array::min_el()
{
	int min = els[0];//or =13; than > without=
	for (int i = 0; i < size; i++)
		if (els[i] <= min)
			min = els[i];

	return min;
}

void Array::max_el_pos()
{
	string month[12] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun","July", "Aug", "Sept", "Oct", "Nov", "Dec"};

	int max = this->max_el();
	for (int i = 0; i < size; i++)
		if (els[i] == max)
			cout << month[i] << " ";
	cout << endl;
}

void Array::min_el_pos()
{
	string month[12] = { "Jan", "Feb", "Mar", "Apr", "May", "Jun","July", "Aug", "Sept", "Oct", "Nov", "Dec" };

	int min = this->min_el();

	for (int i = 0; i < size; i++)
		if (els[i] == min)
			cout << month[i] << " ";
	cout << endl;
}

double Array::sum()
{
	int sum = 0;
	for (int i = 0; i < size; i++)
		sum += els[i];
	return sum;
}

double Array::average()
{
	double average = sum()/size;
	return average;
}

Array& Array::random()
{
	for (int i = 0; i < size; i++)
		els[i] = rand() % 12;//or rand() % 5 + 8; чтобы от 5 до 12, а не от 0
	return *this;
}

Array Array::operator=(const Array & obj)
{
	this->size = obj.size;
	this->els = new int[size];
	for (int i = 0; i < size; i++)
		this->els[i] = obj.els[i];
	return *this;
}

Array Array::operator+(Array obj)
{
	Array tmp;
	for (int i = 0; i < size; i++)
		tmp.els[i] = els[i] + obj.els[i];
	return tmp;
}

Array& Array::operator+=(Array obj)
{
	for (int i = 0; i < size; i++)
		els[i] += obj.els[i];
	return *this;
}

Array Array::operator-(Array obj)
{
	Array tmp(*this);
	for (int i = 0; i < size; i++)
		tmp.els[i] -= obj.els[i];
	return tmp;
}

istream & operator>>(istream & is, Array & obj)
{
	for (int i = 0; i < obj.size; i++)
		is >> obj.els[i];
	return is;
}

ostream & operator<<(ostream & os, Array obj)
{
	for (int i = 0; i < obj.size; i++)
		os << obj.els[i] << " ";
	os << endl;
	return os;
}