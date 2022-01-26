#include <iostream>

int	main(void)
{
	std::string str = "HI THIS IS BRAIN";
	std::string	*ptr;// 포인터는 주소값을 할당
	std::string	&ref = str; // 레퍼런스는 대상을 직접 할당(레퍼런스는 선언과 동시에 초기화를 하지 않으면 컴파일 오류가 발생, 레퍼런스는 NULL이 허용되지 않습니다.)
	
	std::cout << str << " " << &str << std::endl;
	std::cout << &ptr << std::endl;
	ptr = &str;
	std::cout << *ptr << " " << ptr << " " << &ptr << std::endl;
	std::cout << ref << " " << &ref << std::endl;
	return (0);
}