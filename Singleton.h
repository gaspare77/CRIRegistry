#ifndef _SINGLETON_H
#define _SINGLETON_H

template<class Derived, class ToBeCreated> class Singleton
{
protected:
  static Derived *s_pInstance;

  Singleton()
  {
  }

  ~Singleton()
  {
  }

public:
  static Derived *Instance()
  {
      CreateInstance();
      return s_pInstance;
  }

  
  static void CreateInstance()
  {
    if(!s_pInstance)
      s_pInstance = new ToBeCreated;
  } 

  static void Destroy()
  {
    if(s_pInstance)
    {
      delete s_pInstance;
      s_pInstance = 0;
    }
  }
};

template<class Derived, class ToBeCreated>
Derived *Singleton<Derived, ToBeCreated>::s_pInstance = 0;

#endif


