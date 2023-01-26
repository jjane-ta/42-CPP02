/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjane-ta <jjane-ta@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 18:12:59 by jjane-ta          #+#    #+#             */
/*   Updated: 2023/01/26 18:55:55 by jjane-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include "Fixed.hpp"

void	print_raw(Fixed a);
void	main_print_banner(std::string title);
void	print_aritmetic_test(Fixed a, Fixed b , Fixed c , std::string test);
void	print_comparison_test(Fixed &a, Fixed &b , bool res  , std::string op);
void	print_comparison_raw_test(Fixed &a, Fixed &b , bool res  , std::string op);

int main( void )
{
	main_print_banner("TEST subject");
	{
		Fixed a;
		Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
		std::cout << '\t' << a << std::endl;
		std::cout << '\t' << ++a << std::endl;
		std::cout << '\t' << a << std::endl;
		std::cout << '\t' << a++ << std::endl;
		std::cout << '\t' << a << std::endl;
		std::cout << '\t' << b << std::endl;
		std::cout << '\t' << Fixed::max( a, b ) << std::endl;
		std::cout << std::endl;
	}
	Fixed::format = 1;	

	main_print_banner("Test increment / decrement");
	{
		Fixed a;

		a.setRawBits(INT_MAX);
		std::cout << "\tOperator ++pre  => before = " << a << " | now = " << ++a << " | after = " << a << " | Error = " << std::boolalpha << !a.good() << std::endl;
		a.clear();
		a.setRawBits(INT_MAX/2);
		std::cout << "\tOperator ++pre  => before = " << a << " | now = " << ++a << " | after = " << a << " | Error = " << std::boolalpha << !a.good() << std::endl;
		a.clear();	
		a.setRawBits(256);
		std::cout << "\tOperator ++pre  => before = " << a << " | now = " << ++a << " | after = " << a << " | Error = " << std::boolalpha << !a.good() << std::endl;
		a.clear();
		a.setRawBits(0);
		std::cout << "\tOperator ++pre  => before = " << a << " | now = " << ++a << " | after = " << a << " | Error = " << std::boolalpha << !a.good() << std::endl;
		a.clear();
		a.setRawBits(-256);
		std::cout << "\tOperator ++pre  => before = " << a << " | now = " << ++a << " | after = " << a << " | Error = " << std::boolalpha << !a.good() << std::endl;
		a.clear();	
		a.setRawBits(INT_MIN/2);
		std::cout << "\tOperator ++pre  => before = " << a << " | now = " << ++a << " | after = " << a << " | Error = " << std::boolalpha << !a.good() << std::endl;
		a.clear();	
		a.setRawBits(INT_MIN);
		std::cout << "\tOperator ++pre  => before = " << a << " | now = " << ++a << " | after = " << a << " | Error = " << std::boolalpha << !a.good() << std::endl;
		std::cout << std::endl;
		a.clear();	
		a.setRawBits(INT_MAX);
		std::cout << "\tOperator post++ => before = " << a << " | now = " << a++ << " | after = " << a << " | Error = " << std::boolalpha << !a.good() << std::endl;
		a.clear();		
		a.setRawBits(INT_MAX/2);
		std::cout << "\tOperator post++ => before = " << a << " | now = " << a++ << " | after = " << a << " | Error = " << std::boolalpha << !a.good() << std::endl;
		a.clear();	
		a.setRawBits(256);
		std::cout << "\tOperator post++ => before = " << a << " | now = " << a++ << " | after = " << a << " | Error = " << std::boolalpha << !a.good() << std::endl;
		a.clear();	
		a.setRawBits(0);
		std::cout << "\tOperator post++ => before = " << a << " | now = " << a++ << " | after = " << a << " | Error = " << std::boolalpha << !a.good() << std::endl;
		a.clear();	
		a.setRawBits(-256);
		std::cout << "\tOperator post++ => before = " << a << " | now = " << a++ << " | after = " << a << " | Error = " << std::boolalpha << !a.good() << std::endl;
		a.clear();	
		a.setRawBits(INT_MIN/2);
		std::cout << "\tOperator post++ => before = " << a << " | now = " << a++ << " | after = " << a << " | Error = " << std::boolalpha << !a.good() << std::endl;
		a.clear();	
		a.setRawBits(INT_MIN);
		std::cout << "\tOperator post++ => before = " << a << " | now = " << a++ << " | after = " << a << " | Error = " << std::boolalpha << !a.good() << std::endl;
		std::cout << std::endl;
		a.clear();	
		a.setRawBits(INT_MAX);
		std::cout << "\tOperator --pre  => before = " << a << " | now = " << --a << " | after = " << a << " | Error = " << std::boolalpha << !a.good() << std::endl;
		a.clear();	
		a.setRawBits(INT_MAX/2);
		std::cout << "\tOperator --pre  => before = " << a << " | now = " << --a << " | after = " << a << " | Error = " << std::boolalpha << !a.good() << std::endl;
		a.clear();	
		a.setRawBits(256);
		std::cout << "\tOperator --pre  => before = " << a << " | now = " << --a << " | after = " << a << " | Error = " << std::boolalpha << !a.good() << std::endl;
		a.clear();	
		a.setRawBits(0);
		std::cout << "\tOperator --pre  => before = " << a << " | now = " << --a << " | after = " << a << " | Error = " << std::boolalpha << !a.good() << std::endl;
		a.clear();	
		a.setRawBits(-256);
		std::cout << "\tOperator --pre  => before = " << a << " | now = " << --a << " | after = " << a << " | Error = " << std::boolalpha << !a.good() << std::endl;
		a.clear();	
		a.setRawBits(INT_MIN/2);
		std::cout << "\tOperator --pre  => before = " << a << " | now = " << --a << " | after = " << a << " | Error = " << std::boolalpha << !a.good() << std::endl;
		a.clear();	
		a.setRawBits(INT_MIN);
		std::cout << "\tOperator --pre  => before = " << a << " | now = " << --a << " | after = " << a << " | Error = " << std::boolalpha << !a.good() << std::endl;
		std::cout << std::endl;
		a.clear();	
		a.setRawBits(INT_MAX);
		std::cout << "\tOperator post-- => before = " << a << " | now = " << a-- << " | after = " << a << " | Error = " << std::boolalpha << !a.good() << std::endl;
		a.clear();	
		a.setRawBits(INT_MAX/2);
		std::cout << "\tOperator post-- => before = " << a << " | now = " << a-- << " | after = " << a << " | Error = " << std::boolalpha << !a.good() << std::endl;
		a.clear();	
		a.setRawBits(256);
		std::cout << "\tOperator post-- => before = " << a << " | now = " << a-- << " | after = " << a << " | Error = " << std::boolalpha << !a.good() << std::endl;
		a.clear();	
		a.setRawBits(0);
		std::cout << "\tOperator post-- => before = " << a << " | now = " << a-- << " | after = " << a << " | Error = " << std::boolalpha << !a.good() << std::endl;
		a.clear();	
		a.setRawBits(-256);
		std::cout << "\tOperator post-- => before = " << a << " | now = " << a-- << " | after = " << a << " | Error = " << std::boolalpha << !a.good() << std::endl;
		a.clear();	
		a.setRawBits(INT_MIN/2);
		std::cout << "\tOperator post-- => before = " << a << " | now = " << a-- << " | after = " << a << " | Error = " << std::boolalpha << !a.good() << std::endl;
		a.clear();	
		a.setRawBits(INT_MIN);
		std::cout << "\tOperator post-- => before = " << a << " | now = " << a-- << " | after = " << a << " | Error = " << std::boolalpha << !a.good() << std::endl;
		std::cout << std::endl;
	}
	main_print_banner("Test increment / decrement raw bits");
	{
		Fixed a;

		a.setRawBits(INT_MAX);
		std::cout << "\tOperator ++pre  => before = "; print_raw(a); std::cout << " | now = "; print_raw(++a); std::cout << " | after = "; print_raw(a); std::cout <<\
			 " | Error = " << std::boolalpha << !a.good() << std::endl;
		a.clear();	
		a.setRawBits(INT_MAX/2);
		std::cout << "\tOperator ++pre  => before = "; print_raw(a); std::cout << " | now = "; print_raw(++a); std::cout << " | after = "; print_raw(a); std::cout <<\
			 " | Error = " << std::boolalpha << !a.good() << std::endl;
		a.clear();	
		a.setRawBits(256);
		std::cout << "\tOperator ++pre  => before = "; print_raw(a); std::cout << " | now = "; print_raw(++a); std::cout << " | after = "; print_raw(a); std::cout <<\
			 " | Error = " << std::boolalpha << !a.good() << std::endl;		
		a.clear();	
		a.setRawBits(0);
		std::cout << "\tOperator ++pre  => before = "; print_raw(a); std::cout << " | now = "; print_raw(++a); std::cout << " | after = "; print_raw(a); std::cout <<\
			 " | Error = " << std::boolalpha << !a.good() << std::endl;
		a.clear();	
		a.setRawBits(-256);
		std::cout << "\tOperator ++pre  => before = "; print_raw(a); std::cout << " | now = "; print_raw(++a); std::cout << " | after = "; print_raw(a); std::cout <<\
			 " | Error = " << std::boolalpha << !a.good() << std::endl;
		a.clear();	
		a.setRawBits(INT_MIN/2);
		std::cout << "\tOperator ++pre  => before = "; print_raw(a); std::cout << " | now = "; print_raw(++a); std::cout << " | after = "; print_raw(a); std::cout <<\
			 " | Error = " << std::boolalpha << !a.good() << std::endl;
		a.clear();	
		a.setRawBits(INT_MIN);
		std::cout << "\tOperator ++pre  => before = "; print_raw(a); std::cout << " | now = "; print_raw(++a); std::cout << " | after = "; print_raw(a); std::cout <<\
			 " | Error = " << std::boolalpha << !a.good() << std::endl;
		a.clear();	
		std::cout << std::endl;
		a.setRawBits(INT_MAX);
		std::cout << "\tOperator post++  => before = "; print_raw(a); std::cout << " | now = "; print_raw(a++); std::cout << " | after = "; print_raw(a); std::cout <<\
			 " | Error = " << std::boolalpha << !a.good() << std::endl;
		a.clear();	
		a.setRawBits(INT_MAX/2);
		std::cout << "\tOperator post++  => before = "; print_raw(a); std::cout << " | now = "; print_raw(a++); std::cout << " | after = "; print_raw(a); std::cout <<\
			 " | Error = " << std::boolalpha << !a.good() << std::endl;
		a.clear();	
		a.setRawBits(0);
		std::cout << "\tOperator post++  => before = "; print_raw(a); std::cout << " | now = "; print_raw(a++); std::cout << " | after = "; print_raw(a); std::cout <<\
			 " | Error = " << std::boolalpha << !a.good() << std::endl;
		a.clear();	
		a.setRawBits(-256);
		std::cout << "\tOperator post++  => before = "; print_raw(a); std::cout << " | now = "; print_raw(a++); std::cout << " | after = "; print_raw(a); std::cout <<\
			 " | Error = " << std::boolalpha << !a.good() << std::endl;
		a.clear();	
		a.setRawBits(INT_MIN/2);
		std::cout << "\tOperator post++  => before = "; print_raw(a); std::cout << " | now = "; print_raw(a++); std::cout << " | after = "; print_raw(a); std::cout <<\
			 " | Error = " << std::boolalpha << !a.good() << std::endl;
		a.clear();	
		a.setRawBits(INT_MIN);
		std::cout << "\tOperator post++  => before = "; print_raw(a); std::cout << " | now = "; print_raw(a++); std::cout << " | after = "; print_raw(a); std::cout <<\
			 " | Error = " << std::boolalpha << !a.good() << std::endl;
		a.clear();	
		std::cout << std::endl;
		a.setRawBits(INT_MAX);
		std::cout << "\tOperator --pre  => before = "; print_raw(a); std::cout << " | now = "; print_raw(--a); std::cout << " | after = "; print_raw(a); std::cout <<\
			 " | Error = " << std::boolalpha << !a.good() << std::endl;
		a.clear();	
		a.setRawBits(INT_MAX/2);
		std::cout << "\tOperator --pre  => before = "; print_raw(a); std::cout << " | now = "; print_raw(--a); std::cout << " | after = "; print_raw(a); std::cout <<\
			 " | Error = " << std::boolalpha << !a.good() << std::endl;
		a.clear();	
		a.setRawBits(256);
		std::cout << "\tOperator --pre  => before = "; print_raw(a); std::cout << " | now = "; print_raw(--a); std::cout << " | after = "; print_raw(a); std::cout <<\
			 " | Error = " << std::boolalpha << !a.good() << std::endl;
		a.clear();	
		a.setRawBits(0);
		std::cout << "\tOperator --pre  => before = "; print_raw(a); std::cout << " | now = "; print_raw(--a); std::cout << " | after = "; print_raw(a); std::cout <<\
			 " | Error = " << std::boolalpha << !a.good() << std::endl;
		a.clear();	
		a.setRawBits(-256);
		std::cout << "\tOperator --pre  => before = "; print_raw(a); std::cout << " | now = "; print_raw(--a); std::cout << " | after = "; print_raw(a); std::cout <<\
			 " | Error = " << std::boolalpha << !a.good() << std::endl;
		a.clear();	
		a.setRawBits(INT_MIN/2);
		std::cout << "\tOperator --pre  => before = "; print_raw(a); std::cout << " | now = "; print_raw(--a); std::cout << " | after = "; print_raw(a); std::cout <<\
			 " | Error = " << std::boolalpha << !a.good() << std::endl;
		a.clear();	
		a.setRawBits(INT_MIN);
		std::cout << "\tOperator --pre  => before = "; print_raw(a); std::cout << " | now = "; print_raw(--a); std::cout << " | after = "; print_raw(a); std::cout <<\
			 " | Error = " << std::boolalpha << !a.good() << std::endl;
		a.clear();	
		std::cout << std::endl;
		a.setRawBits(INT_MAX);
		std::cout << "\tOperator post--  => before = "; print_raw(a); std::cout << " | now = "; print_raw(a--); std::cout << " | after = "; print_raw(a); std::cout <<\
			 " | Error = " << std::boolalpha << !a.good() << std::endl;
		a.clear();	
		a.setRawBits(INT_MAX/2);
		std::cout << "\tOperator post--  => before = "; print_raw(a); std::cout << " | now = "; print_raw(a--); std::cout << " | after = "; print_raw(a); std::cout <<\
			 " | Error = " << std::boolalpha << !a.good() << std::endl;
		a.clear();	
		a.setRawBits(256);
		std::cout << "\tOperator post--  => before = "; print_raw(a); std::cout << " | now = "; print_raw(a--); std::cout << " | after = "; print_raw(a); std::cout <<\
			 " | Error = " << std::boolalpha << !a.good() << std::endl;
		a.clear();	
		a.setRawBits(0);
		std::cout << "\tOperator post--  => before = "; print_raw(a); std::cout << " | now = "; print_raw(a--); std::cout << " | after = "; print_raw(a); std::cout <<\
			 " | Error = " << std::boolalpha << !a.good() << std::endl;
		a.clear();	
		a.setRawBits(-256);
		std::cout << "\tOperator post--  => before = "; print_raw(a); std::cout << " | now = "; print_raw(a--); std::cout << " | after = "; print_raw(a); std::cout <<\
			 " | Error = " << std::boolalpha << !a.good() << std::endl;
		a.clear();	
		a.setRawBits(INT_MIN/2);
		std::cout << "\tOperator post--  => before = "; print_raw(a); std::cout << " | now = "; print_raw(a--); std::cout << " | after = "; print_raw(a); std::cout <<\
			 " | Error = " << std::boolalpha << !a.good() << std::endl;
		a.clear();	
		a.setRawBits(INT_MIN);
		std::cout << "\tOperator post--  => before = "; print_raw(a); std::cout << " | now = "; print_raw(a--); std::cout << " | after = "; print_raw(a); std::cout <<\
			 " | Error = " << std::boolalpha << !a.good() << std::endl;
		std::cout << std::endl;
	}

	main_print_banner("Test aritmetic");
	{
		Fixed a;
		Fixed b;
		a.setRawBits(INT_MAX);
		b.setRawBits(INT_MAX);
		print_aritmetic_test(a, b , a+b, "+");
		a.setRawBits(INT_MAX/2);
		b.setRawBits(INT_MAX/2);
		print_aritmetic_test(a, b , a+b, "+");
		a.setRawBits(256);
		b.setRawBits(256);
		print_aritmetic_test(a, b , a+b, "+");
		a.setRawBits(0);
		b.setRawBits(0);
		print_aritmetic_test(a, b , a+b, "+");
		a.setRawBits(-256);
		b.setRawBits(-256);
		print_aritmetic_test(a, b , a+b, "+");
		a.setRawBits(INT_MIN/2);
		b.setRawBits(INT_MIN/2);
		print_aritmetic_test(a, b , a+b, "+");
		a.setRawBits(INT_MIN);
		b.setRawBits(INT_MIN);
		print_aritmetic_test(a, b , a+b, "+");
		std::cout << std::endl;
		a.setRawBits(INT_MAX);
		b.setRawBits(INT_MAX);
		print_aritmetic_test(a, b , a-b, "-");
		a.setRawBits(INT_MAX/2);
		b.setRawBits(INT_MAX/2);
		print_aritmetic_test(a, b , a-b, "-");
		a.setRawBits(256);
		b.setRawBits(256);
		print_aritmetic_test(a, b , a-b, "-");
		a.setRawBits(0);
		b.setRawBits(0);
		print_aritmetic_test(a, b , a-b, "-");
		a.setRawBits(-256);
		b.setRawBits(-256);
		print_aritmetic_test(a, b , a-b, "-");
		a.setRawBits(INT_MIN/2);
		b.setRawBits(INT_MIN/2);
		print_aritmetic_test(a, b , a-b, "-");
		a.setRawBits(INT_MIN);
		b.setRawBits(INT_MIN);
		print_aritmetic_test(a, b , a-b, "-");
		std::cout << std::endl;
		a.setRawBits(INT_MAX);
		b.setRawBits(INT_MAX);
		print_aritmetic_test(a, b , a*b, "*");
		a.setRawBits(INT_MAX/2);
		b = 2;
		print_aritmetic_test(a, b , a*b, "*");
		a = 5.1f;
		b = 5.1f;
		print_aritmetic_test(a, b , a*b, "*");
		a.setRawBits(256);
		b.setRawBits(256);
		print_aritmetic_test(a, b , a*b, "*");
		a.setRawBits(0);
		b.setRawBits(0);
		print_aritmetic_test(a, b , a*b, "*");
		a.setRawBits(-256);
		b.setRawBits(-256);
		print_aritmetic_test(a, b , a*b, "*");
		a = -5.1f;
		b = - 5.1f;
		print_aritmetic_test(a, b , a*b, "*");
		a.setRawBits(INT_MIN/2);
		b = 2;
		print_aritmetic_test(a, b , a*b, "*");
		a.setRawBits(INT_MIN);
		b.setRawBits(INT_MIN);
		print_aritmetic_test(a, b , a*b, "*");
		std::cout << std::endl;
		a.setRawBits(INT_MAX);
		b.setRawBits(INT_MAX);
		print_aritmetic_test(a, b , a/b, "/");
		a.setRawBits(INT_MAX/2);
		b = 2;
		print_aritmetic_test(a, b , a/b, "/");
		a = 5.1f;
		b = 5.1f;
		print_aritmetic_test(a, b , a/b, "/");
		a.setRawBits(256);
		b.setRawBits(256);
		print_aritmetic_test(a, b , a/b, "/");
		a.setRawBits(0);
		b.setRawBits(0);
		print_aritmetic_test(a, b , a/b, "/");
		a.setRawBits(-256);
		b.setRawBits(-256);
		print_aritmetic_test(a, b , a/b, "/");
		a = -5.1f;
		b = - 5.1f;
		print_aritmetic_test(a, b , a/b, "/");
		a.setRawBits(INT_MIN/2);
		b = 2;
		print_aritmetic_test(a, b , a/b, "/");
		a.setRawBits(INT_MIN);
		b.setRawBits(INT_MIN);
		print_aritmetic_test(a, b , a/b, "/");
		std::cout << std::endl;
	}
 	main_print_banner("Test comparison");
	{
		Fixed a;
		Fixed b;
		a.setRawBits(INT_MAX);
		b.setRawBits(INT_MAX);
		print_comparison_test(a, b, a < b, "<");
		--a;
		print_comparison_test(a, b, a < b, "<");
		b++;
		print_comparison_test(a, b, a < b, "<");
		a.setRawBits(0);
		b.setRawBits(0);
		print_comparison_test(a, b, a < b, "<");
		a--;
		print_comparison_test(a, b, a < b, "<");
		b++;
		print_comparison_test(a, b, a < b, "<");
		a.setRawBits(INT_MIN);
		b.setRawBits(INT_MIN);
		print_comparison_test(a, b, a < b, "<");
		a--;
		print_comparison_test(a, b, a < b, "<");
		b++;
		print_comparison_test(a, b, a < b, "<");
		std::cout << std::endl;
		a.setRawBits(INT_MAX);
		b.setRawBits(INT_MAX);
		print_comparison_test(a, b, a > b, ">");
		a--;
		print_comparison_test(a, b, a > b, ">");
		b++;
		print_comparison_test(a, b, a > b, ">");
		a.setRawBits(0);
		b.setRawBits(0);
		print_comparison_test(a, b, a > b, ">");
		a--;
		print_comparison_test(a, b, a > b, ">");
		b++;
		print_comparison_test(a, b, a > b, ">");
		a.setRawBits(INT_MIN);
		b.setRawBits(INT_MIN);
		print_comparison_test(a, b, a > b, ">");
		a--;
		print_comparison_test(a, b, a > b, ">");
		b++;
		print_comparison_test(a, b, a > b, ">");
		std::cout << std::endl;
		a.setRawBits(INT_MAX);
		b.setRawBits(INT_MAX);
		print_comparison_test(a, b, a >= b, ">=");
		a--;
		print_comparison_test(a, b, a >= b, ">=");
		b++;
		print_comparison_test(a, b, a >= b, ">=");
		a.setRawBits(0);
		b.setRawBits(0);
		print_comparison_test(a, b, a >= b, ">=");
		a--;
		print_comparison_test(a, b, a >= b, ">=");
		b++;
		print_comparison_test(a, b, a >= b, ">=");
		a.setRawBits(INT_MIN);
		b.setRawBits(INT_MIN);
		print_comparison_test(a, b, a >= b, ">=");
		a--;
		print_comparison_test(a, b, a >= b, ">=");
		b++;
		print_comparison_test(a, b, a >= b, ">=");
		std::cout << std::endl;
		a.setRawBits(INT_MAX);
		b.setRawBits(INT_MAX);
		print_comparison_test(a, b, a <= b, "<=");
		a--;
		print_comparison_test(a, b, a <= b, "<=");
		b++;
		print_comparison_test(a, b, a <= b, "<=");
		a.setRawBits(0);
		b.setRawBits(0);
		print_comparison_test(a, b, a <= b, "<=");
		a--;
		print_comparison_test(a, b, a <= b, "<=");
		b++;
		print_comparison_test(a, b, a <= b, "<=");
		a.setRawBits(INT_MIN);
		b.setRawBits(INT_MIN);
		print_comparison_test(a, b, a <= b, "<=");
		a--;
		print_comparison_test(a, b, a <= b, "<=");
		b++;
		print_comparison_test(a, b, a <= b, "<=");
		std::cout << std::endl;
		a.setRawBits(INT_MAX);
		b.setRawBits(INT_MAX);
		print_comparison_test(a, b, a == b, "==");
		a--;
		print_comparison_test(a, b, a == b, "==");
		b++;
		print_comparison_test(a, b, a == b, "==");
		a.setRawBits(0);
		b.setRawBits(0);
		print_comparison_test(a, b, a == b, "==");
		a--;
		print_comparison_test(a, b, a == b, "==");
		b++;
		print_comparison_test(a, b, a == b, "==");
		a.setRawBits(INT_MIN);
		b.setRawBits(INT_MIN);
		print_comparison_test(a, b, a == b, "==");
		a--;
		print_comparison_test(a, b, a == b, "==");
		b++;
		print_comparison_test(a, b, a == b, "==");
		std::cout << std::endl;
		a.setRawBits(INT_MAX);
		b.setRawBits(INT_MAX);
		print_comparison_test(a, b, a != b, "!=");
		a--;
		print_comparison_test(a, b, a != b, "!=");
		b++;
		print_comparison_test(a, b, a != b, "!=");
		a.setRawBits(0);
		b.setRawBits(0);
		print_comparison_test(a, b, a != b, "!=");
		a--;
		print_comparison_test(a, b, a != b, "!=");
		b++;
		print_comparison_test(a, b, a != b, "!=");
		a.setRawBits(INT_MIN);
		b.setRawBits(INT_MIN);
		print_comparison_test(a, b, a != b, "!=");
		a--;
		print_comparison_test(a, b, a != b, "!=");
		b++;
		print_comparison_test(a, b, a != b, "!=");
		std::cout << std::endl;
	}
 	main_print_banner("Test raw comparison");
	{
		Fixed a;
		Fixed b;
		
		a.setRawBits(INT_MAX);
		b.setRawBits(INT_MAX);
		print_comparison_raw_test(a, b, a < b, "<");
		a--;
		print_comparison_raw_test(a, b, a < b, "<");
		b++;
		print_comparison_raw_test(a, b, a < b, "<");
		a.setRawBits(0);
		b.setRawBits(0);
		print_comparison_raw_test(a, b, a < b, "<");
		a--;
		print_comparison_raw_test(a, b, a < b, "<");
		b++;
		print_comparison_raw_test(a, b, a < b, "<");
		a.setRawBits(INT_MIN);
		b.setRawBits(INT_MIN);
		print_comparison_raw_test(a, b, a < b, "<");
		a--;
		print_comparison_raw_test(a, b, a < b, "<");
		b++;
		print_comparison_raw_test(a, b, a < b, "<");
		std::cout << std::endl;
		a.setRawBits(INT_MAX);
		b.setRawBits(INT_MAX);
		print_comparison_raw_test(a, b, a > b, ">");
		a--;
		print_comparison_raw_test(a, b, a > b, ">");
		b++;
		print_comparison_raw_test(a, b, a > b, ">");
		a.setRawBits(0);
		b.setRawBits(0);
		print_comparison_raw_test(a, b, a > b, ">");
		a--;
		print_comparison_raw_test(a, b, a > b, ">");
		b++;
		print_comparison_raw_test(a, b, a > b, ">");
		a.setRawBits(INT_MIN);
		b.setRawBits(INT_MIN);
		print_comparison_raw_test(a, b, a > b, ">");
		a--;
		print_comparison_raw_test(a, b, a > b, ">");
		b++;
		print_comparison_raw_test(a, b, a > b, ">");
		std::cout << std::endl;
		a.setRawBits(INT_MAX);
		b.setRawBits(INT_MAX);
		print_comparison_raw_test(a, b, a >= b, ">=");
		a--;
		print_comparison_raw_test(a, b, a >= b, ">=");
		b++;
		print_comparison_raw_test(a, b, a >= b, ">=");
		a.setRawBits(0);
		b.setRawBits(0);
		print_comparison_raw_test(a, b, a >= b, ">=");
		a--;
		print_comparison_raw_test(a, b, a >= b, ">=");
		b++;
		print_comparison_raw_test(a, b, a >= b, ">=");
		a.setRawBits(INT_MIN);
		b.setRawBits(INT_MIN);
		print_comparison_raw_test(a, b, a >= b, ">=");
		a--;
		print_comparison_raw_test(a, b, a >= b, ">=");
		b++;
		print_comparison_raw_test(a, b, a >= b, ">=");
		std::cout << std::endl;
		a.setRawBits(INT_MAX);
		b.setRawBits(INT_MAX);
		print_comparison_raw_test(a, b, a <= b, "<=");
		a--;
		print_comparison_raw_test(a, b, a <= b, "<=");
		b++;
		print_comparison_raw_test(a, b, a <= b, "<=");
		a.setRawBits(0);
		b.setRawBits(0);
		print_comparison_raw_test(a, b, a <= b, "<=");
		a--;
		print_comparison_raw_test(a, b, a <= b, "<=");
		b++;
		print_comparison_raw_test(a, b, a <= b, "<=");
		a.setRawBits(INT_MIN);
		b.setRawBits(INT_MIN);
		print_comparison_raw_test(a, b, a <= b, "<=");
		a--;
		print_comparison_raw_test(a, b, a <= b, "<=");
		b++;
		print_comparison_raw_test(a, b, a <= b, "<=");
		std::cout << std::endl;
		a.setRawBits(INT_MAX);
		b.setRawBits(INT_MAX);
		print_comparison_raw_test(a, b, a == b, "==");
		a--;
		print_comparison_raw_test(a, b, a == b, "==");
		b++;
		print_comparison_raw_test(a, b, a == b, "==");
		a.setRawBits(0);
		b.setRawBits(0);
		print_comparison_raw_test(a, b, a == b, "==");
		a--;
		print_comparison_raw_test(a, b, a == b, "==");
		b++;
		print_comparison_raw_test(a, b, a == b, "==");
		a.setRawBits(INT_MIN);
		b.setRawBits(INT_MIN);
		print_comparison_raw_test(a, b, a == b, "==");
		a--;
		print_comparison_raw_test(a, b, a == b, "==");
		b++;
		print_comparison_raw_test(a, b, a == b, "==");
		std::cout << std::endl;
		a.setRawBits(INT_MAX);
		b.setRawBits(INT_MAX);
		print_comparison_raw_test(a, b, a != b, "!=");
		a--;
		print_comparison_raw_test(a, b, a != b, "!=");
		b++;
		print_comparison_raw_test(a, b, a != b, "!=");
		a.setRawBits(0);
		b.setRawBits(0);
		print_comparison_raw_test(a, b, a != b, "!=");
		a--;
		print_comparison_raw_test(a, b, a != b, "!=");
		b++;
		print_comparison_raw_test(a, b, a != b, "!=");
		a.setRawBits(INT_MIN);
		b.setRawBits(INT_MIN);
		print_comparison_raw_test(a, b, a != b, "!=");
		a--;
		print_comparison_raw_test(a, b, a != b, "!=");
		b++;
		print_comparison_raw_test(a, b, a != b, "!=");
		std::cout << std::endl;

	}
	main_print_banner("Test min max");
	{
		Fixed a(15.5f);
		Fixed b(15.5f);
		a++;
		b--;
		
		const Fixed ac = a;
		const Fixed bc = b ;

	//	b.setRawBits(b.getRawBits());
		
		std::cout << "\ta = " << a << " | b = " << b << std::endl;
		std::cout << std::endl;
		std::cout << "\tref min => " <<	Fixed::min(a ,b) << std::endl;
		std::cout << "\tref max => " <<	Fixed::max(a ,b) << std::endl;
		std::cout << std::endl;
		std::cout << "\ta = " << ac << " | b = " << bc << std::endl;
		std::cout << std::endl;
		std::cout << "\tconst ref min => " <<	Fixed::min(ac ,bc) << std::endl;
		std::cout << "\tconst ref max => " <<	Fixed::max(ac ,bc) << std::endl;
		std::cout << std::endl;
}







	return 0;
}

void	main_print_banner(std::string title)
{	
	std::cout	<<	std::endl;
	std::cout	<<	std::setfill('*') << std::setw(title.size()) << "" << std::endl;
	std::cout	<<	title	<<	std::endl;
	std::cout	<<	std::setfill('*') << std::setw(title.size()) << "" << std::endl;
	std::cout	<<	std::endl;
}

void	print_raw(Fixed a)
{
	std::cout << std::setfill(' ') << std::setw(15) << a.getRawBits();
}

void	print_aritmetic_test(Fixed a, Fixed b , Fixed c, std::string op)
{
	std::cout << "\ta = " << a << " | b = " << b << " | a " << op << " b = " << c << " | Error = " << std::boolalpha << !c.good() << std::endl;
}

void	print_comparison_test(Fixed &a, Fixed &b , bool res  , std::string op)
{
	std::cout << "\ta = " << a << " | Error a => " << std::boolalpha << !a.good() << " | b = " << b << " | Error b => " << std::boolalpha << !b.good()\
		<< " | a " << op << " b => " << res << std::endl;
	a.clear();	
	b.clear();	
}

void	print_comparison_raw_test(Fixed &a, Fixed &b , bool res  , std::string op)
{
	std::cout << "\ta = "; print_raw(a); std::cout << " | Error a => " << std::boolalpha << !a.good();
	std::cout << " | b = "; print_raw(b); std::cout << " | Error b => " << std::boolalpha << !b.good()\
		<< " | a " << op << " b => " << res << std::endl;
	a.clear();	
	b.clear();	
}
