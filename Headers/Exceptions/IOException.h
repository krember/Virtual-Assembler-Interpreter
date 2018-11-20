//
// Created by Narek Hovhannisyan and/or Milena Mamyan on 10/14/18.
//

#ifndef VIRTUAL_MACHINE_IOEXCEPTION_H
#define VIRTUAL_MACHINE_IOEXCEPTION_H

#include "Exceptions/Exception.h"

class IOException :
	public Exception
{
public:
	IOException(std::string message);
	virtual std::string getMessage() override;
};

#endif