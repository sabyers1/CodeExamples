// source: https://www.acodersjourney.com/top-15-c-exception-handling-mistakes-avoid/

/* Further, the general rule for exception handling is that you should only catch
 * exceptions that you can handle or plan to transform in a certain way. In the 
 * above example, if we detect WingBroken or Crashed exception, we just re-throw
 * hoping someone up the chain is available to catch and handle the exception. 
 * This catching and re-throwing of exceptions we cannot handle is totally 
 * unnecessary and comes with a performance penalty.
 * The ideal way would have been to take the errors defined in the enum and 
 * translate them into separate exceptions and catch the specific ones we can 
 * handle , while allowing the others to bubble up the call chain.
*/

#include <iostream>
#include <iostream>
#include <exception>
using namespace std;
enum AircraftError
{
  WingsOnFire = 1,
  WingBroken = 2,
  NoRunway = 3,
  Crashed = 4
};
class AircraftException : public exception
{
public:
  AircraftException(const char* errMessage, AircraftError errorType) :m_ErrMessage(errMessage),
                                                            m_ErrorType(errorType){}
  // overriden what() method from exception class
  const char* what() const noexcept{ return m_ErrMessage; }
  AircraftError GetError() { return m_ErrorType; }
private:
  const char* m_ErrMessage;
  AircraftError m_ErrorType;
};
int main() {
  try
  {
    throw AircraftException("crashed", AircraftError::Crashed);
  }
  catch (AircraftException& e)
  {
    cout << e.what() << '\n';
    if (e.GetError() == AircraftError::WingsOnFire)
    {
      // Fire extinguishers
    }
    else if (e.GetError() == AircraftError::WingBroken)
    {
      // Cannot do anything in flight - pray and rethrow
    }
    else if(e.GetError()== AircraftError::NoRunway)
    {
      //Call Air Traffic control to clear up runway
    }
    else
    {
      // We have crashed - throw 
      throw;
    }
  }
  return 0;
}