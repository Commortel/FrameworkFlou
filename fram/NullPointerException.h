#ifndef NULLPOINTEREXCEPTION_H
#define NULLPOINTEREXCEPTION_H

#include <iostream>
#include <sstream>
#include <exception>

class NullPointerException : public std::exception
{
	public:
		NullPointerException( const char * Msg, int Line )
		{
			std::ostringstream oss;
			oss << "Erreur ligne " << Line << " : "
				<< Msg;
			this->msg = oss.str();
		}
 
		virtual ~NullPointerException() throw()
		{
 
		}
 
		virtual const char * what() const throw()
		{
			return this->msg.c_str();
		}
	private:
		std::string msg;
};

int main()
{
    try
    {
        throw NullPointerException( "exception test", __LINE__ );
    }
    catch ( const std::exception & e )
    {
        std::cerr << e.what() << "\n";
    }
}

#endif