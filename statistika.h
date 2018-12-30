#pragma once
#include <string>
#define SIZE 11


struct Node
{
	int rezultat;
	std::string poruka;
	Node();
	Node(int, const std::string&);
};


class KruzniBafer
{
	Node *niz;
	int front, rear;
public:
	static Node errorNode;
	KruzniBafer();
	KruzniBafer(const KruzniBafer&);
	KruzniBafer(KruzniBafer&&);
	KruzniBafer& operator=(const KruzniBafer&);
	KruzniBafer& operator=(KruzniBafer&&);
	void enqueue(int);
	Node dequeue();
	const Node& operator[](int) const;
	~KruzniBafer();
private:
	void copy(const KruzniBafer&);
	void move(KruzniBafer&&);
};
