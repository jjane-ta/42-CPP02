/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjane-ta <jjane-ta@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 18:12:59 by jjane-ta          #+#    #+#             */
/*   Updated: 2023/01/22 20:39:37 by jjane-ta         ###   ########.fr       */
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
	main_print_banner("END TEST");

	main_print_banner("TEST +inf");
	{
		float	nan = std::nanf("1");

 		float	inf_pos = (float) std::numeric_limits<float>::infinity();

		float	max = (float)std::numeric_limits<float>::max();
		float	min = (float)std::numeric_limits<float>::min();
		float	tru_min = std::numeric_limits<float>::denorm_min();

		float	int_max = (float)std::numeric_limits<int>::max();
		float	int_min = (float)std::numeric_limits<int>::min();


		float	zero = 0.0f;

		float	maxFixed = Fixed::max();
		
		Fixed fnan(nan);
		Fixed finf_pos(inf_pos);
		Fixed finf_neg(-inf_pos);
		Fixed fmax(max);
		Fixed fmax_min(-max);
		Fixed fmin(min);
		Fixed ftru_min(tru_min);
		Fixed fintmax(int_max);
		Fixed fintmin(int_min);
		Fixed fzero(zero);
		Fixed fmaxFixed(maxFixed);

		
		std::cout << roundf(maxFixed) << std::endl;


		std::cout << fmaxFixed.getRawBits() << std::endl;



		


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
		std::cout << "\tINT MAX  (float) => " << int_max << " (Fixed) => " << fintmax << std::endl;
		std::cout << "\tINT MIN  (float) => " << int_min << " (Fixed) => " << fintmin << std::endl;
		std::cout << std::endl;
		std::cout << "\tZERO  (float) => " << zero << " (Fixed) => " << fzero << std::endl;
		std::cout << std::endl;
		std::cout << "\tFIXED MAX (float) => " << maxFixed  << " (Fixed) => " << fmaxFixed << std::endl;








	}
	main_print_banner("END TEST 2");
	
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
