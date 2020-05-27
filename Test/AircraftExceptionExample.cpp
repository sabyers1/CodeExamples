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

class AircraftEx_NoRunway : public AircraftException
{
public:
    AircraftEx_NoRunway (const char* errMessage, AircraftError errorType):
        AircraftException(errMessage, errorType){}
};

class AircraftEx_WingOnFire : public AircraftException
{
public:
    AircraftEx_WingOnFire (const char* errMessage, AircraftError errorType):
        AircraftException(errMessage, errorType){}
};

class AircraftEx_WingBroken : public AircraftException
{
public:
    AircraftEx_WingBroken (const char* errMessage, AircraftError errorType):
        AircraftException(errMessage, errorType){}
};

int main() {
  try
  {
    srand(time(nullptr));  // seed random generator
    int choice = rand() % 4;
    switch (choice){
        case 0:
            throw AircraftEx_WingBroken("Wing is broken.",AircraftError::WingsOnFire);
            break;
        case 1:
            throw AircraftEx_WingOnFire("Wings are on fire.",AircraftError::WingsOnFire);
            break;
        case 2:
            throw AircraftEx_NoRunway("Blocked airstripe",AircraftError::NoRunway);
            break;
        case 3:
        default:
            throw AircraftException("crashed", AircraftError::Crashed);
            break;
    }
  } catch (AircraftEx_NoRunway e){
        cout << e.what() << endl;
        cout << "Call ATC to get clear runway." << endl;
  } catch (AircraftEx_WingOnFire e){
        cout << e.what() << endl;
        cout << "Activate fire extinguishers." << endl;
  } catch (AircraftEx_WingBroken e){
        cout << e.what() << endl;
        cout << "Reduce altitude slowly." << endl;
  } catch (AircraftException& e)
  {
    cout << e.what() << endl;
    {
      // We have crashed - throw 
      throw;
    }
  }
  return 0;
}