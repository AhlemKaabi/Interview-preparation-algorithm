# **Star Wars API**

## **Assignment**

Write a script that prints all characters of a Star Wars movie:

* The first positional argument passed is the Movie ID - example: 3 = “Return of the Jedi”
* Display one character name per line in the same order as the “characters” list in the /films/ endpoint
* You must use the [Star wars API](https://swapi-api.hbtn.io/)
* You must use the `request` module

## **Requirements**

* Your code should be `semistandard` compliant. [Rules of Standard](https://standardjs.com/rules.html) + [semicolons on top](https://github.com/standard/semistandard). Also as reference: [AirBnB style](https://github.com/airbnb/javascript).

* You are not allowed to use `var`.

**Install Node 10**

```
$ curl -sL https://deb.nodesource.com/setup_10.x | sudo -E bash -
$ sudo apt-get install -y nodejs
```


**Install semi-standard**

```
$ sudo npm install semistandard --global
```

**Install request module and use it**

[Documentation](https://github.com/request/request)

```
$ sudo npm install request --global
$ export NODE_PATH=/usr/lib/node_modules
```