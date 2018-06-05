class A
{
   public:
   A()
   : data(0)
   {
      cout << "A()" << endl;
   }

   virtual void f() const {
      cout << "A::f" << endl;
      t();
   }

   void m () const {
      cout << "A::m" << endl;
      t();
   }

   protected:
   friend ostream& operator << (ostream& out, A const& );

   virtual void t() const {
      cout << "A::t" << endl;
   }
  int data;
};

class B: public A
{
   public:
   B ()
   {
       cout << "B()" << endl;
   }

   virtual void t() const {
      cout << "B::t" << endl;
   }

   protected:

   virtual void f() const {
      cout << "B::f" << endl;
      t();
   }

};

class C: public A
{
public:
    C()
    {
        cout << "C()" << endl;
    }

private:
   virtual void t() const{
      cout << "C::t" << endl;
    }

    virtual void f() const{
      cout << "C::f" << endl;
      t();
    }

};

ostream& operator << (ostream& out, A const& a)
{
    out << a.data << endl;

    a.f();
    return out;
}

int main()
{
    A a;
    B b;
    C c;

    A* aptr;
    aptr = &b;

    aptr->f();

    aptr = &c;
    aptr->m();

    B* bptr;
    bptr = &b;

    bptr->f();

    A &aRef = c;
    cout << c << endl;

    return 0;
}