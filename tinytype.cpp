#include <iostream>

template <typename U, typename T = typename U::value_type>
class TinyType
{
public:
	typedef T value_type;

	explicit TinyType (const value_type& t) : m_t(t) {}

	explicit operator const value_type&() const { return m_t; }
	explicit operator value_type&() { return m_t; }

private:
	value_type m_t;
};
#define CreateTinyType(TypeName, InnerType) struct TypeName ## Type {}; typedef TinyType<TypeName ## Type, InnerType> TypeName;

CreateTinyType(Person, std::string);
CreateTinyType(Other, std::string);
CreateTinyType(Another, std::string);

int main()
{
	Person person { "danilo" };
	Person person2 ( "danilao" );
	Other other ( "" );
	//Another another(other); // não compila
	
	person = person2;
	// person = other; // não compila
	
	std::cout << (std::string)person << std::endl;
	std::cout << (std::string)other << std::endl;

	return 0;
}

