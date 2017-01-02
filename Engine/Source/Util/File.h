#pragma once

#include<fstream>
#include<sstream>
#include <string>

class File {
    std::string filepath;
public:
    File (std::string path);
    File ();
    ~File ();

   void setFile (std::string path);

   void write (std::string data);
   void append (std::string data);

   std::string read (int position, char delimeter);

   std::string getPath ();

   int search (std::string data);

   void wipe ();
};