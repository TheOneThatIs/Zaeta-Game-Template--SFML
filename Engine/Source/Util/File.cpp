#include "Util\File.h"
#include<iostream>

File::File (std::string path) {
    filepath = path;
}

File::File () {}
File::~File () {}


void File::setFile (std::string path) {
    filepath = path;
}

void File::write (std::string data) {
    std::ofstream file;
    file.open (filepath.c_str());
    file << data;
}

void File::append (std::string data) {
    std::ofstream file;
    file.open (filepath.c_str (), std::ofstream::app);
    file << data;
    file << "\n";
}

std::string File::read (int position, char delimeter) {
    std::ifstream file;
    file.open (filepath.c_str (), std::ifstream::binary);
    file.seekg (position);

    std::stringstream stream;

    char c;
    file.get (c);

    if (c == delimeter) {
        file.close ();
        return stream.str ();
    }

    do {
        stream << c;
        file.get (c);
    } while (c != delimeter);

    file.close ();

    return stream.str ();
}

std::string File::getPath () {
    return filepath;
}

int File::search (std::string data) {
    std::ifstream file;
    file.open (filepath.c_str (), std::ifstream::binary);

    std::string line;
    int position = 0;

    while (getline (file, line)) {
        std::stringstream sstream (line);
        int pos2 = sstream.str ().find (data);

        if (pos2 != std::string::npos) {
            return position + pos2;     //Why?
        }

        position += sstream.str ().length () + 1;     //Why +1?
    }
    file.close ();
    return std::string::npos;
}

void File::wipe () {
    std::ifstream file;

    file.open (filepath, std::ofstream::out | std::ifstream::trunc);
    std::cout << "Wiped.\n";
    file.close ();
}