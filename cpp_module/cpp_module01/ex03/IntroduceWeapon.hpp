#ifndef INTRODUCEWEAPON_HPP
# define INTRODUCEWEAPON_HPP

# include <iostream>

class IntroWeapon
{
	private:
		std::string	type;
		int num;

	public:
		const std::string& getType() const
		{
			return type;
		}

		void setType(const std::string& new_type)
		{
			this->type = new_type;
		}

		const int& getNum() const;
};

#endif


int main()
{
	IntroWeapon a;

	std::string str = a.getType();
	str.append("sd");

	a.getType().append("world");
	a.getType().size();

	const IntroWeapon& b = a;

	b.setType("asdad"); //  매개변수의 타입이 콘스트 레퍼런스 이기때문에, 임시객처를 생성한다.

	lvalue = rvalue




	const std::string& view = a.getType();

	printf("%s", view);
}



//

int size() const
{
	return sizeof(this->str);
}

int append(char *str)
{
	strcat(this->str, str);
}
