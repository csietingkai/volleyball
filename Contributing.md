# Contributions

If you want to join this project, E-mail [me](mailto:tingkai@csie.io) first

## Coding Style

+ must add comment above classes and functions
+ bracket at next line first
+ variables use underline to sperate
+ class name use capital letter to sperate

exmaple.h: 
``` cpp
/**
 * explain the usage of 'ClassName'
 * 
 * @Extend AnotherClassNameA
 * @Extend AnotherClassNameB
 * @Implement InterfaceC
 * 
 * @CreateBy user_one
 * @Date 2019.02.23
 */
class ClassName : AnotherClassNameA, AnotherClassNameB, InterfaceC
{
	public:
		ClassName(int number);
	protected:
		/**
		 * explain the usage of 'sth_func'
		 * 
		 * @CreateBy user_one
		 * @Date 2019.02.23
		 * @UpdateBy user_two on 2019.02.24: explain what update you done
		 */ 
		const char sth_func() const;
		
	private:
		int number;
		std::string str;
		std::string long_var_something;
}
```

exmaple.cpp: 
``` cpp
ClassName::ClassName(int number)
	: AnotherClassNameA(variable_for_A)
	, AnotherClassNameB(variable_for_B)
	, InterfaceC(variable_for_C)
{
	this->number = 0;
	this->str = "";
	this->long_var_something = "";
}

const char ClassName::sth_func() const
{
	// explain the logic of this function
	int a = 0;
	int b = 0;
	cin >> a;
	cin >> b;
	this->number = a + b;
}
```
