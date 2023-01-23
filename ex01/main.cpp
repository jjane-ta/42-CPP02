/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjane-ta <jjane-ta@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 18:12:59 by jjane-ta          #+#    #+#             */
/*   Updated: 2023/01/23 20:30:55 by jjane-ta         ###   ########.fr       */
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

		std::cout << "a is " << a << std::endl;
		std::cout << "b is " << b << std::endl;
		std::cout << "c is " << c << std::endl;
		std::cout << "d is " << d << std::endl;

		std::cout << "a is " << a.toInt() << " as integer" << std::endl;
		std::cout << "b is " << b.toInt() << " as integer" << std::endl; 
		std::cout << "c is " << c.toInt() << " as integer" << std::endl;
		std::cout << "d is " << d.toInt() << " as integer" << std::endl;
		

	}
	std::cout << std::fixed;	
	main_print_banner("TEST Fixed limits");
	{	
		std::cout << std::endl;
		std::cout << "Max Fixed value => " << Fixed::max() << std::endl;
		std::cout << "Min Fixed value => " << Fixed::min() << std::endl;
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
		std::cout << "\tNAN  (float) => " << nan << " (Fixed) => " << fnan << std::endl;
		std::cout << std::endl;
		std::cout << "\tINF+ (float) =>  " << inf_pos << " (Fixed) => " << finf_pos << std::endl;
		std::cout << "\tINF- (float) => " << -inf_pos << " (Fixed) => " << finf_neg << std::endl;
		std::cout << std::endl;
		std::cout << "\tMAX      (float) => " << max << " (Fixed) => " << fmax << std::endl;
		std::cout << "\tMAX MIN  (float) => " << -max << " (Fixed) => " << fmax_min << std::endl;
		std::cout << std::endl;
		std::cout << "\tMIN       (float) => " << min << " (Fixed) => " << fmin << std::endl;
		std::cout << "\tTRUE MIN  (float) => " << tru_min << " (Fixed) => " << ftru_min << std::endl;
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

		std::cout << "\tINT MAX  (float) => " << int_max << " (Fixed) => " << fintmax << std::endl;
		std::cout << "\tINT MIN  (float) => " << int_min << " (Fixed) => " << fintmin << std::endl;
		std::cout << std::endl;
	}

	main_print_banner("TEST Fixed(Fixed(max/min_fixed).toFloat)");
	{	
		Fixed max(Fixed((float)Fixed::max()).toFloat());
		Fixed min(Fixed((float)Fixed::min()).toFloat());

		std::cout << std::endl;	
		std::cout << "MAX => " << max << std::endl;
		std::cout << "MIN => " << min << std::endl;
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
