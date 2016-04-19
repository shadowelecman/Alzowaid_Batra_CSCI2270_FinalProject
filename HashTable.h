#ifndef HASHTABLE_H
#define HASHTABLE_H
#include <string>
#include <vector>
#include <iostream>
using namespace std;

struct HashElem{
	string title;
	int year;
	int qStock;
	string actor;
	string country;
	string language;
	string genres;

	HashElem *next;
    HashElem *previous;

	HashElem(){};
	HashElem(string in_title, int in_year,int s,string g,string c, string l,string a)
	{
		title = in_title;
		year = in_year;
		qStock=s;
		genres=g;
		country=c;
		language=l;
		actor=a;
		next = NULL;
		previous = NULL;
	}

};



class HashTable
{
    public:
        HashTable();
        virtual ~HashTable();
        void printTableContents();
		void insertMovie(string name, int year,int stock,string g,string c,string l,string a);
		void deleteMovie(string name);
		void findMovie(string name);

		void findMovieYear(int year);
		void findMovieGenres(string genres);
		void findMovieActor(string actor);
		void findMovieRange(int min,int max);
		void findMovieLang(string language);
		void findMovieCountry(string country);
		void rentMovie(string name);


    protected:
    private:
        int hashSum(string x, int s);
		int tableSize = 10;
		HashElem* hashTable[10];
};

#endif // HASHTABLE_H
