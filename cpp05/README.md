# Exceptions handling (try catch throw)

-> Exception handling in C++ is a mechanism that allows you to handle runtime errors or    exceptional situations gracefully, An exception is an unexpected problem that arises during the  execution of a program our program terminates suddenly with some errors/issues. Exception occurs  during the running of the program (runtime).   

**TRY :**  

>The try keyword represents a block of code that may throw an exception placed inside the try block. It’s followed by one or more catch blocks. If an exception occurs, try block throws that exception.

**CATCH :**  

>The catch statement represents a block of code that is executed when a particular exception is thrown from the try block. The code to handle the exception is written inside the catch block.

**THROW :**  

>An exception in C++ can be thrown using the throw keyword. When a program encounters a throw statement, then it immediately terminates the current function and starts finding a matching catch block to handle the thrown exception.

->