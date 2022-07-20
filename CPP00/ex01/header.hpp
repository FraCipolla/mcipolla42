#ifndef HEADER_HPP
#define HEADER_HPP

class Contacts{
	public:
	void		setFirstName(std::string str);
	void		setLastName(std::string str);
	void		setNickName(std::string str);
	void		setLogin(std::string str);
	void		setAddress(std::string str);
	void		setEmail(std::string str);
	void		setPhone(std::string str);
	void		setBirthday(std::string str);
	void		setMeal(std::string str);
	void		setUnderwear(std::string str);
	void		setSecret(std::string str);

	std::string	getFirstName(void);
	std::string	getLastName(void);
	std::string	getNickName(void);
	std::string	getLogin(void);
	std::string	getAddress(void);
	std::string	getEmail(void);
	std::string	getPhone(void);
	std::string	getBirthday(void);
	std::string	getMeal(void);
	std::string	getUnderwear(void);
	std::string	getSecret(void);
private:
	std::string	_firstname;
	std::string	_lastname;
	std::string	_nickname;
	std::string	_login;
	std::string	_address;
	std::string	_email;
	std::string	_phone;
	std::string	_birthday;
	std::string	_meal;
	std::string	_underwear;
	std::string	_secret;
};

class PhoneBook{
	public:
		Contacts	contacts[8];
};

#endif