class MyClass {
   int x = 0;
  

   int myInlineMethod()
   {
        auto str = "hello";
        int y = 5 + x;

         auto obj = new MyClass();
         int z = obj->myInlineMethod();

	      return y;
   }
   

   void myOtherThing(int param);
   
   
};

void MyClass::myOtherThing(int param)
{
   // the otherThing
   int z = 44L;
}


