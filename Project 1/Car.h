 Honor Pledge:
 //
 // I pledge that I have neither given nor
 // received any help on this assignment.
 //
 // rkapadia
 #include <iostream>
 #include <string>
 class Car
 {
 //We need public variables and a constructor to create our car objects!
 //There also needs to be getters and setters as they are an important aspect of enxapsulation.
 	public:
 		Car();
 		Car(std::string n, int s, int c, int l);
 		~Car();
 		std::string getName();
 		int getSpeed();
 		int getControl();
 		int getLapNumber();
 		void setName(std:: string n);
 		void setSpeed(int s);
 		void setControl(int c);
 		void setLapNumber(int l);

 	//This is an example of encapsulation. The variables need to be private.
 	private:
 		std::string name_;
 		int speed_;
 		int control_;
 		int lapnumber_;
 };
