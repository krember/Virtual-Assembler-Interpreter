//
// Created by Narek Hovhannisyan and/or Milena Mamyan.
//

#ifndef VIRTUAL_MACHINE_UTILS_H
#define VIRTUAL_MACHINE_UTILS_H

#include <string>
#include "Definitions.h"

class Utils{
public:
    static VDBCommand getCommandFrom(std::string command);
};

#endif //VIRTUAL_MACHINE_UTILS_H
