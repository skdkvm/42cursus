/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Karen.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonggki <seonggki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 15:31:21 by seonggki          #+#    #+#             */
/*   Updated: 2022/01/29 16:40:24 by seonggki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KAREN_HPP
# define KAREN_HPP

# include <iostream>
# include <string>

class Karen
{
private:
    void    debug( void );
    void    info( void );
    void    warning( void );
    void    error( void );
public:
    Karen();
    ~Karen();
    void    complain( std::string level);
};

typedef void    (Karen::*func)(void);

#endif