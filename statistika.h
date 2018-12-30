#pragma once
#include <string>
#define SIZE 11


struct Node
{
	int rezultat; // osvojeni broj bodova u igri
	std::string poruka; // parametar ukoliko budemo htjeli pamtiti jos neki podatak osim rezultata
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
	void enqueue(int, const std::string& poruka=""); //funkcija za upis u kruzni bafer sa prepisom
	Node dequeue(); // brisanje elementa iz bafera koristeci front parametar
	const Node& operator[](int) const;
	~KruzniBafer();
private:
	void copy(const KruzniBafer&);
	void move(KruzniBafer&&);
};
