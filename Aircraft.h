#ifndef AIRCRAFT_H
#define AIRCRAFT_H
#include <iostream>
#include <string>

using namespace std;

class Aircraft{
	private:
		string type; //a design of the aircraft type eg. Boeing 747, Airbus A380
		int passengers; //the number of passengers that aircraft can carry
		int crew; //the number of crew members needed
		double maintCost; //the cost of maintenance per hour of flying 1007350
		double fuelEffic; //the tonnes of fuel used per hour of flight
				
	public:
		Aircraft(){		//default constructor
			/*type = "";
			passengers = 0;
			crew = 0;
			maintCost = 0.0;
			fuelEffic = 0.0;*/
		}

		Aircraft(string type, int passengers, int crew, double maintCost, double fuelEffic){ //Parametrized Constructor
			this->type = type;
			this->passengers = passengers;
			this->crew = crew;
			this->maintCost = maintCost;
			this->fuelEffic = fuelEffic;
		}
		void toString(){	//A method to show the Aircraft type and passenger capacity
			cout<<type<<", "<<passengers<<endl;
		}
		double calcRunningCosts(){ //A method to calculate the total cost of one hour of flight
			return (fuelEffic*767) + (crew*100) + maintCost + 8000; 
			/* 	The cost of jet fuel per tonne is $767 ,
				the crew salary per hour is $100 and
				the overhead figure is $8000.	*/
				
		}

};

#endif

