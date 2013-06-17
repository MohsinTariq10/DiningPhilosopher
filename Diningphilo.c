/* 
*Dining Philosophers problem
* File: main.cpp
* Author: mohsin
*
* Created on March 11, 2013, 11:43 PM
*/
#include <cstdlib>
#include <iostream>
#include <pthread.h>
#include <cmath>
#include<errno.h>
#define MAX_SPOON 2
#define MAX_PHILO 2
using namespace std;
class Philospher{
public:
Philospher(int x){
id =x;
}
bool eat();
void think();
int getId(){
return id;
}
private:
int id;
};
void *dhaga(void *ptr){
Philospher *p = (Philospher*)ptr;
int x=0;
while(x=10){
p->eat();
x++;
}
}
class DiningTable{
private:
static int spoon[MAX_SPOON];
Philospher *p[MAX_PHILO];
public:
DiningTable();
static bool pick_spoon(int id,int pid);
static bool drop_spoon(int id,int pid);
};
bool Philospher::eat(){
//cout<<"pilo "<<getId()<<"begin"<<endl;
int id=getId();
if(DiningTable::pick_spoon(id-100,id)==true){

if(DiningTable::pick_spoon(MAX_SPOON-id+99,id)==true){
cout<<"philosopher no. "<<id<<" is eating"<<endl;
think();
DiningTable::drop_spoon(MAX_SPOON-id+99,id);
DiningTable::drop_spoon(id,id);
//cout<<"pilo "<<getId()<<"endt"<<endl;
return true;
}
cout<<"philosopher no. "<<getId()-100<<" cant eat with one spoon "<<getId()<<endl;
}
// cout<<"pilo "<<getId()<<"endf"<<endl;
return false;
}
void Philospher::think(){
cout<<"philospher no. "<<getId()-100<<" thinking"<<endl;
sleep(rand()%2);
}
DiningTable::DiningTable(){
pthread_t tid[MAX_PHILO];
for(int i=0;i<MAX_PHILO;i++){
p[i] = new Philospher(i+100);
pthread_create(&tid[i],NULL,dhaga,(void*)p[i]);
}
for(int i=0;i<MAX_PHILO;i++){
pthread_join(tid[i],NULL);
}
}
bool DiningTable::pick_spoon(int id,int pid){
//cout<<"pick pid "<<pid<<endl<<"id "<<id<<endl;
//cout<<"pick spoon status "<<spoon[0]<<" "<<spoon[1]<<endl;
if(id>=0 && id<MAX_SPOON){
if(spoon[id]==0){
spoon[id]=pid;
if(id==pid-100)
cout<<"philosopher no. "<<pid-100<<" picked his right spoon"<<endl ;
else 
cout<<"philosopher no. "<<pid-100<<" picked his left spoon" <<endl;
return true;
}
}
return false;
}
bool DiningTable::drop_spoon(int id,int pid){

if(id>=0 && id<MAX_SPOON ){
if(spoon[id]==pid){
spoon[id]=0;
if(id==pid-100)
cout<<"philosopher no. "<<pid-100<<" droped his right spoon"<<endl; 
else 
cout<<"philosopher no. "<<pid-100<<" droped his left spoon" <<endl;
cout<<" drop pid "<<pid<<" "<<"id "<<id<<endl;
cout<<"drop spoon status "<<spoon[0]<<" "<<spoon[1]<<endl;
return true;
}
}
return false;
}
int DiningTable::spoon[MAX_SPOON];
/*
* 
*/
int main(int argc, char** argv) {
DiningTable d1;
return 0;
}