#include<iostream>
using namespace std;
class cPoint {
private:
	double x, y;
public:
	cPoint():x(0),y(0){}
	cPoint(double d) { x = d;y = d*2; }
	double X() { return x; }
	double Y() { return y; }
};
template<class T>
class cElement {
private:
	T element;
	cElement *next;
public:
	cElement() :element(0) {}
	cElement(double w) :element(w) {}
	cElement *Next() { return next; }
	void Next(cElement *p) { next = p; }
	T Element() { return element; }
};
template<class T>
class cLinkElement {
private:
	cElement<T> *head;
public:
	cLinkElement() :head(NULL) {}
    void Output() {
		cElement<T> *bufptr = head;
		cout << "Elements in the list are:" << endl;
		while (bufptr != NULL) {
			cout << bufptr->Element();
			if (sizeof(T) == sizeof(double)) cout << " ";
			bufptr = bufptr->Next();
		}
		printf("\n");
	}
	void AddElement(double n) {
		cElement<T> *newnode = new cElement<T>(n);
		//newnode->SetXY(n, 2 * n);
		newnode->Next(head);
		head = newnode;
	}
	void DeleteElement() {
		cElement<T> *bufptr = head->Next();
		//cout << "delete " << head->Element() << endl;
		delete head;
		head = bufptr;
	}
	bool Check() {
		if (head != NULL) return true;
		else return false;
	}
};
ostream& operator<<(ostream& os, cPoint& p) {
	os << "(" << p.X() << "," << p.Y() << ")";
	return os;
}
void main() {
	cLinkElement<cPoint> plist;
	cLinkElement<double> dlist;
	for (double i = 0;i < 10;i++) { plist.AddElement(i);dlist.AddElement(i); }
	dlist.Output();plist.Output();
	while (dlist.Check()) dlist.DeleteElement();
	while (plist.Check()) plist.DeleteElement();
}