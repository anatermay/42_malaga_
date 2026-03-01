/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SedReplace.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 15:16:22 by aternero          #+#    #+#             */
/*   Updated: 2025/12/01 13:43:41 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SEDREPLACER_HPP
# define SEDREPLACER_HPP

// *** LIBRARIES *** //
# include <iostream>
# include <fstream>
# include <string>

// *** CLASS DEFINITION *** //

class SedReplacer
{
	private:
		std::string	fileName;
		std::string	findStr;
		std::string	replaceStr;
		std::string	fileNameReplace;
	public:
		SedReplacer(std::string fileName, std::string findStr, std::string replaceStr);
		~SedReplacer();
		std::string	replacedContentFile();
		void		replaceInFile();
};

// *** FUNCTIONS *** //

/*  ALLOWED FUNCTIONS
	* ERASE() - erase a substring from a string; from library: <string>
		- Prototype = void erase (size_t pos = 0, size_t len = npos);
		- Returns: void
	* FIND() - find a substring in a string; from library: <string>
		- Prototype = size_t find (const string& str, size_t pos = 0) const;
		- Returns: position of the first character of the first match
	* GETLINE() - read a line from a file; from library: <fstream>
		- Prototype = istream& getline (istream& is, string& str);
		- Returns: istream&
	* IFSTREAM() - input file stream; from library: <fstream>
		- Prototype = ifstream (const char* filename, ios_base::openmode mode = ios_base::in);
		- Returns: void
	* INSERT() - insert a substring into a string; from library: <string>
		- Prototype = string& insert (size_t pos, const string& str);
		- Returns: string&
	* OFSTREAM() - output file stream; from library: <fstream>
		- Prototype = ofstream (const char* filename, ios_base::openmode mode = ios_base::out);
		- Returns: void
*/

#endif
