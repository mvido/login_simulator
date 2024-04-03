#include <iostream>
#include <string>

#include <cpr/cpr.h>

#include <LoginSimulator.h>

int main(int argc, char* argv[]) {
    std::string username = (argc >= 2) ? argv[1] : "test";
    std::string password = (argc >= 3) ? argv[2] : "test";
    LoginSimulator::LoginSimulator login_simulator{username, password};

    cpr::Response response = login_simulator.login();

    if (bool(response.error)) {
        // error occurred
        return 1;
    }

    std::cout << response.text;

    return 0;
}