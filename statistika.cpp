#include "statistika.h"
#include <utility>
#include <algorithm>
#include <iostream>
#include <vector>


Node::Node() : Node(0, "", "")
{}


Node::Node(int r, const std::string& s, const std::string& t) : rezultat(r), poruka(s), vrijeme(t)
{}


Node KruzniBafer::errorNode = Node(-1, "greska", "greska");


KruzniBafer::KruzniBafer() : niz(new Node[SIZE]), front(0), rear(0)
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
	std::copy(other.niz, other.niz + SIZE, niz);
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
	delete [] niz;
	niz = nullptr;
	front = rear = 0;
}


const Node& KruzniBafer::operator[](int i) const
{
	if (i<0 || i>=SIZE)
		return errorNode;
	else
		return niz[i];
}


void KruzniBafer::enqueue(int x, const std::string& poruka, const std::string& vrijeme)
{
	rear = (rear+1)%SIZE;
	niz[rear] = Node(x, poruka, vrijeme);
	if (front == rear)
		front++;
}


Node KruzniBafer::dequeue()
{
	if (front == rear)
		return errorNode;
	else
	{
		front = (front+1)%SIZE;
		return niz[front];
	}
}


void KruzniBafer::print() const
{
	std::vector<Node> tmp;
	for(int i=front+1; i != rear+1; i = (i+1)%SIZE)
	{
		tmp.push_back(niz[i]);
	}
	std::sort(tmp.begin(), tmp.end(), [](const Node& n1, const Node& n2)
					  {
						  return n1.rezultat > n2.rezultat;
					  });
	for(auto x : tmp)
		std::cout << x.rezultat << "  " << x.poruka << "  " << x.vrijeme << std::endl;
	std::cout << std::endl;
}
