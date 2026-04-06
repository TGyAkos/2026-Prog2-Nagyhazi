//
// Created by user on 06/04/2026.
//

#ifndef TITKOSITO_MESSAGEFILE_H
#define TITKOSITO_MESSAGEFILE_H
#include <string>

class MessageFile {
    static std::string output_file_name;
public:
    MessageFile() = default;
    static std::string loadFile(const std::string& file_name);
    static void saveToFile(const std::string& message);
    ~MessageFile() = default;
};



#endif //TITKOSITO_MESSAGEFILE_H
