#ifndef NULLPOINTEREXCEPTION_H
#define NULLPOINTEREXCEPTION_H

#include <iostream>
#include <string>

	public class NullPointerException
	{
		public:
			NullPointerException(std::string);
			~NullPointerException(void);

			std::ostream& PrintOn(std::ostream&) const;

		private:
			std::string what;
	};

#endif