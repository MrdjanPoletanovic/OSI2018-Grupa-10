#define _CRT_SECURE_NO_WARNINGS
#include "statistika.h"
#include <utility>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <iomanip>


Node::Node() : Node(0, "", "")
{}


Node::Node(int r, const std::string& s, const std::string& t) : rezultat(r), poruka(s), vrijeme(t)
{}


Node KruzniBafer::errorNode = Node(-1, "greska", "greska");


KruzniBafer::KruzniBafer() : niz(new Node[MAX]), front(0), rear(0)
{}


KruzniBafer::KruzniBafer(const KruzniBafer& other)
{
	copy(other);
}


KruzniBafer::KruzniBafer(KruzniBafer&& other)
{
	move(std::move(other));
}


KruzniBafer& KruzniBafer::operator=(const KruzniBafer& other)
{
	if (this != &other)
	{
		this->~KruzniBafer();
		copy(other);
	}
	return *this;
}


KruzniBafer& KruzniBafer::operator=(KruzniBafer&& other)
{
	if (this != &other)
	{
		this->~KruzniBafer();
		move(std::move(other));
	}
	return *this;
}


void KruzniBafer::copy(const KruzniBafer& other)
{
	front = other.front;
	rear = other.rear;
	std::copy(other.niz, other.niz + MAX, niz);
}


void KruzniBafer::move(KruzniBafer&& other)
{
	front = std::move(other.front);
	rear = std::move(other.rear);
	niz = other.niz;
	other.niz = nullptr;
}


KruzniBafer::~KruzniBafer()
{
	if (niz != nullptr)
	{
		delete[] niz;
		niz = nullptr;
	}
	front = rear = 0;
}


void KruzniBafer::enqueue(int x, const std::string& poruka, const std::string& vrijeme)
{
	niz[rear] = Node(x, poruka, vrijeme);
	rear = (rear+1)%MAX;
	if (front == rear)
		front = (front+1)%MAX;
}


Node KruzniBafer::dequeue()
{
	if (front == rear)
		return errorNode;
	else
	{
		Node tmp = niz[front];
		front = (front+1)%MAX;
		return tmp;
	}
}


void KruzniBafer::print() const
{
	if (front != rear)
	{
		std::vector<Node> tmp = returnSorted();
		std::cout << "-------------------------------------------------------------------------------" << std::endl;
		std::cout << "| BODOVI |            PORUKA                           |       VRIJEME        |" <<std::endl;
		std::cout << "-------------------------------------------------------------------------------" << std::endl;
		for(auto x : tmp)
		{
			std::cout << "| "<< std::setw(6) <<x.rezultat << " |  " << std::setw(42) << x.poruka << " |  ";
			std::cout << std::setw(19) << x.vrijeme << " |" << std::endl;
		}
		std::cout << "-------------------------------------------------------------------------------" << std::endl;;
		std::cout << std::endl;
	}
	else
		std::cout << "Niste igrali igru. " << std::endl;
}


std::vector<Node> KruzniBafer::returnSorted() const
{
	std::vector<Node> tmp;
	for(int i=front; i != rear; i = (i+1)%MAX)
	{
		tmp.push_back(niz[i]);
	}
	std::sort(tmp.begin(), tmp.end(), [](const Node& n1, const Node& n2)
					  {
						  return n1.rezultat > n2.rezultat;
					  });
	return tmp;
}


KruzniBafer::KruzniBafer(std::ifstream& file) : KruzniBafer()
{
	std::string tmp1, tmp2;
	int bodovi;
	for(rear=0; rear<MAX-1; rear++)
	{
		std::getline(file, tmp1, ',');
		bodovi = std::stoi(tmp1);
		if (bodovi == -1)
			break;
		std::getline(file, tmp1, ',');
		std::getline(file, tmp2);
		niz[rear] = Node(bodovi, tmp1, tmp2);
	}
	for (int i = rear; i < MAX - 1; i++)
		std::getline(file, tmp1);
}


std::ostream& operator<<(std::ostream& stream, const Node& n)
{
	return stream << n.rezultat << "," << n.poruka << "," << n.vrijeme << "\n";
}


void KruzniBafer::writeToFile(std::fstream& file) const
{
	std::vector<Node> tmp = returnSorted();
	for(auto x : tmp)
		file << x;
	for(int i=tmp.size(); i<MAX-1; i++)
		file << errorNode;
}
