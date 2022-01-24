/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonggki <seonggki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 15:40:40 by seonggki          #+#    #+#             */
/*   Updated: 2022/01/24 17:22:57 by seonggki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void)
{
    //스택에 단순 할당
    std::cout << "This is Stack Zombies" << std::endl;
    Zombie  zombie;             // 생성자1 호출
    zombie.announce();
    Zombie  zombie1("Top");     // 생성자2 호출
    zombie1.announce();
    Zombie  zombie2("Mid");     // 생성자2 호출
    zombie2.announce();
    randomChump("randomChump"); // 생성자2 호출

    //동적으로 할당
    std::cout << "This is Heap Zombies" << std::endl;
    Zombie  *heap_zombie;
    heap_zombie = newZombie("Bottom"); // 생성자2 호출
    heap_zombie->announce();           // 포인터를 통한 간접 접근
    delete(heap_zombie);               // heap_zombie를 동적으로 할당했으므로 삭제해야한다.
    return (0);
}