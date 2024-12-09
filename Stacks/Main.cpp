#include <iostream>
#include <string>
#include "ArrayedStack.h"
#include "LinkedStack.h"
#include "LinkedQueue.h"
#include "CircularQueue.h"
using namespace std;

string reverse(string s)
{
	string toRet="";
	LinkedStack<char> characters;
	for (char c : s)
	{
		characters.push(c);
	}
	while (!characters.isEmpty())
	{
		toRet += characters.top();
		characters.pop();
	}
	return toRet;
}
string toBinary(int x)
{
	string toReturn="";
	LinkedStack<int> rems;
	while (x > 0)
	{
		int y = x % 2;
		rems.push(y);
		x /= 2;
	}
	while (!rems.isEmpty())
	{
		toReturn += to_string(rems.top());
		rems.pop();
	}
	return toReturn;
}
void processString(string s)
{
	string output = "";
	LinkedQueue<char> q;
	for (char c : s)
	{
		if (c == '*')
		{
			output += q.front();
			q.dequeue();
		}
		else
		{
			q.enqueue(c);
		}
	}
	cout << output;
}
void queueMain()
{
	string q1 = "EAS*Y*QUE***ST***IO*N***";
	processString(q1);


}

struct Block
{
	int qty;
	float price;
};

void sharesMain()
{
	LinkedQueue<Block> q;
	string input;
	do
	{
		if (q.size() != 0)
			cout << q.front().qty << "@" << q.front().price << ">";
		else
			cout << " >";
		cin >> input;
		if (input == "buy")
		{
			Block b;
			cin >> b.qty;
			cin >> b.price;
			q.enqueue(b);
		}
		else if (input == "sell")
		{
			int qty;
			float price;
			cin >> qty;
			cin >> price;
			double totalProfit=0;
			while (qty > 0)
			{
				if (q.front().qty > qty)
				{
					totalProfit += qty * (price - q.front().price);
					q.front().qty -= qty;
					qty = 0;
				}
				else
				{
					totalProfit += q.front().qty * (price - q.front().price);
					qty -= q.front().qty;
					q.dequeue();
				}
			}
			cout << "Total Profit: " << totalProfit << endl;
		}
	} while (input != "exit");
}


int main()
{
	CircularQueue<int> q(8);
	for (int i = 1; i <= 8; i++)
	{
		q.enqueue(i);
	}
	cout << q;
	q.dequeue();
	q.dequeue();
	q.dequeue();
	
	cout << q;
	q.enqueue(9);
	q.enqueue(10);
	cout << q;

	q.resize();
	cout << q;
	sharesMain();
}

/*
	frontVal = 3;
	count = 6
	capacity = 8;

	(3 + 6) % 8 = 1


*/