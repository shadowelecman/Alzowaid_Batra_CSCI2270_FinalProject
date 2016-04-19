#include "HashTable.h"

HashTable::HashTable()
{
    for(int x=0;x<tableSize;x++)
        hashTable[x]=NULL;
}

HashTable::~HashTable()
{
    //dtor
  //  delete hashTable;
}
void HashTable::deleteMovie(string name)
{
    int index=hashSum(name,name.size());
    int found=0;
    if(hashTable[index]!=NULL)
    {
        HashElem*temp=hashTable[index];
        while(temp!=NULL)
        {
            if(temp->title==name)
            {
                if(temp->previous!=NULL&&temp->next!=NULL)
                {
                    temp->previous->next=temp->next;
                    temp->next->previous=temp->previous;
                }
                else if(temp->previous==NULL&&temp->next!=NULL)
                {
                    temp->next->previous=NULL;
                    hashTable[index]=temp->next;
                }
                else if(temp->next==NULL&&temp->previous!=NULL)
                {
                    temp->previous->next=NULL;
                }
                else if(temp->next==NULL&&temp->previous==NULL)
                {
                    hashTable[index]=NULL;
                }
                found=1;
                delete temp;
               break;
            }
            temp=temp->next;
        }
        if(found==0)
        {
            cout << "not found" << endl;
        }
    }
}
void HashTable::findMovie(string name)
{
    int index=hashSum(name,name.size() ) ;
    int found =0;
    if(hashTable[index]==NULL)
    {
         cout << "not found" << endl;
    }
    else
    {
        HashElem*temp=hashTable[index];
        while(temp!=NULL)
        {
            if(temp->title==name)
            {
                cout << "Movie Info:" << endl;
                cout << "===========" << endl;
                cout << "Title:" << temp->title << endl;
                cout << "Year:" << temp->year << endl;
                cout << "Quantity:" << temp->qStock << endl;
                cout << "Country:" << temp->country<< endl;
                cout << "Language:" << temp->language << endl;
                cout << "Genres:" << temp->genres << endl;
                cout << "Lead Actor:" << temp->actor << endl;
                found=1;
                 break;
            }
            temp=temp->next;
        }
    }
            if(found==0)
                 cout << "not found" << endl;
}
int HashTable::hashSum(string x , int s)
{
     int sum=0;
    for(int xx=0;xx<s;xx++)
    {
    sum+=x[xx];//it sums up the weight of the chars in the string
    }
    sum=sum%tableSize;
    return sum;
}
void HashTable::insertMovie(string name, int year,int s,string g, string c, string l,string a)
{
    HashElem*node =new HashElem(name,year,s,g,c,l,a);
    int index=hashSum(name,name.size());
    if(hashTable[index]==NULL)
     {
        hashTable[index]=node;
        node->previous=NULL;
        node->next=NULL;
     }
     else
     {
         HashElem*temp=hashTable[index];
         while(temp->next!=NULL)
         {
             temp=temp->next;
         }
         temp->next=node;
         node->previous=temp;
     }
}
void HashTable::printTableContents()
{
    int found=0;
    for(int x=0;x<tableSize;x++)
    {
        if(hashTable[x]!=NULL)
        {
            HashElem*temp=hashTable[x];
            while(temp!=NULL)
            {
                cout<<temp->title<<"("<<temp->year<<")"<<":"<<temp->country<<":"<<temp->language<<":"<<temp->genres<<":"<<temp->actor<<":"<<temp->qStock<<endl;
                temp=temp->next;
            }
            found=1;
        }
    }
    if(found==0)
        cout << "empty" << endl;
}

