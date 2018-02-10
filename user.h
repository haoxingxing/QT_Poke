#ifndef USER_H
#define USER_H  1
#include <string>
#include <thread>
#include "network.h"
class user
{
public:
    user();
    std::string username="";
    std::string password;
    bool login(std::string name,std::string pwd);
    bool reg(std::string name,std::string pwd);
    std::string emsg;

};
#endif // USER_H
