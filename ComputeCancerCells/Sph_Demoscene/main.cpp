#include "App.hpp"
#undef main


//template <typename T>
//struct Node
//{
//	Node *next;
//	Node *prev;
//	T value;
//	Node(T _value)
//		: next(nullptr)
//		, prev(nullptr)
//		, value(_value)
//	{}
//	Node()
//		: next(nullptr)
//		, prev(nullptr)
//	{}
//
//};
//
//Node<int> *randomFill(int size)
//{
//	if (size <= 0)
//		return 0;
//	Node<int> *root = new Node<int>(0);
//	auto r = root;
//	for (auto i = 0; i < size; ++i)
//	{
//		root->next = new Node<int>(rand());
//		root->next->prev = root;
//		root = root->next;
//	}
//	return r;
//}

//void quickSort(Node<int> *list, int size)
//{
//	int l = 0;
//	int r = size - 1;
//	while (l < r)
//	{
//
//	}
//}

//void reverse(Node<int> **list)
//{
//	auto t = *list;
//	auto last = list;
//	while (t)
//	{
//		auto temp = t->next;
//		std::swap(t->next, t->prev);
//		if (t)
//		{
//			*last = t;
//		}
//		t = temp;
//	}
//	list = last;
//}
//
//void bubbleSort(int *b, int s)
//{
//	while (s >= 2)
//	{
//		for (int i = 0; i < s - 1; ++i)
//		{
//			if (b[i] > b[i + 1])
//				std::swap(b[i], b[i + 1]);
//		}
//		--s;
//	}
//}
//
//void quickSort(int *b, int s)
//{
//	if (s < 2)
//		return;
//	auto p = b[s / 2];
//
//	int *r = b + s - 1; 
//	int *l = b;
//
//	while (l <= r)
//	{
//		if (*l < p)
//			++l;
//		else if (*r > p)
//			--r;
//		else
//		{
//			std::swap(*r, *l);
//			++l;
//			--r;
//		}
//	}
//	quickSort(b, r - b + 1);
//	quickSort(l, b + s - l);
//}

int main(int argc, char **argv)
{
//	auto size = 30;
//	auto list = randomFill(size);
//	auto t = list;
//	std::cout << "BEG : " << std::endl;
//	while (t)
//	{
//		std::cout << t->value << ", ";
//		t = t->next;
//	}
//	reverse(&list);
//	t = list;
//	std::cout << "RES : " << std::endl;
//	while (t)
//	{
//		std::cout << t->value << ", ";
//		t = t->next;
//	}
//
//{
//	size = 30;
//	int *r = new int[size]();
//	for (auto i = 0; i < size; ++i)
//	{
//		r[i] = rand();
//	}
//	std::cout << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl;
//	bubbleSort(r, size);
//	for (auto i = 0; i < size; ++i)
//	{
//		std::cout << r[i] << ", ";
//	}
//	std::cout << std::endl;
//}
//
//{
//	size = 30;
//	int *r = new int[size]();
//	for (auto i = 0; i < size; ++i)
//	{
//		r[i] = rand();
//	}
//	std::cout << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl;
//	quickSort(r, size);
//	for (auto i = 0; i < size; ++i)
//	{
//		std::cout << r[i] << ", ";
//	}
//	std::cout << std::endl;
//}

	try
	{
		App app;
		if (!app.init())
			return EXIT_FAILURE;
		app.generateBuffers(128 * 128);
		app.generateBuffers();
		while (app.run())
		{
		}
		app.deactivate();
	}
	catch (const std::exception &e)
	{
		std::cout << e.what();
		std::cout << std::endl;
	}
	return EXIT_SUCCESS;
}