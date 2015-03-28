#ifndef REGISTERFILEWRITER
#define REGISTERFILEWRITER

#include "RegisterFile.h"
namespace SSARI {

class RegisterFileWriter {
public:
    RegisterFileWriter();
    bool writeFile(string path, RegisterFile &rf);
    ~RegisterFileWriter();

};

}


#endif // REGISTERFILEWRITER

