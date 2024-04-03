# Login simulator

Login simulator is a console app that does a request to simulate login to
“http://testphp.vulnweb.com/login.php” and displays the returned HTML page.

## Dependencies

- compiler with C++17 support

- cmake (minimum version 3.20)

- **cpr**: https://github.com/libcpr/cpr

  Automatically handled by cmake module FetchContent.

## Build

```
$ mkdir -p build && cd build
$ cmake ..
$ cmake --build .
```

Executable binary `login_simulator` is produced in `build/bin` folder.

## Usage


```
$ build/bin/login_simulator [<username> [<password>]]
```

- `<username>` if 1 argument is provided, it is used as a username, and default password is used
- `<password>` if 2 arguments are provided, first argument is username and second argument is password

If more than 2 arguments are provided, only 2 arguments are used and the rest is ignored.

If no arguments are provided default username and default password are used.

Default username: test

Default password: test

## Design Description

Functionality for simulating a login with username and password credentials is implemented
in class `LoginSimulator`.
Username and password are provided as arguments when an object is constructed.
The class is wrapping the call of `cpr::Post()` function from **cpr** library in `LoginSimulator::login()`
method which performs HTTP POST request to testphp.vulnweb.com server in following format:

```
POST /userinfo.php HTTP/1.1
Host: testphp.vulnweb.com
User-Agent: curl/8.4.0
Accept: */*
Accept-Encoding: deflate, gzip
Cookie: login=test%2Ftest
Origin: http://testphp.vulnweb.com
Referer: http://testphp.vulnweb.com/login.php
Content-Length: 20
Content-Type: application/x-www-form-urlencoded

uname=test&pass=test
```

HTTP response to the given request is returned by `LoginSimulator::login()` method.

Message body of the HTTP response is then printed to the standard output by the main program.

If an error occurs, no response is printed and the program returns error code 1.