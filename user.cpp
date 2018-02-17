#include "user.h"
#include <unistd.h>
void keep_heartbeat(std::string username,std::string password) {
    std::string feelback="OK";
    int error_times=0;
    while(error_times<5)
    {
        network *n=new network();
        //QCoreApplication::processEvents();
        feelback=curl("mode=heartbeat&username="+username+"&password="+password);
        //n->show();
        //feelback=n->reply;
        delete n;
        if (feelback=="OK")
        {
            error_times=0;
        }
        else
        {
            error_times++;
        }
        sleep(30);
    }
    std::terminate();
    return;
}
user::user()
{

}
bool user::reg(std::string name,std::string pwd)
{
    std::string feelback=curl("mode=reg&username="+name+"&password="+pwd);
    if (feelback=="OK")
    {
        std::string f;
        username=name;
        password=pwd;
        std::thread heartbeat(keep_heartbeat,this->username,this->password);
        heartbeat.detach();
        return true;
    }
    else
    {
        return false;
    }
}
bool user::login(std::string name,std::string pwd)
{
    std::string feelback=curl("mode=login&username="+name+"&password="+pwd);
    if (feelback=="oops")
    {
        emsg="NoUser";
        return false;
    }
    else
    {
        if (feelback=="OK")
        {
            username=name;
            password=pwd;
            //tools::write()
            std::thread heartbeat(keep_heartbeat,this->username,this->password);
            heartbeat.detach();
            return true;
        }
        else
        {
            //std::cout<< "\033[31mWrong Password\033[0m";
            return false;
        }
    }
}
