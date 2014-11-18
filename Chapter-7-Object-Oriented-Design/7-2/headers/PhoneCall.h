#ifndef PHONECALL_H
#define PHONECALL_H

class PhoneCall{
	std::string phoneNumber;
	bool answered;

	public:
		PhoneCall(std::string n) : phoneNumber(n), answered(false) {}
		std::string getPhoneNumber() { return phoneNumber; }
		bool getAnswered() { return answered; }
};

#endif