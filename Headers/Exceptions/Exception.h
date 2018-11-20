//
// Created by Narek Hovhannisyan and/or Milena Mamyan on 10/14/18.
//

#ifndef VIRTUAL_MACHINE_EXCEPTION_H
#define VIRTUAL_MACHINE_EXCEPTION_H

#include <string>

class Exception{
protected: 
	std::string message;
public:
	Exception(std::string _message);
	virtual std::string getMessage() = 0;
};

#endif 