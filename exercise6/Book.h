#ifndef BOOK_H_INCLUDED
#define BOOK_H_INCLUDED

typedef void (*operation) (int);

class Book
{
public:
    Book()
    {
       _objectCounter++;
       _idGenerator++;
       _uid = _idGenerator;
       _numPages = 0;
    }

    int getUuid() const
    {
        return _uid;
    }

    static int getCurrentObjectCount()
    {
        return _objectCounter;
    }

    void setOperation(operation op)
    {
        this->_op = op;
    }

    void executeOperation() const
    {
        _op(_numPages);
    }

    ~Book()
    {
       _objectCounter--;
    }

private:
   static int  _idGenerator;
   static int  _objectCounter;
   int         _uid;
   int         _numPages;
   operation   _op;
};

#endif // BOOK_H_INCLUDED
