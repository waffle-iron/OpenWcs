//
// Created by konstantin on 10.08.16.Konsta
//

#ifndef OPENWCS_MAINAPP_H
#define OPENWCS_MAINAPP_H

#include "Poco/Util/Application.h"
#include "Poco/Util/HelpFormatter.h"
#include "ThreadVector.h"

class MainApp: public Poco::Util::Application
{
public:
    MainApp();

protected:
    void initialize(Poco::Util::Application &);
    void uninitialize();
    void reinitialize(Poco::Util::Application &);
    void defineOptions(Poco::Util::OptionSet &);
    void handleHelp(const std::string &, const std::string &);
    void handleVersion(const std::string &, const std::string &);
    void handleSnapPicture(const std::string &, const std::string &);
    void handleTimelapse(std::string);
    void handleConfig(const std::string &, const std::string &);
    void handleWebInterface(const std::string &, const std::string &);
    void displayHelp();
    void displayVersion();
    void processInternalCLIOptions(std::string);
    int main(const ArgVec &);

private:
    bool _endExecution;
    bool _enableWebInterface;
    ThreadVector threadVector;
};


#endif //OPENWCS_MAINAPP_H
