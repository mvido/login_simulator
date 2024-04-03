#include <string>

#include <cpr/cpr.h>

#include <LoginSimulator.h>

namespace LoginSimulator {

LoginSimulator::LoginSimulator(const std::string &username, const std::string &password) :
    _username{username},
    _password{password},
    _base_url{"http://testphp.vulnweb.com"}
{
}

cpr::Response LoginSimulator::login(void)
{
    std::string login_cookie = "login=" + _username + "\%2F" + _password;
    std::string login_url = _base_url + "/userinfo.php";
    std::string referer_url = _base_url + "/login.php";

    return cpr::Post(
        cpr::Url{login_url},
        cpr::Header{
            {"Origin", _base_url},
            {"Referer", referer_url},
            {"Cookie", login_cookie}
        },
        cpr::Payload{{"uname", _username}, {"pass", _password}}
    );
}

} // LoginSimulator