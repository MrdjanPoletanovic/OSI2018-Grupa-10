#pragma once
#include <string>
#include <vector>
#define MAX 11


struct Node
{
	int rezultat; // osvojeni broj bodova u igri
	std::string poruka; // parametar ukoliko budemo htjeli pamtiti jos neki podatak osim rezultata
	std::string vrijeme; // pamti vrijeme u kojem je zabiljezen dati rezultat
	Node();
	Node(int, const std::string&, const std::string&);
};


std::ostream& operator<<(std::ostream&, const Node&);


class KruzniBafer
{
	Node *niz;
	int front, rear;
public:
	static Node errorNode;
	KruzniBafer();
	KruzniBafer(const KruzniBafer&);
	KruzniBafer(std::ifstream&);
	KruzniBafer(KruzniBafer&&);
	KruzniBafer& operator=(const KruzniBafer&);
	KruzniBafer& operator=(KruzniBafer&&);
	void enqueue(int, const std::string&, const std::string&); //funkcija za upis u kruzni bafer sa prepisom
	Node dequeue(); // brisanje elementa iz bafera koristeci front parametar
	void writeToFile(std::fstream&) const;
	const Node& operator[](int) const;
	void print() const;
	~KruzniBafer();
private:
	std::vector<Node> returnSorted() const;
	void copy(const KruzniBafer&);
	void move(KruzniBafer&&);
};
