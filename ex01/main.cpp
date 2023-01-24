/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjane-ta <jjane-ta@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 18:12:59 by jjane-ta          #+#    #+#             */
/*   Updated: 2023/01/24 17:19:52 by jjane-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include "Fixed.hpp"

void	main_print_banner(std::string title);

int main( void )
{
	
	main_print_banner("TEST subject");
	{
		Fixed a;
		Fixed const b( 10 );
		Fixed const c( 42.42f );
		Fixed const d( b );

		a = Fixed( 1234.4321f );

		std::cout << std::endl;
		std::cout << "\ta is " << a << std::endl;
		std::cout << "\tb is " << b << std::endl;
		std::cout << "\tc is " << c << std::endl;
		std::cout << "\td is " << d << std::endl;
		std::cout << std::endl;
		std::cout << "\ta is " << a.toInt() << " as integer" << std::endl;
		std::cout << "\tb is " << b.toInt() << " as integer" << std::endl; 
		std::cout << "\tc is " << c.toInt() << " as integer" << std::endl;
		std::cout << "\td is " << d.toInt() << " as integer" << std::endl;
		std::cout << std::endl;

	}
	main_print_banner("TEST basics");
	{
		Fixed a(100);
		Fixed b(-100);
		Fixed a2(100.100f);
		Fixed b2(-100.100f);

		std::cout << std::endl;
		std::cout << "\t+-100 int " << a << " " << b << std::endl; 
		std::cout << "\t+-100.0 float  " << a2 << " " << b2 << std::endl;
 		std::cout << "\t+-100 int toInt " << a << " " << b << std::endl; 
		std::cout << "\t+-100.0 float toInt " << a2 << " " << b2 << std::endl;
		std::cout << std::endl;
		if (!a.good() || !a2.good() || !b.good() || !b2.good())
		{
			std::cout << "\tError on basic test!!\n"; 
			std::cout << std::endl;
		}
	}

	std::cout << std::fixed;	

	main_print_banner("TEST Fixed limits");
	{	
		Fixed maxf_i(Fixed::max());
		Fixed minf_i(Fixed::min());
		Fixed maxf_f(Fixed::max());
		Fixed minf_f(Fixed::min());
		Fixed maxf_fPlus(Fixed::max() + 0.26f);
		Fixed minf_fPlus(Fixed::min() - 0.51f);


		std::cout << std::endl;
		std::cout << "\tMax Fixed value => " << Fixed::max() << std::endl;
		std::cout << "\tMin Fixed value => " << Fixed::min() << std::endl;
		std::cout << std::endl;
		std::cout << "\tFixed int maxf " << maxf_i\
			 	<< " ERROR : " << std::boolalpha << !maxf_i.good() << std::endl; 
		std::cout << "\tFixed int minf " << minf_i \
				<< " ERROR : " << std::boolalpha << !minf_i.good() << std::endl;
 		std::cout << "\tFixed float maxf " << maxf_f \
				<< " ERROR : " << std::boolalpha << !maxf_f.good() << std::endl; 
		std::cout << "\tFixed float minf " << minf_i\
				<< " ERROR : " << std::boolalpha << !minf_f.good() << std::endl;
		std::cout << std::endl;
		std::cout << "\tFixed float maxf + 0.26 float => " << Fixed::max() + 0.26f\
				<< " fixed => " << maxf_fPlus\
				<< " ERROR : " << std::boolalpha << !maxf_fPlus.good() << std::endl; 
		std::cout << "\tFixed float minf - 0.51 float =>  " << Fixed::min() - 0.51f\
				<< " fixed => " << minf_fPlus\
				<< " ERROR : " << std::boolalpha << !minf_fPlus.good() << std::endl;
		std::cout << std::endl;



	}
	main_print_banner("TEST float limits");
	{
		float	nan = std::nanf("1");
 		float	inf_pos = (float) std::numeric_limits<float>::infinity();
		float	max = (float)std::numeric_limits<float>::max();
		float	min = (float)std::numeric_limits<float>::min();
		float	tru_min = std::numeric_limits<float>::denorm_min();
	
		Fixed fnan(nan);
		Fixed finf_pos(inf_pos);
		Fixed finf_neg(-inf_pos);
		Fixed fmax(max);
		Fixed fmax_min(-max);
		Fixed fmin(min);
		Fixed ftru_min(tru_min);
	
		std::cout << std::endl;
		std::cout << "\tNAN  (float) => " << nan << " (Fixed) => " << fnan \
				 << " ERROR : " << std::boolalpha << !fnan.good() << std::endl;
		std::cout << std::endl;
		std::cout << "\tINF+ (float) =>  " << inf_pos << " (Fixed) => " << finf_pos\
				 << " ERROR : " << std::boolalpha << !finf_pos.good() << std::endl;
		std::cout << "\tINF- (float) => " << -inf_pos << " (Fixed) => " << finf_neg\
				<< " ERROR : " << std::boolalpha << !finf_neg.good()  << std::endl;
		std::cout << std::endl;
		std::cout << "\tMAX      (float) => " << max << " (Fixed) => " << fmax\
				 << " ERROR : " << std::boolalpha << !fmax.good() << std::endl;
		std::cout << "\tMAX MIN  (float) => " << -max << " (Fixed) => " << fmax_min\
				 << " ERROR : " << std::boolalpha << !fmax_min.good() << std::endl;
		std::cout << std::endl;
		std::cout << "\tMIN       (float) => " << min << " (Fixed) => " << fmin\
				 << " ERROR : " << std::boolalpha << !fmin.good() << std::endl;
		std::cout << "\tTRUE MIN  (float) => " << tru_min << " (Fixed) => " << ftru_min\
				 << " ERROR : " << std::boolalpha << !ftru_min.good() << std::endl;
		std::cout << std::endl;
	}
	main_print_banner("TEST int limits");
	{
		float	int_max = (float)std::numeric_limits<int>::max();
		float	int_min = (float)std::numeric_limits<int>::min();

		Fixed fintmax(int_max);
		Fixed fintmin(int_min);

		std::cout << std::endl;
		std::cout << "\tINT MAX rawbits => " << fintmax.getRawBits() << std::endl;

		std::cout << "\tINT MAX  (float) => " << int_max << " (Fixed) => " << fintmax\
				 << " ERROR : " << std::boolalpha << !fintmax.good() << std::endl;
		std::cout << "\tINT MIN  (float) => " << int_min << " (Fixed) => " << fintmin\
				 << " ERROR : " << std::boolalpha << !fintmin.good() << std::endl;
		std::cout << std::endl;
	}
	main_print_banner("TEST Fixed(Fixed(max/min_fixed).toFloat)");
	{	
		Fixed max(Fixed((float)Fixed::max()).toFloat());
		Fixed min(Fixed((float)Fixed::min()).toFloat());

		std::cout << std::endl;	
		std::cout << "\tMAX => " << max\
				 << " ERROR : " << std::boolalpha << !max.good() << std::endl;
		std::cout << "\tMIN => " << min\
				 << " ERROR : " << std::boolalpha << !min.good() << std::endl;	
		std::cout << std::endl;
	}
	main_print_banner("TEST error inheritance when copy");
	{	
		Fixed a_i(INT_MAX);
		Fixed b_i = a_i;
		Fixed a_f((float)(INT_MAX));
		Fixed b_f = a_f;

		std::cout << std::endl;	
		std::cout << "\tFixed(int) a_i overload => " <<  a_i\
				<< " ERROR : " << std::boolalpha << !a_i.good() << std::endl;
		std::cout << "\tFixed b_i = a_i |   b_i => " << b_i\
				<< " ERROR : " << std::boolalpha << !b_i.good() << std::endl;
		std::cout << std::endl;	
		std::cout << "\tFixed(float) a_f overload => " << a_f\
				<< " ERROR : " << std::boolalpha << !a_f.good() << std::endl;
		std::cout << "\tFixed b_f = a_f |     b_f => " << b_f\
				<< " ERROR : " << std::boolalpha << !b_f.good() << std::endl;
		std::cout << std::endl;
		b_i.clear();
		std::cout << "\tAfter clear error b_i | ERROR a_i : " << std::boolalpha << !a_i.good()\
				<< " ERROR b_i : " << std::boolalpha << !b_i.good() << std::endl;
		b_f.clear();
		std::cout << "\tAfter clear error b_f | ERROR a_f : " << std::boolalpha << !a_f.good()\
				<< " ERROR b_i : " << std::boolalpha << !b_f.good() << std::endl;
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
