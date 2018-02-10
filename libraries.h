#ifndef LIB_H
#define LIB_H   1
#pragma once

#include <iostream>
#include <sstream>
#include <fstream>
#include <future>
#include <thread>
#include <cassert>
#include <cstdio>
#include <string>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <unistd.h>
#include <pthread.h>
#include <netdb.h>
#include <time.h>
#include <fcntl.h>
#include <errno.h>
#include <termios.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/select.h>
#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/time.h>

#include "network1.h"
 std::string exec(const char* cmd) {
    FILE* pipe = popen(cmd, "r");
    if (!pipe) return "ERROR";
    char buffer[128];
    std::string result = "";
    while(!feof(pipe)) {
        if(std::fgets(buffer, 128, pipe) != NULL)
            result += buffer;
    }
    pclose(pipe);
    return result;
}

std::string str_replacve(std::string dstPattern,std::string pattern,std::string str,int count=-1)
{
    std::string retStr="";
    std::string::size_type pos;
    int i=0,l_count=0,szStr=str.length();
    if(-1 == count) // replace all
        count = szStr;
    for(i=0; i<szStr; i++)
    {
        if(std::string::npos == (pos=str.find(pattern,i)))  break;
        if((int)pos < szStr)
        {
            retStr += str.substr(i,pos-i) + dstPattern;
            i=pos+pattern.length()-1;
            if(++l_count >= count)
            {
                i++;
                break;
            }
        }
    }
    retStr += str.substr(i);
    return retStr;
}
std::string read(std::string filename)
{
    const char*f = filename.c_str();
    std::string data;
    std::ifstream read;
    read.open(f);
    std::stringstream buffer;
    buffer << read.rdbuf();
    std::string contents(buffer.str());
    return contents;
}

#endif
