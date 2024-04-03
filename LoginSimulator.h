#pragma once

#include <string>

#include <cpr/cpr.h>

namespace LoginSimulator {

class LoginSimulator {
    const std::string &_username;
    const std::string &_password;
    const std::string _base_url;

public:
    /**
     * \brief Constructs LoginSimulator object using provided username and password credentials.
     * \param username Username used for login request.
     * \param password Password used for login request.
     */
    LoginSimulator(const std::string &username, const std::string &password);

    /**
     * \brief Prepares and sends HTTP login request.
     * \return Object representing HTTP response.
     */
    cpr::Response login(void);
};

} // LoginSimulator