void HashTable::findMovieYear(int year)
{
    int found=0;
    for(int x=0;x<tableSize;x++)
    {
        if(hashTable[x]!=NULL)
        {
            HashElem*temp=hashTable[x];
            while(temp!=NULL)
            {
                if(temp->year==year)
                {
                    cout << "Movie Info:" << endl;
                    cout << "===========" << endl;
                    cout << "Title:" << temp->title << endl;
                    cout << "Year:" << temp->year << endl;
                    cout << "Quantity:" << temp->qStock -1 << endl;
                    cout << "Country:" << temp->country<< endl;
                    cout << "Language:" << temp->language << endl;
                    cout << "Genres:" << temp->genres << endl;
                    cout << "Lead Actor:" << temp->actor << endl;
                }

                temp=temp->next;
            }
            found=1;
        }
    }
    if(found==0)
        cout << "Not found" << endl;
}
void HashTable::findMovieCountry(string country)
{
    int found=0;
    for(int x=0;x<tableSize;x++)
    {
        if(hashTable[x]!=NULL)
        {
            HashElem*temp=hashTable[x];
            while(temp!=NULL)
            {
                if(temp->country==country)
                {
                    cout << "Movie Info:" << endl;
                    cout << "===========" << endl;
                    cout << "Title:" << temp->title << endl;
                    cout << "Year:" << temp->year << endl;
                    cout << "Quantity:" << temp->qStock -1 << endl;
                    cout << "Country:" << temp->country<< endl;
                    cout << "Language:" << temp->language << endl;
                    cout << "Genres:" << temp->genres << endl;
                    cout << "Lead Actor:" << temp->actor << endl;
                }

                temp=temp->next;
            }
            found=1;
        }
    }
    if(found==0)
        cout << "Not found" << endl;
}
void HashTable::findMovieGenres(string genres)
{
    int found=0;
    for(int x=0;x<tableSize;x++)
    {
        if(hashTable[x]!=NULL)
        {
            HashElem*temp=hashTable[x];
            while(temp!=NULL)
            {
                if(temp->genres==genres)
                {
                    cout << "Movie Info:" << endl;
                    cout << "===========" << endl;
                    cout << "Title:" << temp->title << endl;
                    cout << "Year:" << temp->year << endl;
                    cout << "Quantity:" << temp->qStock -1 << endl;
                    cout << "Country:" << temp->country<< endl;
                    cout << "Language:" << temp->language << endl;
                    cout << "Genres:" << temp->genres << endl;
                    cout << "Lead Actor:" << temp->actor << endl;
                }

                temp=temp->next;
            }
            found=1;
        }
    }
    if(found==0)
        cout << "Not found" << endl;
}
void HashTable::findMovieActor(string actor)
{
    int found=0;
    for(int x=0;x<tableSize;x++)
    {
        if(hashTable[x]!=NULL)
        {
            HashElem*temp=hashTable[x];
            while(temp!=NULL)
            {
                if(temp->actor==actor)
                {
                    cout << "Movie Info:" << endl;
                    cout << "===========" << endl;
                    cout << "Title:" << temp->title << endl;
                    cout << "Year:" << temp->year << endl;
                    cout << "Quantity:" << temp->qStock -1 << endl;
                    cout << "Country:" << temp->country<< endl;
                    cout << "Language:" << temp->language << endl;
                    cout << "Genres:" << temp->genres << endl;
                    cout << "Lead Actor:" << temp->actor << endl;
                }
                temp=temp->next;
            }
            found=1;
        }
    }
    if(found==0)
        cout << "Not found" << endl;
}
void HashTable::findMovieRange(int min,int max)
{
    int found=0;
    for(int x=0;x<tableSize;x++)
    {
        if(hashTable[x]!=NULL)
        {
            HashElem*temp=hashTable[x];
            while(temp!=NULL)
            {
                if(temp->year>min && temp->year<max)
                {
                    cout << "Movie Info:" << endl;
                    cout << "===========" << endl;
                    cout << "Title:" << temp->title << endl;
                    cout << "Year:" << temp->year << endl;
                    cout << "Quantity:" << temp->qStock -1 << endl;
                    cout << "Country:" << temp->country<< endl;
                    cout << "Language:" << temp->language << endl;
                    cout << "Genres:" << temp->genres << endl;
                    cout << "Lead Actor:" << temp->actor << endl;
                    found=1;
                }
                temp=temp->next;

            }

        }
    }
    if(found==0)
        cout << "Not found" << endl;
}
void HashTable::findMovieLang(string language)
{
    int found=0;
    for(int x=0;x<tableSize;x++)
    {
        if(hashTable[x]!=NULL)
        {
            HashElem*temp=hashTable[x];
            while(temp!=NULL)
            {
                if(temp->language==language)
                {
                    cout << "Movie Info:" << endl;
                    cout << "===========" << endl;
                    cout << "Title:" << temp->title << endl;
                    cout << "Year:" << temp->year << endl;
                    cout << "Quantity:" << temp->qStock -1 << endl;
                    cout << "Country:" << temp->country<< endl;
                    cout << "Language:" << temp->language << endl;
                    cout << "Genres:" << temp->genres << endl;
                    cout << "Lead Actor:" << temp->actor << endl;
                }
                temp=temp->next;
            }
            found=1;
        }
    }
    if(found==0)
        cout << "Not found" << endl;
}
void HashTable::rentMovie(string name)
{
    int found=0;
    for(int x=0;x<tableSize;x++)
    {
        if(hashTable[x]!=NULL)
        {
            HashElem*temp=hashTable[x];
            while(temp!=NULL)
            {
                if(temp->title==name)
                {
                    if(temp->qStock>0)
                    {
                        cout << "Movie has been rented." << endl;
                        cout << "Movie Info:" << endl;
                        cout << "===========" << endl;
                        cout << "Title:" << temp->title << endl;
                        cout << "Year:" << temp->year << endl;
                        cout << "Quantity:" << temp->qStock -1 << endl;
                        cout << "Country:" << temp->country<< endl;
                        cout << "Language:" << temp->language << endl;
                        cout << "Genres:" << temp->genres << endl;
                        cout << "Lead Actor:" << temp->actor << endl;
                        temp->qStock=temp->qStock-1;
                        found=1;
                        break;
                    }
                    else //If movie is out of stock
                    {
                        cout << "Movie out of stock." << endl;
                        found=1;
                        break;
                    }

                }
                temp=temp->next;
              }
           }
    }
    if(found==0)
        cout << "Movie not found." << endl;
}



