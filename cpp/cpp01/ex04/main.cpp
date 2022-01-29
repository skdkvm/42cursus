/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonggki <seonggki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 17:28:52 by seonggki          #+#    #+#             */
/*   Updated: 2022/01/29 19:19:17 by seonggki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>

int main(int argc, char **argv)
{
    std::ifstream           fin;
    std::ofstream           fout;
    std::string             str;
    std::string             s1;
    std::string             s2;
    std::string::size_type  i;

    if (argc == 4)
    {
        fin.open(argv[1]);
        if (fin == 0)
        {
            std::cout << "Read Error" << std::endl;
            return (-1);
        }
        fout.open((std::string)argv[1] + ".replace");
        if (fout == 0)
        {
            std::cout << "Open Error" << std::endl;
            return (-1);
        }
        s1 = argv[2];
        s2 = argv[3];
        while (std::getline(fin, str).eof() == 0)//입력스트림 오브젝트,문자열을 저장할 str객체 eof == 0 일떄까지 계속 입력을받고
        {
            i = 0;
            while ((i = str.find(s1, i)) != std::string::npos)//문자열 s1=seonggki가 존재한다면 해당 문자열에서 s1문자열이 시작하는 위치를 반환하고 그렇지 않으면 nPos를 반환 find함수의 리턴값이 nPos와 동일하면 해당문자열에는 s1이 존재하지 않음
            {
                str.replace(i, s1.size(), s2);//찾아야할 문자열의 길이(size())를 replace 함수에 알려주고 찾아낸 문자열을 새로운 문자열인 s2로 교체
                i = i + s2.size();
            }
            fout << str << std::endl;
        }
        i = 0;
        while ((i = str.find(s1, i)) != std::string::npos)
        {
            str.replace(i, s1.size(), s2);
            i = i + s2.size();
        }
        fout << str;
        fin.close();
        fout.close();
    }
    else
        std::cout << "Input Error Filename s1 s2" << std::endl;
    return (0);
}